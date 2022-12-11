#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 300505;
int a[N], b[N], n;
struct node{
	int a, b;
	bool operator < (const node &i) const{
		if (a == i.a) return b < i.b;
		return a < i.a;
	}
}p[N];

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
const int P = 998244353;
#define ll long long
ll jie[N];
int main() {
//	freopen("hs.in","r",stdin);
	n = read();
	ll ans = 0;
	jie[0] = 1;
	for (int i = 1;i <= n; i++) {
		jie[i] = jie[i-1] * i % P;
//		cout << jie[i] << endl;
	}
	for (int i = 1;i <= n; i++) {
		p[i].a = a[i] = read();
		p[i].b = b[i] = read();
	}
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(p + 1, p + n + 1);
	ll cnt = 1, x = 0, tmp = 1;
	for (int i = 1;i <= n; i++) {
		if (x == a[i]) cnt++;
		else {
			x = a[i];
			tmp *= jie[cnt];
			tmp %= P;
			cnt = 1;
		}
	}
	if (cnt != 1) tmp *= jie[cnt];
	ans += tmp;
	ans %= P;
	x = 0, cnt = tmp = 1;
	for (int j = 1;j <= n; j++) {
		if (x == b[j]) cnt++;
		else {
			x = b[j];
			tmp *= jie[cnt];
			tmp %= P;
			cnt = 1;
		}
	}
	if (cnt != 1) tmp *= jie[cnt];
	tmp %= P;
	ans += tmp;
	ll y = x = 0;
	tmp = cnt = 1;
	for (int i = 1;i <= n; i++) {
		if (p[i].b < y || p[i].a < x) {
			tmp = 0, cnt = 1;
			break;
		}
		if (y == p[i].b && x == p[i].a) cnt++;
		else {
			y = p[i].b, x = p[i].a;
			tmp *= jie[cnt];
			tmp %= P;
			cnt = 1;
		}
	}
	if (cnt != 1) tmp *= jie[cnt];
	tmp %= P;
	ans -= tmp, ans %= P;
	cout << (jie[n] - ans + P) % P << endl;
	return 0;
}
/*
15
1 6
2 4
3 5
14 5
1 5
3 6
7 15
3 4
5 3
1 6
7 5
1 6
15 13
12 14
15 2

*/