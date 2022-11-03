#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> l(n);
    vector<pll> begs;
    for(int i = 0; i < n; ++i){
        cin >> l[i];
        if(l[i]){
            begs.push_back({i - l[i], -1});
            begs.push_back({i - 1, 1});
        }
    }
    if(begs.size() == 0){
        cout << n << endl;
        return 0;
    }
    sort(all(begs));
    int level = 0;
    int last = -1;
    ll ans = 0;
    for(int i = 0; i < begs.size(); ++i){
        if(level == 0 && begs[i].first > last + 1){
            ans += begs[i].first - last - 1;
        }
        last = begs[i].first;
        level -= begs[i].second;
    }
    ans += n - last - 1;
    cout << ans << endl;



}