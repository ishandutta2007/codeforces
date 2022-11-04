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
    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	s.insert(a);
    }
    vi ans(n, -1);
    for(int i = 1; i < n - 1; i+=2) {
    	ans[i] = *(s.begin());
    	s.erase(s.begin());
    }
    for(int i = 0; i < n; i++) {
    	if(ans[i] != -1) {
    		continue;
    	}
    	int max1 = -1;
    	if(i != 0) {
    		max1 = max(max1, ans[i - 1]);
    	}
    	if(i != n - 1) {
    		max1 = max(max1, ans[i + 1]);
    	}
    	auto it = s.upper_bound(max1);
    	if(it != s.end()) {
    		ans[i] = *it;
    		s.erase(it);
    	} else {
    		ans[i] = *(s.begin());
    		s.erase(s.begin());
    	}
    }
    int res = 0;
    for(int i = 1; i < n - 1; i++) {
    	if(ans[i - 1] > ans[i] && ans[i + 1] > ans[i]) {
    		++res;
    	}
    }
    cout << res << '\n';
    for(int i = 0; i < n; i++) {
    	 cout << ans[i] << ' ';
	}
}