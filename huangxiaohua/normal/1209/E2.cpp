#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define b(x) (1<<((x)-1))

int i,j,k,n,t,m,f[20][5050],g[20][5050];

struct SB{
	int f[13],mx;
	bool operator<(const SB x)const{
		return mx>x.mx;
	}
}s[2050];

int get(int x,int y){
	int res=0,i,j,k,tmp=0;
	for(i=1;i<=n;i++){
		tmp=0;
		for(j=1;j<=n;j++){
			if(!(b(j)&y))continue;
			k=j+i;
			if(k>n)k-=n;
			tmp+=s[x].f[k];
		}
		res=max(res,tmp);
	}
	return res;
}

int dfs(int x,int y){
	if(!x)return 0;
	if(~f[x][y])return f[x][y];
	f[x][y]=g[x][y];
	for(int i=y;i;i=(y&(i-1))){
		f[x][y]=max(f[x][y],dfs(x-1,i)+g[x][y^i]);
	}
	return f[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		memset(s,0,sizeof(s));
		cin>>n>>m;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>s[j].f[i];
				s[j].mx=max(s[j].mx,s[j].f[i]);
			}
		}
		sort(s+1,s+m+1);
		memset(f,-1,sizeof(f));
		memset(g,0,sizeof(g));
		for(i=1;i<=min(n,m);i++){
			for(j=1;j<b(n+1);j++){
				g[i][j]=get(i,j);
			}
		}
		cout<<dfs(min(n,m),b(n+1)-1)<<'\n';
	}
}