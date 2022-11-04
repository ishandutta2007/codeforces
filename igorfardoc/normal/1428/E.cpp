#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll f(int a, int p) {
	int w = a / p;
	int amw1 = a - w * p;
	int amw = p - amw1;
	return (ll)w * w * amw + (ll)(w + 1) * (w + 1) * amw1;
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
    multiset<pair<pair<ll, int>, int>> s;
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	ans += (ll)a * a;
    	ll next = 1;
    	if(a != 1) {
    		next = f(a, 2);
    	}
    	s.insert({{(ll)a * a - next, a}, 1});
    }
    for(int i = 0; i < k - n; i++) {
    	auto p = *(s.rbegin());
    	s.erase(--s.end());
    	ans -= p.first.first;
    	pair<pair<ll, int>, int> now = {{0, p.first.second}, p.second + 1};
    	if(p.second != p.first.second - 1) {
    		ll here = f(p.first.second, p.second + 1) - f(p.first.second, p.second + 2);
    		now.first.first = here;
    	}
    	s.insert(now);
    }
    cout << ans;
}