#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int ima[2];
int niz[300005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll suma=0;
    ll res=0;
    ima[0] = 1;
    for(int i=1; i<=n; i++){
        ll x;
        cin >> x;
        niz[i] = __builtin_popcountll(x);
        suma += niz[i];
        suma %= 2;
        res += ima[suma];
        ima[suma]++;
    }
    for(int i=1; i<=n; i++){
        suma = 0;
        int mx=niz[i];
        for(int j=i; j<=n && j-i<=70; j++){
            suma += niz[j];
            mx = max(mx, niz[j]);
            if(mx > suma-mx && suma%2 == 0) res--;
        }
    }
    cout << res;
    return 0;
}