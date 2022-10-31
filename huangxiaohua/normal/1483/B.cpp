#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define maxn 300500
int i,j,k,n,m,t,l[100500],a[100500],used[100500];
vector<int> ans;
int u,v,vl;
queue<pair<int,int> >q;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<n;i++){
			l[i]=i+1;
		}
		l[n]=1;vl=0;
		ans.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			used[i]=0;
		}
		for(i=1;i<=n;i++){
			u=i;v=l[i];
			if(__gcd(a[u],a[v])==1){q.push({u,v});}
		}
		while(!q.empty()){
			auto [u,v]=q.front();q.pop();
			if(used[u]||used[v]){continue;}
			vl=l[v];
			ans.push_back(v);used[v]=1;
			
			if(__gcd(a[u],a[vl])==1){q.push({u,vl});}
			l[u]=vl;
		}
		printf("%d ",ans.size());
		for(auto i:ans){
			printf("%d ",i);
		}puts("");
	}
}