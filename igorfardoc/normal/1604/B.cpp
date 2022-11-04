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
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		 cin >> a[i];
		}
		if(n % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		bool ok = false;
		for(int i = 0; i < n - 1; i++) {
			if(a[i + 1] <= a[i]) {
				ok = true;
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