#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    for(int i = 0; i < n; ++i){
        cin >> l[i] >> r[i];
    }
    ll ans = n;
    sort(rall(l));
    sort(rall(r));
    for(int i = 0; i < n; ++i){
        ans += max(l[i], r[i]);
    }
    cout << ans << endl;

}