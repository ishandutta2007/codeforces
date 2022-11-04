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
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	int now = 1;
    	for(int i = 0; i < n; i++) {
    		if(a[i] * 2 == k) {
    			cout << now << ' ';
    			now = 1 - now;
    			continue;
    		}
    		if(a[i] * 2 > k) {
    			cout << 1 << ' ';
    		} else {
    			cout << 0 << ' ';
    		}
    	}
    	cout << '\n';
    }
}