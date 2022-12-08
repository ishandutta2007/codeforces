#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k, n, vec;
const int N = 1<<9;
ll a[N][N], b[N][N];
int x[N], y[N];

int main()
{
	cin >> k;n=1<<k;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%lld",&a[i][j]);
	cin >> vec;
	for(int i=0;i<vec;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=vec-1;~i;i--){
		x[i]-=x[0],y[i]-=y[0];
	}
	for(int t=0;t<k;t++){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)b[i][j]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int q=0;q<vec;q++){
					int nxtx=(i+x[q])&(n-1), nxty=(j+y[q])&(n-1);
					b[nxtx][nxty]^=a[i][j];
				}
			}
		}
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=b[i][j];
		for(int i=0;i<vec;i++)x[i]=(x[i]*2)&(n-1),y[i]=(y[i]*2)&(n-1);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j])ans++;
		}
	}
	cout << ans << endl;
}