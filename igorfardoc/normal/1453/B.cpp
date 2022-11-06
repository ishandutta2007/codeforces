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
    	vi a(n);
    	for(int i = 0; i < n; i++) { 
    		cin >> a[i];
    	}
    	ll sum = 0;
    	ll res;
    	for(int i = 0; i < n - 1; i++) {
    		sum += abs(a[i] - a[i + 1]);
    	}
    	res = sum;
    	for(int i = 1; i < n - 1; i++) {
    		if(a[i - 1] <= a[i] && a[i] <= a[i + 1]) {
    			continue;
    		}
    		if(a[i - 1] >= a[i] && a[i] >= a[i + 1]) {
    			continue;
    		}
    		res = min(res, sum - 2 * min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1])));
    	}
    	res = min(res, sum - abs(a[0] - a[1]));
    	res = min(res, sum - abs(a[n - 1] - a[n - 2]));
    	cout << res << '\n';
    }
}