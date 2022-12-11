#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 250000;
int d[N], n;
inline int low(int x) {
	return x & -x;
}
void add(int x,int k) {
	for (;x <= n; x += low(x)) d[x] += k;
}
int ask(int x) {
	int val = 0;
	for (; x ; x -= low(x)) val += d[x];
	return val;
}
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
int a[N];
struct Ans{
	int x, pos;
	bool operator < (const Ans &i) const{
		return x < i.x;
	}
}s[N];
#include<algorithm>
int main() {
	n = read();
	for (int i = 1;i <= n; i++) {
		a[i] = s[i].x = read();
		s[i].pos = i;
		a[i] = min(a[i], i);
	}
	sort(s + 1, s + n + 1);
	int x = 0;
	long long ans = 0;
	for (int i = 1;i <= n; i++) {
		if (s[i].x > n) s[i].x = n;
		for (int j = x + 1;j <= s[i].x; j++)
			add(a[j], 1);
		x = s[i].x;
		ans += x - ask(s[i].pos - 1);
		if (s[i].x >= s[i].pos) ans--;
	}
	cout << ans << endl;
	return 0;
}