
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

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

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

ll mi[500], n, q;
ll mp[200][200];
int main() {
	cin >> n; mi[0] = 1;
	for (int i = 1;i <= 51; i++) mi[i] = mi[i-1] * 2;
	for (int i = 1;i < 2 * n - 2; i++) {
		for (int x = 1; x <= n; x++) {
			int y = 2 + i - x;
			if (y < 1 || y > n) continue;
			if (x & 1) mp[x][y] = mi[i - 1];
		}
	}
	for (int i = 1;i <= n; i++) {
		for (int j = 1;j <= n; j++)
			cout << mp[i][j] <<  ' ';
		cout << endl;
	}
	fflush(stdout);
	cin >> q;
	while (q--) {
		ll k; read(k);
		cout << 1 << ' ' << 1 << endl;
		int px = 1, py = 1;
		for (int i = 1;i < 2 * n - 2; i++) {
			if (k & 1) {
				if (px & 1) py++;
				else px++;
			}
			else {
				if (px & 1) px++;
				else py++;
			}
			cout << px << ' '<< py << endl;
			k >>= 1;
		}
		cout << n << ' ' << n << endl;
		fflush(stdout);
	}
	return 0;
}

/*


*/