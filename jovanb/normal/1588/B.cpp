#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll query(int l, int r){
    cout << "? " << l << " " << r << endl;
    ll x;
    cin >> x;
    return x;
}

void solve(){
    int n;
    cin >> n;
    ll total = query(1, n);
    int l = 4, r = n, dot = n;
    while(l <= r){
        int mid = (l+r)/2;
        if(query(1, mid) == total){
            dot = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    int K = dot;
    ll x = query(1, dot - 1);
    ll len = total - x + 1;
    int J = K - len + 1;
    total -= len*(len-1)/2;
    x = query(1, J - 2);
    len = total - x + 1;
    int I = J - 1 - len + 1;
    cout << "! " << I << " " << J << " " << K << endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}