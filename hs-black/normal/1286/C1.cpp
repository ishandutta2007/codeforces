#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define MP make_pair
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

void query(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	fflush(stdout);
}

void out(string ans) {
	cout << "! " << ans << endl;
	fflush(stdout);
}

struct node {
	int C[26], siz;
	node (string s = "") {
		memset(C, 0, sizeof(C));
		for (int i = 0;i < s.size(); ++i)
			C[s[i] - 'a']++;
		siz = s.size();
	}
	bool operator < (const node &t) const {
		for (int i = 0;i < 26; ++i) 
			if (C[i] != t.C[i]) return C[i] < t.C[i];
		return 0;
	}
	inline int size(void) const {
		return siz;
	}
}vec[233];

multiset<node> mp;
int cnt, n;
string s;
int main() {
	read(n);
	query(1, n);
	for (int i = 1;i <= n * (n + 1) / 2; ++i)
		cin >> s, mp.insert(node(s));
	if (n == 1) return out(s), 0;
	query(2, n);
	for (int i = 1;i <= n * (n - 1) / 2; ++i)
		cin >> s, mp.erase(mp.find(node(s)));
	for (auto t: mp) vec[++cnt] = t;
	sort(vec + 1, vec + cnt + 1, [&](node a, node b) { return a.size() < b.size(); });
	string ans;
	for (int i = 1;i <= cnt; ++i) {
		int nw = 0;
		for (int j = 0;j < 26; ++j)
			if (vec[i-1].C[j] != vec[i].C[j]) nw = j + 'a';
		ans += (char)nw;
	}
	out(ans);
	return 0;
}