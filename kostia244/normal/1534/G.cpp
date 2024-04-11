#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1<<30;
struct sset : public multiset<ll> {
	ll bias = 0;
	void insert(int x) {
		multiset<ll>::insert(x-bias);
	}
	ll get_min() {
		return *begin() + bias;
	}
	void pop_min() {
		erase(find(*begin()));
	}
	ll get_max() {
		return *rbegin() + bias;
	}
	void pop_max() {
		erase(find(*rbegin()));
	}
	void add(ll x) {
		bias += x;
	}
};
int n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    map<ll, vector<ll>> diags;
    sset L, R;
    ll lst = 0, ans = 0;
    for(int x, y, i = 0; i < n; i++) {
        cin >> x >> y;
        diags[x+y].push_back(y);
    }
    
    for(auto [diag, vec] : diags) {
        R.add(diag-lst);
        for(auto a : vec) {
            if(L.empty()) {
                L.insert(a);
                R.insert(a);
            } else if(L.get_max() <= a && a <= R.get_min()) {
                L.insert(a);
                R.insert(a);
            } else if(a < L.get_max()) {
                ans += L.get_max()-a;
                L.insert(a);
                L.insert(a);
                R.insert(L.get_max());
                L.pop_max();
            } else {
                ans += a-R.get_min();
                R.insert(a);
                R.insert(a);
                L.insert(R.get_min());
                R.pop_min();
            }
        }
        lst = diag;
    }
    cout << ans << '\n';
}