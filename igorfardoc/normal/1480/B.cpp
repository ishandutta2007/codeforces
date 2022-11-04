#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int c, d;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

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
    	cin >> c >> d >> n;
    	vi a(n), b(n);
    	vector<pair<int, int>> e(n);
    	for(int i = 0; i < n; i++) {
    		cin >> e[i].first;
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> e[i].second;
    	}
    	sort(e.begin(), e.end(), cmp);
    	for(int i = 0; i < n; i++) {
    		a[i] = e[i].first;
    		b[i] = e[i].second;
    	}
    	bool ok = true;
    	for(int i = 0; i < n; i++) {
    		if(d <= 0) {
    			ok = false;
    			break;
    		}
    		int am = min((d - 1) / a[i], (b[i] - 1) / c) + 1;
    		d -= a[i] * am;
    		b[i] -= c * am;
    		if(d <= 0 && b[i] > 0) {
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