#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,res[500500],a[500500],x,no;
vector<int> v[500500];
queue<int> q;
set<int> s;
void dfs(int x,int fa){
	res[x]=it;it--;
	if(x<n+1){
		if(*s.upper_bound(x)!=fa){no=1;return;}
	}
	s.insert(x);
	for(auto i:v[x]){
		dfs(i,x);
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);no=0;s.clear();
		for(i=1;i<=n+1;i++){
			v[i].clear();
			res[i]=0;
		}
		it=n+1;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=-1){v[a[i]].push_back(i);}
			else{v[i+1].push_back(i);}
		}
		for(i=1;i<=n+1;i++){
			if(v[i].size()>1){sort(v[i].begin(),v[i].end());}
		}
		dfs(n+1,n+2);
		if(no){puts("-1");goto aaa;}
		for(i=1;i<=n;i++){
			printf("%d ",res[i]);
		}
		puts("");
		aaa:;
	}
}