
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


const int P = 998244353;
const int N = 1005;
int f[N][N], a[N], mx, n, k;
inline int add(int x, int y) {
	x += y; return x >= P ? x - P : x;
}

int work(int lim) {
//	memset(f, 0, sizeof(f));
//	for (int i = 1;i <= n; i++) f[1][i] = 1;
	for (int j = 2;j <= k; j++) {
		int l = j - 1, sum = 0, *A = f[j-1], *B = f[j];
		for (int i = j;i <= n; i++) {
			while (a[i] - a[l] >= lim) sum = add(sum, A[l]), l++;
			B[i] = sum;
		}
	}
	int sum = 0;
	for (int i = k;i <= n; i++) sum = add(sum, f[k][i]);
	return sum;
}

int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(k);
	for (int i = 1;i <= n; i++) 
		read(a[i]), Mx(mx, a[i]);
	sort(a + 1, a + n + 1), mx /= (k - 1); 
	ll ans = 0;
	for (int i = 1;i <= n; i++) f[1][i] = 1;
	for (int i = 1;i <= mx; i++) ans = add(ans, work(i));
	write(ans);
	return 0;
}

/*



*/