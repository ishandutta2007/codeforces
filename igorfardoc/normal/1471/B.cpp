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
    	int n, x;
    	cin >> n >> x;
    	ll sum = 0;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		sum += a[i];
    	}
    	ll now = x;
    	for(int i = 0; i < 35; i++) {
    		bool ok = true;
    		for(int j = 0; j < n; j++) {
    			if(a[j] % x == 0) {
    				sum += now * (a[j] / x);
    				a[j] /= x;
    			} else {
    				ok = false;
    				break;
    			}
    		}
    		if(!ok) {
    			break;
    		}
    		now *= x;
    	}
    	cout << sum << '\n';
    }
}