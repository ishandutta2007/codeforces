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
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int summary = 0;
    for(int i = -30; i < 31; i++) {
    	vector<int> res(n, 0);
    	int prev = n;
    	int val = 0;
    	for(int j = n - 1; j >= 0; j--) {
    		if(a[j] != i) {
    			continue;
    		}
    		int ans = 0;
    		int sumnow = 0;
    		bool can = true;
    		for(int k = j + 1; k <= prev; k++) {
    			if(k == n) {
    				continue;
    			}
    			if(a[k] > a[j]) {
    				can = false;
    				break;
    			}
    			sumnow += a[k];
    			ans = max(ans, sumnow);
    		}
    		if(prev != n && can) {
    			ans = max(ans, sumnow + val);
    		}
    		res[j] = ans;
    		prev = j;
    		val = ans;
    	}
    	prev = -1;
    	val = 0;
    	for(int j = 0; j < n; j++) {
    		if(a[j] != i) {
    			continue;
    		}
    		int ans = 0;
    		int sumnow = 0;
    		bool can = true;
    		for(int k = j - 1; k >= prev; k--) {
    			if(-1 == k) {
    				continue;
    			}
    			if(a[k] > a[j]) {
    				can = false;
    				break;
    			}
    			sumnow += a[k];
    			ans = max(ans, sumnow);
    		}
    		if(prev != -1 && can) {
    			ans = max(ans, sumnow + val);
    		}
    		res[j] += ans;
    		summary = max(summary, res[j]);
    		prev = j;
    		val = ans;
    	}
    }
    cout << summary;
}