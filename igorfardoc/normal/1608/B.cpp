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
    	int n, a, b;
    	cin >> n >> a >> b;
    	if(a + b > n - 2) {
    		cout << "-1\n";
    		continue;
    	}
    	if(a > (n - 1) / 2 || b > (n - 1) / 2) {
    		cout << "-1\n";
    		continue;
    	}
    	if(abs(a - b) > 1) {
    		cout << "-1\n";
    		continue;
    	}
    	vi a1(n, 1);
    	for(int i = 0; i < n; i++) {
    		a1[i] = i;
    	}
    	for(int i = 0; i < a + b; i++) {
    		int here = n - a - b - 1 + i;
    		if(i % 2 == 0) {
    			a1[here] = a1[here - 1] + 1;
    			a1[here + 1] = a1[here] - 1;
    		} else {
    			a1[here] = a1[here - 1] - 1;
    			a1[here + 1] = a1[here] + 1;
    		}
    	}
    	vector<pair<int, int>> p;
    	for(int i = 0; i < n; i++) {
    		p.push_back({a1[i], i});
    	}
    	vi ans(n);
    	sort(p.begin(), p.end());
    	for(int i = 0; i < n; i++) {
    		ans[p[i].second] = i + 1;
    	}
    	int ammx = 0;
    	for(int i = 1; i < n - 1; i++) {
    		if(ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) {
    			++ammx;
    		}
    	}
    	if(ammx != a) {
    		for(int i = 0; i < n; i++) {
    			ans[i] = n + 1 - ans[i];
    		}
    	}
    	for(const auto& el : ans) {
    		cout << el << ' ';
    	}
    	cout << '\n';
    }
}