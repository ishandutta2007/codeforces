#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int q(int l, int r) {
	int c = r - l + 1;
	cout << "? " << c << ' ';
	for(int i = l; i <= r; i++) {
		cout << i + 1 << ' ';
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
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
    	int n, k;
    	cin >> n >> k;
    	vvi a(k);
    	for(int i = 0; i < k; i++) {
    		int c;
    		cin >> c;
    		a[i].resize(c);
    		for(int j = 0; j < c; j++) {
    			cin >> a[i][j];
    			--a[i][j];
			}
		}
		int max1 = q(0, n - 1);
		int l = 0;
		int r = n;
		while(r - l > 1) {
			int mid = (l + r) / 2;
			if(q(l, mid - 1) == max1) {
				r = mid;
			} else {
				l = mid;
			}
		}
		r = l;
		vi ans(k);
		for(int i = 0; i < k; i++) {
			bool here = false;
			set<int> s;
			for(int j = 0; j < a[i].size(); j++) {
				s.insert(a[i][j]);
				if(a[i][j] == r) {
					here = true;
				}
			}
			if(!here) {
				ans[i] = max1;
				continue;
			}
			cout << "? " << n - a[i].size() << ' ';
			for(int i = 0; i < n; i++) {
				if(s.find(i) == s.end()) {
					cout << i + 1 << ' ';
				}
			}
			cout << endl;
			int aa;
			cin >> aa;
			ans[i] = aa;
		}
		cout << "! ";
		for(int i = 0; i < k; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
		string s;
		cin >> s;
	}
			

}