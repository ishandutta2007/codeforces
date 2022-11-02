#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int N = 3005, mod = 998244353;

int n, m, dt[N][N], ans;
bool vis[N][N];
char a[N], b[N];

bool match (int I, int J) {
	if(J >= m) return true;
	return a[I] == b[J];
}

int solve (int S, int E) {
	if(vis[S][E]) return dt[S][E];
	vis[S][E] = true;
	if(S == E) {
		dt[S][E] = (match(0, S) ? 2 : 0);
	}
	else {
		if(match(E-S, E)) dt[S][E] += solve(S, E-1);
		if(match(E-S, S)) dt[S][E] += solve(S+1, E);
		dt[S][E] %= mod;
	}
	if(S == 0 && E >= m-1) ans = (ans + dt[S][E]) % mod;
	return dt[S][E];
}

int main()
{
	scanf("%s%s",a,b);
	n = strlen(a);
	m = strlen(b);
	solve(0, n-1);
	printf("%d\n", ans);
}