#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> mkd(n);
    vector<pii> p(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        p[i] = {a[i], i};
    }
    sort(p.rbegin(), p.rend());
    ll ans = 0;
    for(int i = 0; i < k; ++i){
        ans += p[i].first;
        ++mkd[p[i].second];
    }
    cout << ans << endl;
    int ptr = 0;
    int prv = -1;
    for(int i = 0; i < n; ++i){
        if(mkd[i]){
            if(ptr != k - 1) {
                cout << i - prv << " ";
                prv = i;
            }else{
                cout << n - 1 - prv << endl;
                return 0;
            }
            ++ptr;
        }
    }
    return 0;
}