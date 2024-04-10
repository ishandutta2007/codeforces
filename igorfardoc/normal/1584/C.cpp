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
    	vi a(300, 0), b(300, 0);
    	for(int i = 0; i < n; i++) {
    		int a1;
    		cin >> a1;
    		a[a1 + 102]++;
    	}
    	for(int i = 0; i < n; i++) {
    		int a1;
    		cin >> a1;
    		b[a1 + 102]++;
    	}
    	bool ok = true;
    	for(int i = 299; i >= 0; i--) {
    		if(b[i] == 0) {
    			continue;
    		}
    		int can = min(a[i], b[i]);
    		b[i] -= can;
    		a[i] -= can;
    		can = min(b[i], a[i - 1]);
    		b[i] -= can;
    		a[i - 1] -= can;
    		if(b[i] > 0) {
    			ok = false;
    			break;
    		}
    	}
    	if(ok) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}