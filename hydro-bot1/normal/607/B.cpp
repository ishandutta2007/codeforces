// Hydro submission #63017a2a9a984a1e293eeee1@1661041194388
#include<iostream>
#define maxn 510
using namespace std;
int a[maxn],f[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j] = 1e9;
		}
	}
	for(int l=0;l<n;l++){
		for(int i=1,j=i+l;i<=n-l;i++,j++){
			if (a[i] == a[j])
				f[i][j] = (l < 2) ? 1:min(f[i][j],f[i+1][j-1]);
			for(int k=i;k<j;k++){
				f[i][j] = min (f[i][j],f[i][k] + f[k+1][j]);
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}