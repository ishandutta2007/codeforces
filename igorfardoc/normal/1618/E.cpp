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
    	vi b(n);
    	ll sumb = 0;
    	for(int i = 0; i < n; i++) {
    		cin >> b[i];
    		sumb += b[i];
    	}
    	ll ameach = (ll)n * (n + 1) / 2;
    	if(sumb % ameach != 0) {
    		cout << "NO\n";
    		continue;
    	}
    	ll suma = sumb / ameach;
    	vi a(n);
    	bool ok = true;
    	for(int i = 0; i < n; i++) {
    		ll dt = b[i] - suma - b[(i - 1 + n) % n];
    		dt = -dt;
    		if(dt <= 0 || dt % n != 0) {
    			ok = false;
    			break;
    		}
    		a[i] = dt / n;
    	}
    	if(!ok) {
    		cout << "NO\n";
    		continue;
    	}
    	cout << "YES\n";
    	for(int i = 0; i < n; i++) {
    		cout << a[i] << ' ';
    	}
    	cout << '\n';
    }
}