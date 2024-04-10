#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[200505],cnt;
vector<int> v[200505];
int l,r,md,res;

void dfs(int x,int fa){
	for(auto i:v[x]){
		dfs(i,x);
		f[x]=max(f[x],f[i]+1);
	}
	if(x!=1&&fa!=1&&f[x]==(md-1)){
		cnt++;f[x]=-1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		assert(n<=200000);
		
		for(i=2;i<=n;i++){
			cin>>j;
			v[j].push_back(i);
		}
		
		l=1;r=n;res=n-1;
		
		while(l<=r){
			md=(l+r)/2;
			memset(f,0,n*sizeof(int)+50);
			cnt=0;
			dfs(1,0);
			if(cnt>m){
				l=md+1;
			}
			else{
				r=md-1;res=min(res,md);
			}
		}
		cout<<res<<'\n';
		
		for(i=1;i<=n;i++)v[i].clear();
	}
}