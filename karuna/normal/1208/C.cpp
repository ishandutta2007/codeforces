#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int ans[1010][1010];
int main() {
	cin >> n;
	for (int i=0; i<n; i+=4) {
		for (int j=0; j<n; j+=4) {
			for (int k=0; k<4; k++) {
				for (int l=0; l<4; l++)
					ans[i+k][j+l] = n*i+4*j+4*k+l;
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cout << ans[i][j] <<' ';
		cout << '\n';
	}
}