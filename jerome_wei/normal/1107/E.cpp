#include<bits/stdc++.h>
using namespace std;
const int N=110;
typedef long long ll;
int n;
char t[N];
int pre[N];
int c[N];
ll f[N][N];
ll g[2][N][N];
const int INF=0x3f3f3f3f;
void upd(ll &A,ll B){A=max(A,B);}
int main()
{
	scanf("%d",&n);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+t[i]-'0';
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int l=n;l;l--){
		
		for(int i=1;i<=n;i++)g[0][l-1][i]=g[1][l-1][i]=-INF;
		g[0][l-1][0]=g[1][l-1][0]=0;
		
		for(int i=l;i<=n;i++){
			int mx=i-l+1;
			for(int j=0;j<=mx;j++)g[0][i][j]=g[1][i][j]=-INF;
			if(t[i]=='1'){
				for(int j=1;j<=mx;j++) g[1][i][j]=g[1][i-1][j-1];
			}else{
				for(int j=1;j<=mx;j++) g[0][i][j]=g[0][i-1][j-1];
			}
			for(int len=l+1;len<=i;len++)for(int j=0;j<=mx;j++){
				upd(g[0][i][j],g[0][len-1][j]+f[len][i]);
				upd(g[1][i][j],g[1][len-1][j]+f[len][i]);
			}
			ll MX=0;
			for(int j=0;j<=mx;j++){
				// if(l==1)cout<<j<<"::"<<g[0][i][j]<<" "<<g[1][i][j]<<endl;
				MX=max(MX,max(g[0][i][j],g[1][i][j])+(ll)c[j]);
			}
			f[l][i]=(l==i)?(c[1]):MX;
			upd(g[0][i][0],f[l][i]);
			upd(g[1][i][0],f[l][i]);
			// cout<<l<<" "<<i<<" : "<<f[l][i]<<endl;
		}
	}
	cout<<f[1][n]<<endl;
}