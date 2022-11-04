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
    	int sum = 0;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		sum += a[i];
    	}
    	int res = n - 1;
    	for(int i = n; i > 1; i--) {
    		if(sum % i != 0) {
    			continue;
    		}
    		int need = sum / i;
    		int now = 0;
    		bool ok = true;
    		for(int j = 0; j < n; j++) {
    			if(a[j] + now > need) {
    				ok = false;
    				break;
    			}
    			now += a[j];
    			if(now == need) {
    				now = 0;
    			}
    		}
    		if(ok) {
    			res = n - i;
    			break;
    		}
    	}
    	cout << res << '\n';
    }
}