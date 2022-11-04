#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, int> lo, hi;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!lo.count(a[i])){
            lo[a[i]] = i;
        }
        hi[a[i]] = i;
    }
    int ans = 1;
    vector<int> lolo(n), hihi(n);
    for (int i = 0; i < n; ++i){
        hihi[i] = max((i == 0 ? -998244353 : hihi[i - 1]), hi[a[i]]);
    }
    for (int i = n - 1; i >= 0; --i){
        lolo[i] = min((i == n - 1 ? 998244353 : lolo[i + 1]), lo[a[i]]);
    }
    for(int i = 0; i < n - 1; ++i){
        if (hihi[i] == i && lolo[i + 1] == i + 1){
            ans = (ans * 2LL) % 998244353;
        }
    }
    cout << ans << endl;
}