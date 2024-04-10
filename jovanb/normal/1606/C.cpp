#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll p10[20];

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    k++;
    vector <int> vec;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    ll res = 0;
    for(int i=0; i+1<n; i++){
        ll od = min(p10[vec[i+1]]/p10[vec[i]] - 1, k);
        k -= od;
        res += od*p10[vec[i]];
    }
    if(k > 0) res += p10[vec.back()]*k;
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    p10[0] = 1;
    for(int i=1; i<=10; i++) p10[i] = 10*p10[i-1];
    while(t--) solve();
}