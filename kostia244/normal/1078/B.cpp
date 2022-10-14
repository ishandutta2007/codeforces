#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1000000007;
 
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	vi a;
	cin >> n;
	a.resize(n);
	map<int, int> cnt;
	int sm = 0;
	for(auto &i : a) cin >> i, cnt[i]++, sm += i;
	int dp[111][101*103];
    memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
    for(auto i : cnt)
    	for(int cst = 101*100; cst>=0; cst--) {
    		for(int k = n-1; k>=0; k--)
    	    	for(int c = 1; c <= i.second; c++) {
//    			if(dp[k][cst]) {
//    				cout << k+c*i.first << " " << cst << " " << dp[k][cst] << "\n";
//    			}
                if(k+c <= n && cst + i.first <= sm)
    			dp[k+c][cst+c*i.first] = min(dp[k+c][cst+c*i.first]+dp[k][cst], 2);
    		}
    	}
    int div;
    {
    	set<int> t(all(a));
    	div = t.size();
    }
    int ans = 0;
    for(auto i : cnt) {
    	for(int c = 1; c <= i.second; c++) {
    		ans = max(ans, c*(dp[c][c*i.first]==1) + (n-c)*(dp[n-c][sm - c*i.first]==1&&c==i.second&&div==2));
    	}
    }
    cout << ans;
}