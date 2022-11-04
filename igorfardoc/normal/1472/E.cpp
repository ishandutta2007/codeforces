#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool cmp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
	pair<pair<int, int>, int> a1 = {{a.first.second, a.first.first}, a.second};
	pair<pair<int, int>, int> b1 = {{b.first.second, b.first.first}, b.second};
	return a1 < b1;
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
    	cin >> n;
    	vector<pair<pair<int, int>, int>> a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i].first.first >> a[i].first.second;
    		a[i].second = i;
    	}
    	sort(a.begin(), a.end());
    	vi ans(n, -2);
    	int id1 = -1;
    	int min1 = 1000000001;
    	int now = -1;
    	for(int i = 0; i < n; i++) {
    		while(now < n - 1 && a[now + 1].first.first < a[i].first.first) {
    			++now;
    			if(min1 > a[now].first.second) {
    				min1 = a[now].first.second;
    				id1 = now;
    			}
    		}
    		if(a[i].first.second > min1) {
    			ans[a[i].second] = a[id1].second;
    		}
    	}
    	auto b = a;
    	sort(b.begin(), b.end(), cmp);
    	id1 = -1;
    	min1 = 1000000001;
    	now = -1;
    	for(int i = 0; i < n; i++) {
    		while(now < n - 1 && b[now + 1].first.second < a[i].first.first) {
    			++now;
    			if(min1 > b[now].first.first) {
    				min1 = b[now].first.first;
    				id1 = now;
    			}
    		}
    		if(a[i].first.second > min1) {
    			ans[a[i].second] = b[id1].second;
    		}
    	}
    	for(int i = 0; i < n; i++) {
    		cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	}
}