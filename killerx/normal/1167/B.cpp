#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int  x = 0, f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
inline void write(int x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) {putchar('-'); x = -x;}
	int stk[20], tp = 0;
	for (; x; x /= 10) stk[tp ++] = x % 10;
	for (; tp; putchar(stk[-- tp] + '0')) ;
}
map <int, pair <int, int> > mp;
pair <int, int> ask(int i, int j) {
	printf("? %d %d\n", i, j);
	fflush(stdout);
	return mp[read()];
}
int comn(pair <int, int> a, pair <int, int> b) {
	if (a.first == b.first) return a.first;
	if (a.first == b.second) return a.first;
	if (a.second == b.first) return a.second;
	if (a.second == b.second) return a.second;
	return -1;
}
int main() {
	int a[] = {4, 8, 15, 16, 23, 42};
	for (int i = 0; i < 6; ++ i) {
		for (int j = 0; j < i; ++ j) {
			mp[a[i] * a[j]] = make_pair(a[i], a[j]);
		}
	}
	pair <int, int> a1, a2, a3, a4;
	a1 = ask(1, 2);
	a2 = ask(2, 3);
	a3 = ask(4, 5);
	a4 = ask(5, 6);
	int ans[6];
	ans[1] = comn(a1, a2);
	ans[4] = comn(a3, a4);
	ans[0] = a1.first * a1.second / ans[1];
	ans[2] = a2.first * a2.second / ans[1];
	ans[3] = a3.first * a3.second / ans[4];
	ans[5] = a4.first * a4.second / ans[4];
	printf("! %d %d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5]);
	fflush(stdout);
	return 0;
}