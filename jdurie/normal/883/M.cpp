#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define F(i, l, r) for(ll i = l; i < (r); i++)
#define G(x) ll x; cin >> x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    G(x) G(y) G(a) G(b)
    cout << 2*(abs(a-x)+abs(b-y)+2) + 2 * (x==a or y==b) << endl;
}