#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    string s;
    cin >> s;
    vi f(1 << 20, 0);
    int n;
    n = s.size();
    for(int i = 0; i < n; i++) {
    	int now = 0;
    	for(int j = i; j < n; j++) {
    		if((1 << (s[j] - 'a')) & now) {
    			break;
    		}
    		now ^= (1 << (s[j] - 'a'));
    		f[now] = __builtin_popcount(now);
    	}
    }
    for(int i = 0; i < 20; i++) {
    	for(int j = 0; j < (1 << 20); j++) {
    		if((j >> i) & 1) {
    			f[j] = max(f[j], f[j ^ (1 << i)]);
    		}
    	}
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	int now = 0;
    	for(int j = i; j < n; j++) {
    		if((1 << (s[j] - 'a')) & now) {
    			break;
    		}
    		now ^= (1 << (s[j] - 'a'));
    		int can = (1 << 20) - 1 - now;
    		ans = max(ans, f[can] + __builtin_popcount(now));
    	}	
    }
    cout << ans;
}