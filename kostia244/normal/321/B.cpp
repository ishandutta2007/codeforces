#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, t;
multiset<int> atk, def, my;
string str;

int kall(multiset<int> my, multiset<int> def, multiset<int> atk) {
    while(!def.empty()) {
        int t = *def.begin();
        auto it = my.upper_bound(t);
        if(it == my.end())
            return 0;
        my.erase(it);
        def.erase(def.begin());
    }
    int ans = 0;
    while(!atk.empty()) {
        int t = *atk.begin();
        auto it = my.upper_bound(t-1);
        if(it == my.end())
            return ans;
        ans += (*it-t);
        my.erase(it);
        atk.erase(atk.begin());
    }
    for(auto i : my)
        ans += i;
    return ans;
}
int nall(multiset<int> my, multiset<int> atk, int k) {
    int ans = 0;
    auto i = atk.begin(), j = my.end();
    advance(j, -k);
    while(k--) {
        if((*j-*i) < 0)
            return 0;
        ans += (*j-*i);
        i++;
        j++;
    }
    return ans;
}
int main() {
	doin();
	cin >> m >> n;
	while(m--) {
        cin >> str >> t;
        if(str == "DEF") def.insert(t);
        else atk.insert(t);
	}
	while(n--) {
        cin >> t;
        my.insert(t);
	}
	int ans = kall(my, def, atk);
	for(int i = 1; i <= min(atk.size(), my.size()); i++)
        ans = max(ans, nall(my, atk, i));
    cout << ans;
}