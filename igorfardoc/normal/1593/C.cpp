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
    	int n, k;
    	cin >> n >> k;
    	vi a(k);
    	for(int i = 0; i < k; i++) {
    		cin >> a[i];
    	}
    	sort(a.begin(), a.end());
    	int now = 0;
    	int res = 0;
    	for(int i = k - 1; i >= 0; i--) {
    		if(now >= a[i]) {
    			break;
    		}
    		++res;
    		now += n - a[i];
    	}
    	cout << res << '\n';
    }
}