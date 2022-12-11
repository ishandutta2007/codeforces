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

const int N = 1005;
char s[N];


ll n, m, k, cnt;
int Lcp[N][N];

struct node {
	int l, r;
	bool operator < (const node &b) const {
		int lcp = Lcp[l][b.l];
		if (lcp > r - l || lcp > b.r - b.l) return r - l < b.r - b.l;
		return s[l + lcp] < s[b.l + lcp];
	}
	
	
	
}S[N*N];

bool operator == (const node a, const node b) {
	return !(a < b) and !(b < a);
}


inline void add(ll &x, ll y) {
	x += y; if (x > k) x = k;
}

ll dp[N][N], d[N][N];
bool check(int p) {
	memset(dp, 0, sizeof(dp));
	memset(d, 0, sizeof(d));
	dp[n+1][0] = d[n+1][0] = 1;
	int len = S[p].r - S[p].l + 1, L = S[p].l;
	for (int i = n;i >= 1; i--) {
		int t = min(Lcp[L][i], len);
		if (t == len || s[i + t] > s[L + t]) {
			for (int j = 1;j <= m; j++)
				dp[i][j] = d[i + t + 1][j - 1];
		}
		for (int j = 0;j <= m; j++) 
			d[i][j] = d[i+1][j] + dp[i][j], add(d[i][j], 0);
	}
	return dp[1][m] >= k;
}

int main() {
	read(n), read(m), read(k);
	scanf ("%s", s + 1);
	for (int i = n;i >= 1; i--) 
		for (int j = n;j >= 1; j--) 
			Lcp[i][j] = (s[i] == s[j] ? Lcp[i+1][j+1] + 1 : 0);

	for (int i = 1;i <= n; i++) 
		for (int j = i;j <= n; j++) 
			S[++cnt] = (node){i, j};

	sort(S + 1, S + cnt + 1);
	cnt = unique(S + 1, S + cnt + 1) - S - 1;
	int L = 1, R = cnt;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (check(mid)) L = mid + 1;
		else R = mid - 1;
	}
	for (int i = S[L].l;i <= S[L].r; i++) putchar(s[i]);
	putchar('\n');
	return 0;
}
/*
10 5 17
ajhfsdsfdy

*/