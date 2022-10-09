#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 666666667;
string s;
int n;
int p[1000005], h[1000005];

void probaj(int a, int b) {
	if (0 >= a || a >= b || b >= n)
		return;
	int pe = h[a];
	int qu = (h[b] - h[a] * 1ll * p[b-a]) % mod;
	qu += (qu < 0) * mod;
	int er = (h[n] - h[b] * 1ll * p[n-b]) % mod;
	er += (er < 0) * mod;
	pe += qu;
	pe -= (pe >= mod) * mod;
	if (er == pe) {
		cout << s.substr(0, a) << "+" << s.substr(a, b-a) << "=" << s.substr(b) << '\n';
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	p[0] = 1;
	for (int i=0; i<n; i++) {
		p[i+1] = p[i] * 10ll % mod;
		h[i+1] = (h[i] * 10ll + s[i] - '0') % mod;
	}

	for (int b=0; b<=n; b++) {
		for (int j=-2; j<=2; j++) {
			probaj(b+j, n-b);
			probaj(n-2*b+j, n-b);
		}
	}
}