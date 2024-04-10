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
inline void write(F x, char ed = '\n')
{
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

const int N = 505;
int T, n, w[N];
int main() {
	for (read(T); T; T--) {
		read(n); int ans = 0;
		memset(w, 0, sizeof(w));
		for (int i = 1, t;i <= n; i++)	
			read(t), w[t]++;
		for (int i = 1;i <= 2 * n; i++) {
			int tmp = 0;
			for (int k = 1;2 * k <= i; k++) {
				if (k + k == i) tmp += w[k] / 2;
				else tmp += min(w[i-k], w[k]);
			}
			Mx(ans, tmp);
		}
		write(ans);
	}
	return 0;
}

/*

1
8
1 2 2 1 2 1 1 2


*/