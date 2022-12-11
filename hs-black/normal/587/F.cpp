#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 100500;
vector<char> s[N];
char res[N];
int ch[N][26], en[N], dfn[N];
int f[N], cnt, num, T, m, n;
int ne[N], to[N], h[N], tot;
inline void add_e(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

int add(char *s, int len) {
	int p = 0;
	for (int i = 1;i <= len; i++) {
		int di = s[i] - 'a';
		if (!ch[p][di]) ch[p][di] = ++cnt;
		p = ch[p][di];
	} return p;
}

void build(void) {
	queue<int> q;
	for (int i = 0;i < 26; i++)	
		if (ch[0][i]) q.push(ch[0][i]);
	while (q.size()) {
		int x = q.front(); q.pop();
		add_e(f[x], x);
		for (int i = 0;i < 26; i++)
			if (ch[x][i]) f[ch[x][i]] = ch[f[x]][i], q.push(ch[x][i]);
			else ch[x][i] = ch[f[x]][i];
	}
}
 
int siz[N];
void dfs(int x) {
	dfn[x] = ++num, siz[x] = 1;
	for (int i = h[x]; i; i = ne[i]) 
		dfs(to[i]), siz[x] += siz[to[i]];
}

struct node {
	int k, l, num;
	bool operator < (const node &i) const {
		return l < i.l;
	}
};

vector<node> v[N], q; 

ll ans[N], d[N], val[N];
void Add(int x, int k) {
	for (; x <= num; x += x & -x) d[x] += k;
}

ll Sum(int x) {
	ll res = 0;
	for (; x ; x -= x & -x) res += d[x];
	return res;
}

int main() {
	read(n), read(m); T = 250;
	for (int i = 1;i <= n; i++) {
		scanf ("%s", res + 1); 
		int t = strlen(res + 1); en[i] = add(res, t);
		s[i].push_back('f');
		for (int j = 1;j <= t; j++) s[i].push_back(res[j]);
	}
	build(); dfs(0);
	
	for (int i = 1;i <= m; i++) {
		int l, r, k; read(l), read(r), read(k);
		if ((int)s[k].size() > T) {
			if (l-1) v[k].push_back((node){-1, l-1, i});
			v[k].push_back((node){1, r, i});
		}
		else {
			if (l-1) q.push_back((node){-k, l-1, i});
			q.push_back((node){k, r, i});
		}
	}
	sort(q.begin(), q.end());
	for (int i = 1;i <= n; i++) {
		if (!v[i].size()) continue;
		sort(v[i].begin(), v[i].end());
		memset(val, 0, sizeof(val));
		int p = 0;
		for (int j = 1;j < (int)s[i].size(); j++) {
			p = ch[p][s[i][j]-'a'];
			int x = p;
			while (x) val[x]++, x = f[x];
		}
		ll sum = 0, now = 1;
		for (auto j: v[i]) {
			while (now <= j.l) 
				sum += val[en[now++]];
			ans[j.num] += j.k * sum;
		}
	}
	
	int now = 1;
	for (auto i: q) {
		while (now <= i.l) {
			int x = en[now];
			Add(dfn[x] + siz[x], -1);
			Add(dfn[x], 1); now++; 
		}
		int p = 0, f = i.k > 0 ? 1 : -1;
		if (i.k < 0) i.k = -i.k;
		ll sum = 0;
		for (int j = 1;j < (int)s[i.k].size(); j++) {
			p = ch[p][s[i.k][j]-'a'];
			sum += Sum(dfn[p]);
		}
		ans[i.num] += f * sum;
	}
	
	for (int i = 1;i <= m; i++) printf ("%lld\n", ans[i]); 
	
	return 0;
}