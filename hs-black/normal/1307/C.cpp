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
char s[N];
ll f[33][33], n;
int cnt[66];
int main() {
	scanf ("%s", s + 1); n = strlen(s + 1);
	for (int i = n;i >= 1; i--) {
		int di = s[i] - 'a';
		for (int j = 0;j < 26; j++) 
			f[di][j] += cnt[j];
		cnt[di]++;
	}
	ll ans = 1;
	for (int i = 0;i < 26; i++) {
		ans = max(ans, (ll)cnt[i]);
		for (int k = 0;k < 26; k++) 
			ans = max(ans, f[i][k]);
	}
	cout << ans << endl;
	return 0;
}