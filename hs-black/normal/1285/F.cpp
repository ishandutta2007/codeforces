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

const int N = 100500;
const int Maxn = 100000;
vector<int> v[N];
int prime[N], mu[N], e[N], tot;
void prework(void) {
	for (int i = 1;i <= Maxn; i++)
		for (int j = i;j <= Maxn; j += i) 
			v[j].push_back(i);
			
	mu[1] = 1;
	for (int i = 2;i <= Maxn; i++) {
		if (!e[i]) prime[++tot] = e[i] = i, mu[i] = -1; 
		for (int j = 1;j <= tot; j++) {
			int t = i * prime[j];
			if (t > Maxn) break;
			e[t] = prime[j];
			if (e[i] == prime[j]) {
				mu[t] = 0; break;
			}
			mu[t] = -mu[i];
		}
	}
}

ll a[N], ans, res, n;
int st[N], cnt[N], top;

inline int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	prework();
	read(n);
	for (int i = 1;i <= n; i++) {
		int x; read(x); ans = max(ans, (ll)x);
		for (auto j: v[x]) a[j] = 1;
	}
	
	for (int i = Maxn;i >= 1; i--) {
		if (!a[i]) continue;
		int tmp = 0;
		for (auto j: v[i]) tmp += cnt[j] * mu[j], cnt[j]++;
		while (tmp) {
			if (gcd(i, st[top]) == 1) ans = max(ans, (ll)st[top] * i);
			for (auto j: v[st[top]]) {
				cnt[j]--; if (i % j == 0) tmp -= mu[j];
			}
			top--;
		}
		st[++top] = i;
	}
	cout << ans << endl;
	return 0;
}