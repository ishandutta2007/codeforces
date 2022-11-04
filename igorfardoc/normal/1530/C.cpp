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
    	sort(b.begin(), b.end());
    	sort(a.begin(), a.end());
    	int l = -1;
    	int r = 2 * n;
    	while(r - l > 1) {
    		int mid = (l + r) / 2;
    		int take1 = (mid + n) - (mid + n) / 4 - mid;
    		int take2 = min(n, (mid + n) - (mid + n) / 4);
    		int a1 = mid * 100; 
    		int a2 = 0;
    		for(int i = n - take1; i < n; i++) {
    			a1 += a[i];
    		}
    		for(int i = n - take2; i < n; i++) {
    			a2 += b[i];
    		}
    		if(a1 >= a2) {
    			r = mid;
    		} else {
    			l = mid;
    		}
    	}
    	cout << r << '\n';
    }

}