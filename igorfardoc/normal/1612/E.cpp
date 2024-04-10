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
    vi m(n), k(n);
    for(int i = 0; i < n; i++) {
    	cin >> m[i] >> k[i];
    }
    vi ans;
    ll a1 = 0;
    ll b1 = 1;
    for(int len = 1; len < 50; len++) {
	    vector<ll> am(200001, 0);
	    for(int i = 0; i < n; i++) {
	    	am[m[i]] += min(k[i], len);
	    }
	    vector<pair<ll, int>> all;
	    for(int i = 1; i <= 200000; i++) {
	    	if(am[i] > 0) {
	    		all.push_back({am[i], i});
	    	}
	    }
	    sort(all.begin(), all.end());
	    ll a = 0;
	    ll b = len;
	    vi anshere;
	    for(int i = all.size() - 1; i >= max((ll)0, (int)all.size() - b); i--) {
	    	a += all[i].first;
	    	anshere.push_back(all[i].second);
	    }
	    if(a * b1 > b * a1) {
	    	ans = anshere;
	    	a1 = a;
	    	b1 = b;
	    }
	}
	cout << ans.size() << '\n';
	for(const auto& el : ans) {
		cout << el << ' ';
	}
}