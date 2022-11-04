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
    ll k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    int now = n;
    vector<ll> need;
    for(int i = 1; i < n; i++) {
    	if(a[i] - a[i - 1] <= x) {
    		--now;
    	} else {
    		need.push_back(((a[i] - a[i - 1] - x - 1) / x + 1));
    	}
    }
    sort(need.begin(), need.end());
    for(int i = 0; i < need.size(); i++) {
    	if(need[i] <= k) {
    		k -= need[i];
    		--now;
    	}
    }
    cout << now << '\n';
}