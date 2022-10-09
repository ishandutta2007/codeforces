#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void gaus(basic_string<int>& b) {
	int l = 0;
	for (int i=29; i>=0; i--) {
		int k = -1;
		for (int j=l; j<(int)b.size(); j++) {
			if (b[j] & (1 << i)) {
				k = j;
				break;
			}
		}
		if (k != -1) {
			swap(b[k], b[l]);
			for (int j=l+1; j<(int)b.size(); j++) {
				if (b[j] & (1 << i)) {
					b[j] ^= b[l];
				}
			}
			l++;
		}
	}
	b.resize(l);
}

bool nez(basic_string<int> u) {
	int a = u.size();
	gaus(u);
	int b = u.size();
	return a == b;
}

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	basic_string<int> g;
	int x = 0;
	for (int i=0; i<n; i++) {
		x ^= a[i];
		g += x;
	}
	gaus(g);
	if (x == 0)
		cout << "-1\n";
	else
		cout << g.size() << '\n';
}