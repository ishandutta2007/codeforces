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
    	vi a(n), b(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> b[i];
    	}
    	int l = 0;
    	int r = 1000000000;
    	while(r - l > 1) {
    		int mid = (l + r) / 2;
    		ll sum = 0;
    		for(int i = 0; i < n; i++) {
    			if(a[i] > mid) {
    				sum += b[i];
    			}
    		}
    		if(sum <= mid) {
    			r = mid;
    		} else {
    			l = mid;
    		}
    	}
    	cout << r << '\n';
    }
}