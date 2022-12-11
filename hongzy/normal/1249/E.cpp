#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 4e5 + 10;

int n;
ll c, a[N], b[N], sa[N], sb[N], dp[N];

int main() {
	ucin();
	cin >> n >> c;
	for(int i = 1; i < n; i ++) {
		cin >> a[i]; sa[i] = sa[i - 1] + a[i];
	}
	for(int i = 1; i < n; i ++) {
		cin >> b[i]; sb[i] = sb[i - 1] + b[i];
	}
	dp[1] = 0; ll m1 = c, m2 = 0;
	for(int i = 2; i <= n; i ++) {
		dp[i] = min(m1 + sb[i - 1], m2 + sa[i - 1]);
		m1 = min(m1, dp[i] - sb[i - 1] + c);
		m2 = min(m2, dp[i] - sa[i - 1]);
	}
	for(int i = 1; i <= n; i ++)	
		cout << dp[i] << ' ';
	return 0;
}