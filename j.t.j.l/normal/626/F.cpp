#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 202;
const int MAXK = 1002;
const int MM = 1e9 + 7;
const ll INF = (1LL) << 60;

int a[MAXN];
long long f[2][MAXN][MAXK];

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1,  a + n + 1);
	f[0][0][0] = 1;
	for(int ii = 0; ii < n; ii++){
		int i = ii & 1, p = 1 - i;
		for(int j = 0; j <= ii + 2; j++)
			for(int k = 0; k <= m; k++)
				f[p][j][k] = 0;
		for(int j = 0; j <= ii; j++)
			for(int k = 0; k <= m; k++)
				if (f[i][j][k]){
				//	cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<endl;
					int tmp = k + j * (a[ii + 1] - a[ii]);
					if (tmp <= m){
						f[1-i][j][tmp] = (f[1-i][j][tmp] + (j + 1) * f[i][j][k]) % MM;
						f[1-i][j+1][tmp] = (f[1-i][j+1][tmp] + f[i][j][k]) % MM;
						if (j)
							f[1-i][j-1][tmp] = (f[1-i][j-1][tmp] + j * f[i][j][k]) % MM;
					}
				}
	}
	ll ans = 0;
	//for(int j = 0; j <= n; j++)
	for(int k = 0; k <= m; k++)
		ans += f[n & 1][0][k];
	cout<<ans % MM<<endl;
	return 0;
}