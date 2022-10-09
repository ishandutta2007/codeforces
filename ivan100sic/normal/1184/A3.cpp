#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int T = 7;
int prosti[] = {114689, 163841, 147457, 188417, 151553, 270337, 286721};
int proots[] = {     3,      3,     10,      3,      3,     10,     11};
int pows[7][300000];

void fft_trivial(vector<int>& a, int id) {
	int n = a.size();
	int mod = prosti[id];
	int step = (mod-1)/n;

	vector<int> b(n);

	for (int i=0; i<n; i++) {
		// n je malo, nema overflow
		for (int k=0, w=0; k<n; k++, w=(w+i*step)%(mod-1)) {
			b[i] += a[k]*1ll*pows[id][w]%mod;
			if (b[i] >= mod) b[i] -= mod;
		}
	}

	swap(a, b);
}

void fft(vector<int>& a, int id) {
	int n = a.size();
	if (n & 1) {
		fft_trivial(a, id);
		return;
	}

	int mod = prosti[id];
	int step = (mod-1)/n;

	int h = n >> 1;
	vector<int> b(h), c(h);
	for (int i=0; i<h; i++) {
		b[i] = a[2*i];
		c[i] = a[2*i+1];
	}

	fft(b, id);
	fft(c, id);

	for (int i=0, w=0; i<h; i++, w+=step) {
		int bb = b[i];
		int cc = c[i]*1ll*pows[id][w]%mod;
		int u = bb + cc;
		int v = bb - cc;
		if (u >= mod) u -= mod;
		if (v < 0) v += mod;
		a[i] = u;
		a[i+h] = v;
	}
}

void init() {
	for (int i=0; i<T; i++) {
		int p = 1, q = proots[i];
		for (int j=0; j<300000; j++) {
			pows[i][j] = p;
			p = p*1ll*q%prosti[i];
		}
	}
}

int hsh(string s, int mod, int b) {
	int z = 0;
	for (int i=0,p=1; i<(int)s.size(); i++,p=p*1ll*b%mod)
		z = (z+s[i]*1ll*p)%mod;
	return z;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	init();
	int n, m;
	string a, b;
	cin >> n >> m >> a >> b;

	for (int i=0; i<T; i++) {
		int mod = prosti[i];
		vector<int> va(mod-1, 0), vb(mod-1, 0);
		for (int j=0; j<n; j++) {
			va[j] = a[j];
			vb[j] = b[j];
		}
		fft(va, i);
		fft(vb, i);
		for (int r=0; r<mod-1; r++) {
			int y = pows[i][r];
			if (va[r] == vb[r] && y > 1 && y < mod-1) {
				cout << mod << ' ' << y << '\n';
				// cerr << hsh(a, mod, y) << '\n';
				// cerr << hsh(b, mod, y) << '\n';
				// cerr << va[r] << '\n';
				// cerr << vb[r] << '\n';
				return 0;
			}
		}
	}	
	cout << "Failed\n";
	return 1;
}