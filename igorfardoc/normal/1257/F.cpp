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
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    map<vi, int> d;
    int all = (1 << 15) - 1;
    for(int mask = 0; mask < (1 << 15); mask++) {
    	vi here;
    	for(int i = 0; i < n; i++) {
    		here.push_back(__builtin_popcount((a[i] & all) ^ mask));
    	}
    	vi now;
    	for(int i = 0; i < n - 1; i++) {
    		now.push_back(here[i + 1] - here[i]);
    	}
    	d[now] = mask;
    }
    for(int mask = 0; mask < (1 << 15); mask++) {
    	vi here;
    	for(int i = 0; i < n; i++) {
    		here.push_back(__builtin_popcount(((a[i] >> 15) & all) ^ mask));
    	}
    	vi now;
    	for(int i = 0; i < n - 1; i++) {
    		now.push_back(here[i] - here[i + 1]);
    	}
    	auto it = d.find(now);
    	if(it != d.end()) {
    		int ans = mask << 15;
    		ans += it->second;
    		cout << ans;
    		return 0;
    	}
    }
    cout << -1;
}