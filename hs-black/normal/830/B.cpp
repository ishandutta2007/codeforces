#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100500;
inline int low(int x) {
	return x & -x;
}
int d[N], n;
struct node{
	int x, pos;
	bool operator < (const node &i) const {
		if (x == i.x) return pos < i.pos;
		return x < i.x;
	}
}a[N];
void add(int x,int k) {
	for (; x <= n; x += low(x)) d[x] += k;
}

int ask(int x) {
	int val = 0;
	for (; x; x -= low(x)) val += d[x];
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

int v[N];

int main() {
	n = read();
	for (int i = 1;i <= n; i++) a[i].x = read(), a[i].pos = i;
	sort(a + 1, a + n + 1);
	int tmp = 0, x = 0, p = -1;
	long long ans = 0;
	for (int i = 1;i <= n; i++) {
		while (a[i].x == x) i++;
		if (i > n) break;
		x = a[i].x;
		p = i;
		for (int j = i;j <= n; j++) {
			if (a[j].x != x) break;
			if (a[j].pos > a[tmp].pos) {
				p = j;
				break;
			}
		}
		for (int j = p; ; j++) {
			if (a[p].x != x) p = i;
			if (v[a[p].pos]) break;
			if (a[p].pos < a[tmp].pos) {
				ans += n - a[tmp].pos - (ask(n) - ask(a[tmp].pos));
				ans += a[p].pos - ask(a[p].pos);
				v[a[p].pos] = 1;
				add(a[p].pos, 1);
				tmp = p++;
			}
			else {
				ans += a[p].pos - a[tmp].pos - (ask(a[p].pos) - ask(a[tmp].pos));
				v[a[p].pos] = 1;
				add(a[p].pos, 1);
				tmp = p++;
			}
		}
	}
//	for (int i = 1;i <= n; i++) cout << ask(i) << endl;
	cout << ans << endl;
	return 0;
}