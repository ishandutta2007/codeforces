#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
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
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

ll n, m, k;

const int N = 30050;
ll f[N];
char s[N][6];

int main() {
//	freopen ("hs.in","r",stdin);
//	freopen ("hs.out","w",stdout);
	read(n), read(m), read(k);
//	cout << n << ' ' << m << ' ' << k << endl;
	if (k > 4 * n * m - 2 * n - 2 * m) {
		cout << "NO\n";
		return 0;
	}
	ll cnt = 0;
	cout << "YES\n";
	if (m == 1) {
		f[++cnt] = n - 1;
		s[cnt][1] = 'D';
		if (k < n) f[cnt] = k;
		else {
			k -= n - 1;
			f[++cnt] = k;
			s[cnt][1] = 'U';
		}
		k = 0;	
		cout << cnt << endl;
		for (int i = 1;i <= cnt; i++) {
			printf ("%lld %s\n", f[i], s[i] + 1);
		}
		return 0;
	}
	if (n > 1) {
		if (k < n) {
			cout << 1 << endl;
			cout << k << " D" << endl;
			return 0;
		}
		k -= n - 1; cnt = 1;
		f[1] = n - 1, s[1][1] = 'D';
	}
	for (int i = n;i > 1; i--) {
		if (!k) break;
		if (k < m) {
			f[++cnt] = k, s[cnt][1] = 'R'; 
			k = 0;
			break;
		}
		f[++cnt] = m - 1, s[cnt][1] = 'R';
		k -= m - 1;
		cnt++; f[cnt] = m - 1;
		s[cnt][1] = 'U', s[cnt][2] = 'D', s[cnt][3] = 'L';
		if (k <= (m - 1) * 3) {
			f[cnt] = k / 3; k %= 3;
			if (k == 0) break;
			if (f[cnt] == 0) s[cnt][2] = 0, s[cnt][3] = 0, cnt--;
			f[++cnt] = 1;
			if (k >= 1) s[cnt][1] = 'U';
			if (k >= 2) s[cnt][2] = 'D';
			k = 0;
			break;
		}
		k -= (m - 1) * 3;
		f[++cnt] = 1, s[cnt][1] = 'U';
		k--; if (!k) break;
	}
	if (k > 0) {
		f[++cnt] = m - 1; s[cnt][1] = 'R';
		if (k < m) f[cnt] = k;
		else {
			k -= m - 1;
			if (k > 0) {
				f[++cnt] = k;
				s[cnt][1] = 'L';
			}
		}
	}
	cout << cnt << endl;
	for (int i = 1;i <= cnt; i++) {
		printf ("%lld %s\n", f[i], s[i] + 1);
	}
	return 0;
}
/*
30 30 330

*/