#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS         std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n)      fixed << setprecision(n)

#define F           first
#define S           second
#define pii         pair<int, int>
#define pll         pair<ll, ll>

#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()
#define sz(a)       a.length()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e+7;
const int N = 100005;

int p[N][5];
bool dp[N][5];

void solve(){
    int n; cin >> n;
	vector<int> a(n);
	for (auto &z : a) cin >> z;
	int i, j;
	for (i = 0; i <= n; i++)
		for (j = 0; j < 5; j++)
			p[i][j] = -1, dp[i][j] = false;
 
	for (i = 0; i < 5; i++) dp[0][i] = true;
 
	int k;
	for (i = 1; i < n; i++){
		for (j = 0; j < 5; j++){
			if (a[i] == a[i - 1]){
				if (j > 0 && dp[i - 1][j - 1])
					dp[i][j] = true, p[i][j] = j - 1;
				else if (j < 4 && dp[i - 1][j + 1])
					dp[i][j] = true, p[i][j] = j + 1;
			}
			else if (a[i] > a[i - 1]){
				for (k = 0; k < j; k++){
					if (dp[i - 1][k])
						dp[i][j] = true, p[i][j] = k;
				}
			}
			else{
				for (k = 4; k > j; k--)
					if (dp[i - 1][k]) dp[i][j] = true, p[i][j] = k;
			}
		}
	}

	for (i = 0; i < 5; i++){
		if (dp[n - 1][i]){
			vector<int> ans;
			int cur = i;
			j = n - 1;
			while (cur != -1){
				ans.emplace_back(cur + 1);
				cur = p[j--][cur];
			}
			for (j = n - 1; j >= 0; j--)
				cout << ans[j] << ' ';
			return ;
		}
	}
	cout << -1;
} 

int main(){
    IOS;
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}