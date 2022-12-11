#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

#define ull unsigned ll
#define se second
#define fi first
const int bas = 1333331, P = 998244353;
const int N = 200050;
map<pair<ull, int>, int> mp[N];
char s[N];
int id[N], siz[222], ch[N][26], cnt, n;
vector<pair<ull, int> > qry[N];
struct cont {
	vector<int> a; vector<pair<ull, int> > hs;
	int len; pair<ull, int> has;
	void readin(void) {
		scanf ("%s", s + 1), len = strlen(s + 1), a.resize(len + 1);
		for (int i = 1;i <= len; ++i) a[i] = s[i] - 'a', ++siz[a[i]];
		hs.resize(len + 2);
		for (int i = len;i >= 1; --i)
			hs[i].se = (1ll * hs[i + 1].se * bas + a[i] + 'a') % P, hs[i].fi = (hs[i + 1].fi * bas + a[i] + 'a');
		//for (int i = 1;i <= len; ++i)
			//printf ("hs[%d] = %d\n", i, hs[i]);

		for (int i = 0;i < 26; ++i) {
			has.se = (1ll * has.se * bas + (siz[i] ^ (i * 1919 + 810))) % P;
			has.fi = (has.fi * bas + (siz[i] + 333) * i), siz[i] = 0;
		}
		//printf ("has = %d\n", has);
	}
	void insert(void) {
		int p = 0;
		for (int i = 1;i <= len; ++i) {
			mp[p][hs[i]]++;
			if (!ch[p][a[i]]) ch[p][a[i]] = ++cnt;
			p = ch[p][a[i]];
		}
		mp[p][hs[len + 1]]++;
	}
	void calc(void) {
		int p = 0;
		for (int l = 1, r;l <= len; ) {
			r = l;
			while (r < len && a[r + 1] >= a[r]) ++r;
			//write(p, ' '), write(hs[r + 1]);
			qry[p].emplace_back(hs[r + 1]);
			while (l <= r) p = ch[p][a[l]], ++l;
		}
		//printf ("res = %d\n", res);
	}
}A[N];

ll all, ans;
void dfs(int x) {
	for (int i = 0, y;i < 26; ++i) if (ch[x][i]) {
		dfs(y = ch[x][i]);
		if (mp[y].size() > mp[x].size()) swap(mp[x], mp[y]);
		for (auto t: mp[y]) mp[x][t.first] += t.second;
	}
	for (auto t: qry[x]) all += mp[x][t] - 1;
	qry[x].clear();
}

void solve(cont *A, int len) {
	all = 0;
	memset(ch, 0, (cnt + 1) * sizeof(ch[0]));
	for (int i = 0;i <= cnt; ++i) mp[i].clear();
	cnt = 0;
	for (int i = 1;i <= len; ++i) A[i].insert();
	for (int i = 1;i <= len; ++i) A[i].calc();
	dfs(0);
	ans += 1ll * len * (len - 1) - all;
}

int main() {
	read(n);
	for (int i = 1;i <= n; ++i) A[i].readin(), id[i] = i;
	sort(A + 1, A + n + 1, [&](cont A, cont B) { return A.has < B.has; });
	for (int l = 1, r;l <= n; l = r + 1) {
		r = l;
		while (r < n && A[r + 1].has == A[l].has) ++r;
		ans += 1337ll * (r - l + 1) * (l - 1);
		solve(A + l - 1, r - l + 1);
	}
	write(ans);
	return 0;
}