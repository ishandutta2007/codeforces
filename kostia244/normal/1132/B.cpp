#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
using namespace std;

ll n, q, t, sm = 0;
vi v;

int main()
{
    cin >> n;
    v.resize(n);
    for(auto& i : v) cin >> i, sm += i;
    sort(v.begin(), v.end());
    cin >> q;
    while(q--) {
    cin >> t;
        cout << sm-v[n - t] << "\n";
    }
    return 0;
}