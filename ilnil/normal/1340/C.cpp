#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e4+5,M=1005;
int n,m,g,r;
int d[N];
int f[N][M];
queue<P>q[N];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	fo(i,1,m)cin>>d[i];
	cin>>g>>r;
	sort(d+1,d+m+1);
	fo(i,1,m)fo(j,0,g)f[i][j]=1e9;
	f[1][0]=0;
	q[0].push(P(1,0));
	fo(i,0,m){
		for(;!q[i].empty();){
			P x=q[i].front();q[i].pop();
			if(f[x.fi][x.se]!=i)continue;
			if(x.se==g&&i+1<f[x.fi][0]){
				f[x.fi][0]=i+1;
				q[i+1].push(P(x.fi,0));
			}
			int dt=x.se+d[x.fi]-d[x.fi-1];
			if(x.fi>1&&dt<=g&&i<f[x.fi-1][dt]){
				f[x.fi-1][dt]=i;
				q[i].push(P(x.fi-1,dt));
			}
			dt=x.se+d[x.fi+1]-d[x.fi];
			if(x.fi<m&&dt<=g&&i<f[x.fi+1][dt]){
				f[x.fi+1][dt]=i;
				q[i].push(P(x.fi+1,dt));
			}
		}
	}
	ans=1e18;
	fo(i,1,m)
		if(d[m]-d[i]<=g&&f[i][0]<1e9)
			ans=min(ans,(ll)(g+r)*f[i][0]+d[m]-d[i]);
	printf("%lld\n",ans==1e18?-1:ans);
}