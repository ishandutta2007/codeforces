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
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vi a(n), b(n), c(n);
    	for(int i = 0; i < n; i++) {
    		cin >> c[i];
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> b[i];
    	}
    	ll now = max(a[1], b[1]) - min(a[1], b[1]) + 1;
    	ll res = 0;
    	for(int i = 1; i < n; i++) {
    		res = max(res, now + c[i]);
    		if(i == n - 1) {
    			break;
    		}
    		if(a[i + 1] == b[i + 1]) {
    			now = 1;
    		} else {
    			now = max(now + min(a[i + 1], b[i + 1]) + c[i] - max(a[i + 1], b[i + 1]) + 1, (ll)max(a[i + 1], b[i + 1]) - min(a[i + 1], b[i + 1]) + 1);
    			//now += min(a[i + 1], b[i + 1]) + c[i] - max(a[i + 1], b[i + 1]) + 1;
    			//now += c[i] + c[i] - max(a[i + 1], b[i + 1]) - min(a[i + 1], b[i + 1]) + 2;
    		}
    	}
    	cout << res << '\n';
    }
}