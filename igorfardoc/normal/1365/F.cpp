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
    	if(n % 2 == 1 && a[n / 2] != b[n / 2]) {
    		cout << "no\n";
    		continue;
    	}
    	multiset<pair<int, int>> s;
    	for(int i = 0; i < n / 2; i++) {
    		s.insert({min(a[i], a[n - 1 - i]), max(a[i], a[n - 1 - i])});
    	}
    	bool ok = true;
    	for(int i = 0; i < n / 2; i++) {
    		auto it = s.find({min(b[i], b[n - 1 - i]), max(b[i], b[n - 1 - i])});
    		if(it == s.end()) {
    			ok = false;
    			break;
    		}
    		s.erase(it);
    	}
    	if(ok) {
    		cout << "yes\n";
    	} else {
    		cout << "no\n";
    	}
    }
}