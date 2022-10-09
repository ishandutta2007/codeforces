/*
	Bacio pogled na editorial, lep zadatak, ne znam kako nisam video
	da kornjaca uvek ide duz ivice...
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[55];
int can[27][1250005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<2*n; i++)
		cin >> a[i];
	sort(a, a+2*n, greater<int>());
	int m = 2*n-2;

	memset(can, 0xff, sizeof can);
	can[0][0] = -2;
	for (int i=0; i<m; i++) {
		for (int j=n-2; j>=0; j--) {
			for (int k=0; k<1250005; k++) {
				if (can[j][k] != -1 && can[j+1][k + a[i]] == -1) {
					can[j+1][k + a[i]] = a[i];
				}
			}
		}
	}
	int sm = accumulate(a, a+m, 0) / 2;
	while (can[n-1][sm] == -1)
		sm--;
	vector<int> svi(a, a+m), uzeti, ostali;
	sort(svi.begin(), svi.end());
	for (int j=n-1; j>0; j--) {
		int x = can[j][sm];
		uzeti.push_back(x);
		sm -= x;
	}
	sort(uzeti.begin(), uzeti.end());
	set_difference(svi.begin(), svi.end(), uzeti.begin(), uzeti.end(),
		back_inserter(ostali));
	reverse(ostali.begin(), ostali.end());
	uzeti.insert(uzeti.begin(), a[2*n-1]);
	ostali.push_back(a[2*n-2]);

	for (int x : uzeti)
		cout << x << ' ';
	cout << '\n';

	for (int x : ostali)
		cout << x << ' ';
	cout << '\n';
}