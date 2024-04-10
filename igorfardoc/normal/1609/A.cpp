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
    	vector<ll> a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	ll ans = -1;
    	for(int i = 0; i < n; i++) {
    		auto b = a;
    		for(int j = 0; j < n; j++) {
    			if(i == j) continue;
    			while(b[j] % 2 == 0) {
    				b[j] /= 2;
    				b[i] *= 2;
    			}
    		}
    		ll sum = 0;
    		for(const auto& el : b) {
    			sum += el;
    		}
    		ans = max(ans, sum);
    	}
    	cout << ans << '\n';
    }
}