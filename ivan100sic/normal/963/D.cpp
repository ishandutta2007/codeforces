#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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

const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int BASE = 447;

typedef pair<int, int> pii;

int n, m;
int str[100005];
int sa[100005];
pii hs[100005];
pii hq[100005];
pii pw[100005];
int tmp[100005];
string s, q;

pii hes(int l, int r, pii* h) {
	int h0 = h[r].first - h[l].first * 1ll * pw[r-l].first % MOD1;
	int h1 = h[r].second - h[l].second * 1ll * pw[r-l].second % MOD2;
	if (h0 < 0) h0 += MOD1;
	if (h1 < 0) h1 += MOD2;
	return {h0, h1};
}

int lcp(pii* h1, pii* h2, int hi) {
	int l=1, r=hi, o=0;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (hes(0, m, h1) == hes(0, m, h2)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return o;
}

bool cmp(int x, int y) {
	if (y == -1) {
		x = max(x, y);
		int l = lcp(hq, hs+x, min(m, n-x));
		if (l == m)
			return false;
		else
			return q[l] > s[x+l];
	} else {
		x = max(x, y);
		int l = lcp(hq, hs+x, min(m, n-x));
		if (l == m)
			return false;
		else
			return q[l] < s[x+l];
	}
		
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pw[0] = {1, 1};
	for (int i=1; i<100005; i++) {
		pw[i].first = pw[i-1].first * 1ll * BASE % MOD1;
		pw[i].second = pw[i-1].second * 1ll * BASE % MOD2;
	}

	cin >> s;
	n = s.size();
	s += '.';
	for (int i=0; i<n; i++) {
		str[i] = s[i] - 'a' + 1;
		hs[i+1] = {
			(hs[i].first * 1ll * BASE + s[i]) % MOD1,
			(hs[i].second * 1ll * BASE + s[i]) % MOD2
		};
	}
	suffixArray(str, sa, n, 29);
	int qq;
	cin >> qq;
	while (qq--) {
		int k;
		cin >> k >> q;
		k--;
		m = q.size();
		for (int j=0; j<m; j++) {
			hq[j+1] = {
				(hq[j].first * 1ll * BASE + q[j]) % MOD1,
				(hq[j].second * 1ll * BASE + q[j]) % MOD2
			};
		}
		int lo = lower_bound(sa, sa+n, -1, cmp) - sa;
		int hi = upper_bound(sa, sa+n, -1, cmp) - sa;
		int z = hi - lo;
		copy(sa+lo, sa+hi, tmp);
		sort(tmp, tmp+z);

		int sol = 1123123123;
		for (int i=k; i<z; i++) {
			sol = min(sol, tmp[i] - tmp[i-k] + m);
		}
		if (sol == 1123123123)
			sol = -1;
		cout << sol << '\n';
	}
}