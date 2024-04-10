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
    	ll k;
    	cin >> n >> k;
    	--k;
    	vi a(n);
    	int max1 = -1000000001;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		max1 = max(max1, a[i]);
    	}
    	for(int i = 0; i < n; i++) {
    		a[i] = max1 - a[i];
    	}
    	if(k % 2 == 1) {
    		max1 = -1000000001;
    		for(int i = 0; i < n; i++) {
    			max1 = max(max1, a[i]);
    		}
    		for(int i = 0; i < n; i++) {
    			a[i] = max1 - a[i];
    		}
    	}
    	for(auto& el : a) {
    		cout << el << ' ';
    	}
    	cout << '\n';
    }
    
}