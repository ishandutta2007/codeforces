#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,x[2000005],y[2000005],p[2000005],f[200005];

struct NMSL{
	int n,i,j,k,fa[2000005];
	void init(int n){for(i=1;i<=n;i++)fa[i]=i;}
	int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
	int hb(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return 0;
		fa[x]=y;return 1;
	}
}f1,f0;
//
int main(){
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=m;i++){
			p[i]=i;cin>>x[i]>>y[i];
		}
		while(1){
			aaa:;
			shuffle(p+1,p+m+1,rng);
			f0.init(n);f1.init(n);
			for(j=1;j<=m;j++){
				i=p[j];
				if(f0.hb(x[i],y[i]))f[i]=0;
				else if(f1.hb(x[i],y[i]))f[i]=1;
				else goto aaa;
			}
			break;
		}
		for(i=1;i<=m;i++)cout<<f[i];
		cout<<'\n';
	}
}