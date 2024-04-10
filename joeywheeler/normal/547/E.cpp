#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m, q;
int s[200005], e[200005];
char l[400005];
int a[400005];
int ia[400005];

int h[400005], p[400005];
long long BASE = 137;
long long MOD = 1000000009;

int hsh(int i, int j) {
	return (MOD + h[j] - h[i]) * p[400003-i] % MOD;
}

int lcp(int i, int j) {
	int S = 0, E = min(m-i,m-j), b = 0;
	while (S <= E) {
		int M = (S+E)/2;
		if (hsh(i,i+M) == hsh(j,j+M)) b=M, S=M+1;
		else E=M-1;
	}
	return b;
}

vector<int> t[800005];

int cnt(const vector<int> &v, int i, int j) {
	return lower_bound(v.begin(),v.end(),j) - lower_bound(v.begin(),v.end(),i);
}

int qu(int l, int r, int i, int j) {
	int res = 0;
	for (l+=m, r+=m; l < r; l >>= 1, r >>= 1) {
		if (l&1) res += cnt(t[l++], i, j);
		if (r&1) res += cnt(t[--r], i, j);
	}
	return res;
}

int rint() {
	int r = 0; char ch;
	while ((ch=getchar()) < '0');
	do {
		r = r*10+ch-'0';
	} while ((ch=getchar()) >= '0');
	return r;
}

int ps[400005], tp[400005], g;

bool sc(int i, int j) {
	if (ps[i] != ps[j]) return ps[i] < ps[j];
	i += g; j += g;
	return i<m && j<m ? ps[i] < ps[j] : i > j;
}

void sa() {
	FO(i,0,m) a[i] = i, ps[i] = l[i];
	for (g = 1;; g <<= 1) {
		sort(a,a+m,sc);
		FO(i,0,m-1) tp[i+1] = tp[i] + sc(a[i],a[i+1]);
		FO(i,0,m) ps[a[i]] = tp[i];
		if (tp[m-1] == m-1) break;
	}
	FO(i,0,m) ia[a[i]] = i;
}

int main() {
	n = rint(); q = rint();
	FO(i,0,n) {
		s[i] = m;
		while ((l[m++] = getchar()) >= 'a');
		l[e[i]=m-1] = '$';
	}
	//printf("%s\n", l);

	p[0] = 1;
	FO(i,1,400005) p[i] = p[i-1] * BASE % MOD;
	FO(i,0,m) h[i+1] = (h[i] + p[i] * 1ll * l[i]) % MOD;

	sa();

	//FO(i,0,m) printf("%d: %s\n", i, l+a[i]);

	FO(i,0,m) t[m+i].push_back(a[i]);
	for (int i = m-1; i > 0; i--) {
		t[i].resize(sz(t[i<<1])+sz(t[i<<1|1]));
		merge(t[i<<1].begin(), t[i<<1].end(),
				t[i<<1|1].begin(), t[i<<1|1].end(),
				t[i].begin());
	}

	FO(Z,0,q) {
		int x, y, k;
		x = rint()-1; y = rint()-1; k = rint()-1;
		x = s[x]; y = e[y];


		int S = 0, E = ia[s[k]], rl = ia[s[k]], rr = ia[s[k]];
		while (S <= E) {
			int M = (S+E)/2;
			if (a[M]+e[k]-s[k] <= m && hsh(a[M], a[M]+e[k]-s[k]) == hsh(s[k], e[k])) rl = M, E=M-1;
			else S=M+1;
		}

		S = ia[s[k]], E = m-1;
		while (S <= E) {
			int M = (S+E)/2;
			if (a[M]+e[k]-s[k] <= m && hsh(a[M], a[M]+e[k]-s[k]) == hsh(s[k], e[k])) rr = M, S=M+1;
			else E=M-1;
		}

		printf("%d\n", qu(rl, rr+1, x, y));
	}
}