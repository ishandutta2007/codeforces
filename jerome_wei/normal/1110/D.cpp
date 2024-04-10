#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6+20;
typedef long long ll;
const int INF=0x3f3f3f3f;
ll a[N],cnt[N];
ll f[N][3][3];
int main()
{
	ll ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];cnt[a[i]]++;}
	for(int i=0;i<=2;i++)for(int j=0;j<=2;j++)if(i||j)f[2][i][j]=-INF;
	f[2][0][0]=0;
	for(int i=3;i<=m+3;i++){
		for(int x=0;x<3;x++)for(int y=0;y<3;y++)f[i][x][y]=-INF;
		for(int l=0;l<=2;l++){
			for(int r=0;r<=2;r++){
				for(int d=0;d<=2;d++)if(d<=cnt[i]&&r+d<=cnt[i-1]&&r+d+l<=cnt[i-2]){
					int tmp=(cnt[i-2]-r-d-l)/3;
					f[i][r][d]=max(f[i][r][d],f[i-1][l][r]+d+tmp);
				}
			}
		}
	}
	for(int x=0;x<3;x++)for(int y=0;y<3;y++){
		ans=max(ans,f[m+3][x][y]);
	}cout<<ans<<endl;
}