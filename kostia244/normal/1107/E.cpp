#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;

long long n;
string s;
long long a[105], dp[105][105][105] = { { {-1, }, }, };
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long f(long long st, long long e, long long p) {
	if(st == e)
		return 0;
	if(e-st == 1)
		return a[p];
	if(dp[st][e][p] != -1)
		return dp[st][e][p];
	dp[st][e][p] = a[p] + f(st + 1, e, 1);

	for(int i = st + 1; i < e; i++)
		if(s[st] == s[i])
			dp[st][e][p] = max(dp[st][e][p], f(st + 1, i, 1) + f(i, e, p + 1));

	return dp[st][e][p];
}

int main() {
	memset(&dp, -1, sizeof dp);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> s;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cout << f(0, n, 1);
}