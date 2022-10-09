#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD1 = 1'000'000'007;
const int BASE = 447;

int n, q;
string s;

int p1[200005], p2[200005];
int h1[200005], h2[200005];

inline pair<int, int> get_hash(int l, int r) {
	int v1 = h1[r] - h1[l] * 1ll * p1[r-l] % MOD1;
	int v2 = h2[r] - h2[l] * p2[r-l];
	if (v1 < 0) v1 += MOD1;
	return {v1, v2};
}

inline int lcp(int x, int y) {
	int lo = 1, hi = min(n-x, n-y), o = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (get_hash(x, x+mid) == get_hash(y, y+mid)) {
			o = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return o;
}

inline bool cmp(int x, int y) {
	int z = lcp(x, y);
	return s[x+z] < s[y+z];
}

inline ll resi_niz(const basic_string<int>& a) {
	ll sol = 0, prod = 0;
	vector<pair<int, int>> stek;

	for (int x : a) {
		int len = 1;
		while (stek.size() && x < stek.back().first) {
			prod -= stek.back().first * 1ll * stek.back().second;
			len += stek.back().second;
			stek.pop_back();
		}
		stek.push_back({x, len});
		prod += x * 1ll * len;
		sol += prod;
	}

	return sol;
}

basic_string<int> konvertuj(basic_string<int> a) {
	sort(a.begin(), a.end(), cmp);
	basic_string<int> b;
	for (int i=0; i<(int)a.size()-1; i++)
		b += lcp(a[i], a[i+1]);
	return b;
}

int a[200005];

/* http://algo2.iti.kit.edu/documents/jacm05-revised.pdf */
/* Maybe I should rewrite this but it works, so who cares */

#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)

inline bool leq(int a1, int a2, int b1, int b2) {
	return a1 < b1 || (a1 == b1 && a2 <= b2);
}

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
	return a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3));
}

// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
inline void radixPass(int* a, int* b, int* r, int n, int K) {
	int* c = new int[K + 1];
	for (int i = 0; i <= K; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++) c[r[a[i]]]++;
	for (int i = 0, sum = 0; i <= K; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (int i = 0; i < n; i++)
		b[c[r[a[i]]]++] = a[i];
	delete [] c;
}

// find the suffix array SA of T[0..n-1] in {1..K}^n
// require T[n]=T[n+1]=T[n+2]=0, n>=2
void suffixArray(int* T, int* SA, int n, int K) {
	int n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2;
	int* R = new int[n02 + 3]; R[n02]= R[n02+1]= R[n02+2]=0;
	int* SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
	int* R0 = new int[n0];
	int* SA0 = new int[n0];

	for (int i=0, j=0; i < n+(n0-n1); i++)
		if (i%3 != 0)
			R[j++] = i;

	radixPass(R , SA12, T+2, n02, K);
	radixPass(SA12, R , T+1, n02, K);
	radixPass(R , SA12, T , n02, K);

	int name = 0, c0 = -1, c1 = -1, c2 = -1;
	for (int i = 0; i < n02; i++) {
		if (T[SA12[i]] != c0 || T[SA12[i]+1] != c1 || T[SA12[i]+2] != c2) {
			name++;
			c0 = T[SA12[i]];
			c1 = T[SA12[i]+1];
			c2 = T[SA12[i]+2];
		}
		if (SA12[i] % 3 == 1)
			R[SA12[i]/3] = name;
		else
			R[SA12[i]/3 + n0] = name;
	}

// recurse if names are not yet unique
	if (name < n02) {
		suffixArray(R, SA12, n02, name);
		for (int i = 0; i < n02; i++) R[SA12[i]] = i + 1;
	} else {
		for (int i = 0; i < n02; i++)
			SA12[R[i] - 1] = i;
	}

	for (int i=0, j=0; i < n02; i++)
		if (SA12[i] < n0)
			R0[j++] = 3*SA12[i];

	radixPass(R0, SA0, T, n0, K);
	
	for (int p=0, t=n0-n1, k=0; k < n; k++) {
		int i = GetI();
		int j = SA0[p];
		if (SA12[t] < n0 ?
			leq(T[i], R[SA12[t] + n0], T[j], R[j/3]) :
			leq(T[i],T[i+1],R[SA12[t]-n0+1], T[j],T[j+1],R[j/3+n0])
		) {
			SA[k] = i;
			t++;
			if (t == n02) {
				for (k++; p < n0; p++, k++)
					SA[k] = SA0[p];
			}
		} else { // suffix from SA0 is smaller
			SA[k] = j;
			p++;
			if (p == n0) {
				for (k++; t < n02; t++, k++) 
					SA[k] = GetI();
			}
		}
	}
	delete [] R;
	delete [] SA12;
	delete [] SA0;
	delete [] R0;
}


int sa[200005];
int inv[200005];

bool cmp2(int x, int y) {
	return inv[x] < inv[y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q >> s;
	s += '.';

	for (int i=0; i<n; i++)
		a[i] = s[i] - 'a' + 1;
	suffixArray(a, sa, n, 28);

	p1[0] = p2[0] = 1;
	for (int i=1; i<=n+1; i++) {
		p1[i] = p1[i-1] * 1ll * BASE % MOD1;
		p2[i] = p2[i-1] * BASE;
	}

	for (int i=0; i<n; i++) {
		h1[i+1] = (h1[i] * 1ll * BASE + s[i]) % MOD1;
		h2[i+1] = (h2[i] * BASE + s[i]);
	}

	for (int i=0; i<n; i++)
		inv[sa[i]] = i;

	while (q--) {
		int x, y;
		cin >> x >> y;
		basic_string<int> u, v;
		while (x--) {
			int a;
			cin >> a;
			u += a-1;
		}
		while (y--) {
			int a;
			cin >> a;
			v += a-1;
		}
		auto uv = u + v;
		sort(u.begin(), u.end(), cmp2);
		sort(v.begin(), v.end(), cmp2);
		merge(u.begin(), u.end(), v.begin(), v.end(), uv.begin(), cmp2);		

		basic_string<int> a, b, ab;

		for (int i=0; i<(int)u.size() - 1; i++)
			a += lcp(u[i], u[i+1]);
		for (int i=0; i<(int)v.size() - 1; i++)
			b += lcp(v[i], v[i+1]);
		for (int i=0; i<(int)uv.size() - 1; i++)
			ab += lcp(uv[i], uv[i+1]);

		ll sol = resi_niz(ab) - resi_niz(a) - resi_niz(b);
		cout << sol << '\n';
	}

}