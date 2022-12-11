#include <queue>
#include <vector>
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

const int N = 200500;
int T, n, k;
char s[N];
int mp[N][28];
int main() {
	read(T);
	while (T--) {
		read(n), read(k); ll ans = n;
		scanf ("%s", s + 1);
		for (int i = 1;i <= k; i++) memset(mp[i], 0, sizeof(mp[i]));
		for (int i = 1;i <= n / k; i++) {
			int l = (i - 1) * k + 1, r = k * i;
			for (int j = l;j <= (l + r + 1) >> 1; j++) {
				mp[j-l+1][s[j]-'a']++;
				if (j * 2 != l + r) mp[j-l+1][s[r-(j-l)]-'a']++; 
			}
		}
		for (int j = 1;j <= (k + 1) / 2; j++) {
			int tmp = 0;
			for (int p = 0;p < 26; p++) 
				tmp = max(tmp, mp[j][p]);
			ans -= tmp;
		}
		printf ("%lld\n", ans);
	}
	return 0;
}
/*
1
21 7
wudixiaoxingxingheclp

*/