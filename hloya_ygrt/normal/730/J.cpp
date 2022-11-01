// In the name of God
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <assert.h>
#include <bitset>
#define sqr(a) (a)*(a)
#define all(a) (a).begin(), (a).end()
using namespace std;

template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if(ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return p * x;
}

string next_token() {
    char ch;
    string ans = "";
    do { ch = getchar(); } while(ch <= ' ');
    while(ch > ' ') {
        ans += ch;
        ch = getchar();
    }
    return ans;
}

const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int MAXN = (int)1e2 + 10;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-8;

long long bin_pow(long long a, long long b) {
	if(!b) return 1;
	long long ans = bin_pow(a, b / 2);
	ans = ans * ans % MOD;
	if(b % 2) ans = ans * a % MOD;
	return ans;
}   

pair<int, int> dp[MAXN][MAXN * MAXN * 2];
                             
int main() {
//	ios::sync_with_stdio(false);

//	freopen(".in", "r", stdin);

	int n; cin >> n;

	vector<int> a(n), b(n);

	for(int i = 0; i < n; i++)
		a[i] = next_int<int>();
	for(int i = 0; i < n; i++) 
		b[i] = next_int<int>();

	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN * MAXN * 2; j++) 
			dp[i][j] = make_pair(INFINT, INFINT);

	dp[0][MAXN * MAXN] = make_pair(0, 0);

	for(int i = 0; i < n; i++) {
		for(int j = - MAXN * MAXN; j < MAXN * MAXN; j++) {
		    if(dp[i][j + MAXN * MAXN] == make_pair(INFINT, INFINT)) continue;

			dp[i + 1][j - (b[i] - a[i]) + MAXN * MAXN] = min(dp[i + 1][j - (b[i] - a[i]) + MAXN * MAXN], make_pair(dp[i][j + MAXN * MAXN].first + 1, dp[i][j + MAXN * MAXN].second + (b[i] - a[i])));
			dp[i + 1][j + a[i] + MAXN * MAXN] = min(dp[i + 1][j + a[i] + MAXN * MAXN], dp[i][j + MAXN * MAXN]);
		}
	}

	pair<int, int> ans = make_pair(INFINT, INFINT);

	for(int i = - MAXN * MAXN; i <= 0; i++) {
		dp[n][i + MAXN * MAXN].second += i;

		ans = min(ans, dp[n][i + MAXN * MAXN]);		
	}

	cout << ans.first << " " << ans.second << "\n";
}