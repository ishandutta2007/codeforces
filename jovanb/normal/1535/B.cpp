#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[2005];

bool cmp(int a, int b){
    if(a%2 == 0 && b%2 != 0) return 1;
    return 0;
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n, cmp);
    int res = 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            res += (__gcd(a[i], 2*a[j]) > 1);
        }
    }
    cout << res << "\n";
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