#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll n;
    cin >> n;
    ll sum = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a+1, a+1+n);
    int istih = 0;
    for(int i=2; i<=n; i++){
        if(a[i] == a[i-1]) istih++;
    }
    if(istih > 1){
        cout << "cslnb";
        return 0;
    }
    a[0] = -5;
    for(int i=1; i<n; i++){
        if(a[i] == a[i+1] && a[i] == a[i-1] + 1){
            cout << "cslnb";
            return 0;
        }
        if(a[i] == a[i+1] && a[i] == 0){
            cout << "cslnb";
            return 0;
        }
    }
    sum -= n*(n-1)/2;
    if(sum <= 0){
        cout << "cslnb";
        return 0;
    }
    if(sum%2) cout << "sjfnb";
    else cout << "cslnb";
    return 0;
}