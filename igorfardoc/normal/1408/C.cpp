#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const ld eps = 1e-7;



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
    	int n, l;
    	cin >> n >> l;
    	vi a(n + 2);
    	a[0] = 0;
    	a[n + 1] = l;
    	for(int i = 1; i <= n; i++) {
    		cin >> a[i];
    	}
    	n += 2;
    	vector<ld> fir(n + 2);
    	vector<ld> sec(n + 2);
    	int now = 1;
    	fir[0] = 0;
    	for(int i = 1; i < n; i++) {
    		fir[i] = fir[i - 1] + (ld)(a[i] - a[i - 1]) / now;
    		++now;
    	}
    	sec[n - 1] = 0;
    	now = 1;
    	for(int i = n - 2; i >= 0; i--) {
    		sec[i] = sec[i + 1] + (ld)(a[i + 1] - a[i]) / now;
    		++now;
    	}
    	int now1 = 0;
    	for(int i = 0; i < n - 1; i++) {
    		++now1;
    		int now2 = n - now1;
    		if(max(fir[i], sec[i + 1]) - eps < min(fir[i + 1], sec[i])) {
    			ld ans;
    			if(fir[i] < sec[i + 1]) {
    				ans = sec[i + 1] + (ld)(a[i + 1] - a[i] - now1 * (sec[i + 1] - fir[i])) / n;
    			} else {
    				ans = fir[i] + (ld)(a[i + 1] - a[i] - now2 * (fir[i] - sec[i + 1])) / n;
    			}
    			cout << fixed << setprecision(10) << ans << '\n';
    			break;
    		}
    	}
    }
}