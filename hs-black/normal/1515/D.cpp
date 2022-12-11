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

const int N = 200050;
int T, n, x, s[N], l, r;
int main() {
	for (read(T); T; --T) {
		read(n), read(l), read(r); multiset<int> s1, s2;
		for (int i = 1;i <= n; ++i) read(s[i]);
		if (l < r) swap(l, r), reverse(s + 1, s + n + 1);
		for (int i = 1;i <= l; ++i) s1.insert(s[i]);
		for (int i = l + 1;i <= n; ++i) s2.insert(s[i]);
		for (int i = 1;i <= l; ++i) 
			if (s2.find(s[i]) != s2.end()) s2.erase(s2.find(s[i])), s1.erase(s1.find(s[i]));
		int t = (s1.size() - s2.size()) / 2;
		int ans = s1.size();
		while (t && s1.size()) {
			auto it = *s1.begin();
			s1.erase(s1.find(it));
			if (s1.find(it) != s1.end()) --ans, --t, s1.erase(s1.find(it));
		}
		write(ans);
	}
	return 0;
}