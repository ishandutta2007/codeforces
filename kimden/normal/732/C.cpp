#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1002;

int main() {
    ios_base::sync_with_stdio(false);
    vector<ll> v;
    ll a;
    ll ans = 0;
    for(int i = 0; i < 3; i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.rbegin(), v.rend());
    if(v[1] < v[0] - 1){
        ans += v[0] - 1 - v[1];
    }
    if(v[2] < v[0] - 1){
        ans += v[0] - 1 - v[2];
    }
    cout << ans;
    return 0;
}