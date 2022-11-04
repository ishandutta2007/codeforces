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
    	int mina = 1000000000;
    	int minb = 1000000000;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		mina = min(a[i], mina);
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> b[i];
    		minb = min(b[i], minb);
    	}
    	ll ans = 0;
    	for(int i = 0; i < n; i++) {
    		int can = min(a[i] - mina, b[i] - minb);
    		ans += can;
    		int anew = a[i] - can;
    		int bnew = b[i] - can;
    		ans += anew - mina + bnew - minb;
    	}
    	cout << ans << '\n';
    }
}