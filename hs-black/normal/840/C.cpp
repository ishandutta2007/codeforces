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

const int N = 500;
ll a[N], cnt, n;
int num[N], siz[N];

ll f[N][N];
ll C[N][N], jie[N];

const int P = 1e9+7;
int main() {
	C[0][0] = jie[0] = 1;
	for (int i = 1;i <= 300; i++) {
		C[i][0] = 1; jie[i] = jie[i-1] * i % P;
		for (int j = 1;j <= i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
	}
	read(n);
	for (int i = 1;i <= n; i++) {
		read(a[i]);
		for (int j = 1;j < i; j++) {
			ll t = sqrt(a[i] * a[j]);
			if (t * t == a[i] * a[j]) {
				siz[num[i] = num[j]]++;
				break;
			}
		}
		if (!num[i]) siz[num[i] = ++cnt] = 1;
	}
	f[0][0] = 1; ll sum = 0;
	for (int i = 1;i <= cnt; i++) {
		for (int j = 0;j <= sum; j++) {
			for (int k = 1;k <= siz[i]; k++) {
				for (int l = 0;l <= j; l++) {
					ll t = j - l + siz[i] - k;
					if (t < 0 || t >= n) continue;
					(f[i][t] += jie[siz[i]] * C[siz[i]-1][k-1] % P
						* C[j][l] % P * C[sum+1-j][k-l] % P * f[i-1][j]) %= P;
				}
			}
		}
		sum += siz[i];
	}
	cout << f[cnt][0] << endl;
	return 0;
}