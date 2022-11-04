#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
 
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	int ans = 0;
    	unordered_map<int, int> prev1;
    	unordered_map<int, int> now1;
    	unordered_map<int, int>* prev;
    	unordered_map<int, int>* now;
    	now1.reserve(2000);
    	prev1.reserve(2000);
    	prev1[a[n - 1]] = 1;
    	for(int i = n - 2; i >= 0; i--) {
    		if((n - i) % 2 == 0) {
    			now = &now1;
    			prev = &prev1;
    		} else {
    			now = &prev1;
    			prev = &now1;
    		}
    		now->clear();
    		(*now)[a[i]] = 1;
    		for(const auto& el : *prev) {
    			(*now)[a[i] / ((a[i] - 1) / el.first + 1)] += el.second;
    			ans = (ans + (ll)((a[i] - 1) / el.first) * el.second % mod * (i + 1)) % mod;
    		}
    		/*for(const auto& el : now) {
    			cout << el.first << ' ' << el.second << '\n';
    		}
    		cout << endl;*/
    	}
    	cout << ans << '\n';
    }
}