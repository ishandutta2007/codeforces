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

int n,m,k,p,ans,otk;
string s;

int a[500][500];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) 
			cin >> a[i][j];
	for (int j=1; j<=n; j++) cin >> a[0][j];

	for (int i=1; i<=n; i++) { // 
		int curans=500;
		for (int j=1; j<=n; j++) { //  
			if (i==j) continue;
			for (int k=1; k<=n; k++) if (a[0][k]<=j && a[0][k]!=i) {
				otk=a[0][k]; break;
			}
			for (int k=1; k<=n; k++) if (a[i][k]==otk) {
				if (k<curans) {
					curans=k;
					ans=otk;
				}
			}
		}
		cout << ans << ' ';
	}
	return 0;
}