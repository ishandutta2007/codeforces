#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool cmp(pair <int, int> x, pair <int, int> y){
    return min(x.first, x.second) < min(y.first, y.second);
}

pair <int, int> a[200005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    ll res = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i].first;
    }
    for(int i=1; i<=n; i++){
        cin >> a[i].second;
        res += abs(a[i].first - a[i].second);
    }
    sort(a+1, a+1+n, cmp);
    int mxprvi = 0, mxdrugi = 0;
    int mx = 0;
    for(int i=1; i<=n; i++){
        if(a[i].first < a[i].second){
            mx = max(mx, min(a[i].second, mxdrugi) - a[i].first);
            mxprvi = max(mxprvi, a[i].second);
        }
        else{
            mx = max(mx, min(a[i].first, mxprvi) - a[i].second);
            mxdrugi = max(mxdrugi, a[i].first);
        }
    }
    cout << res - 2*mx << "\n";
    return 0;
}