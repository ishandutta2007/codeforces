#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

int n,m;
int a[101][101];
int d[101][101];
int ans[101][10001];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i][0];
		for (int j=1; j<=a[i][0]; j++) cin >> a[i][j];
		int sum=0;
		for (int l=0; l<=a[i][0]; l++) {
			if (l) sum+=a[i][l];
			int csum=sum;
			for (int r=0; l+r<=a[i][0]; r++) {
				if (r) csum+=a[i][a[i][0]-r+1];
				d[i+1][l+r]=max(d[i+1][l+r],csum);
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<=m; j++) {
			for (int k=0; k<=a[i][0] && j+k<=m; k++) {
				ans[i+1][j+k]=max(ans[i+1][j+k],ans[i][j]+d[i+1][k]);
			}
		}
	}
	cout << ans[n][m];
	return 0;
}