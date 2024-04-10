#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll res[3][300005];
ll a[300005];
ll b[300005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n;
    cin >> n;
    ll suma=0;
    ll maxres=0;
    for(int i=1; i<=n; i++){cin >> a[i]; suma += a[i];}
    for(int i=1; i<=n; i++){cin >> b[i]; suma += b[i];}
    //suma -= a[1];
    for(int i=2; i<=n; i++){
        res[2][1] += (i-1)*a[i];
    }
    for(int i=1; i<=n; i++){
        res[2][1] += (2*n-i)*b[i];
    }
    maxres = res[2][1];
    for(int koji=3; koji<=n; koji+=2){
        res[2][koji] = res[2][koji-2];
        suma -= b[koji-1]+b[koji-2]+a[koji-2]+a[koji-3];
        ll bilo = 2*n-1;
        ll sad = koji*2-5;
        res[2][koji] -= (bilo-sad)*b[koji-2];
        bilo--;
        sad++;
        res[2][koji] -= (bilo-sad)*b[koji-1];
        res[2][koji] += 2*suma;
        maxres = max(maxres, res[2][koji]);
    }
    suma = 0;
    for(int i=2; i<=n; i++) suma += a[i];
    for(int i=1; i<=n; i++) suma += b[i];
    if(n <= 1){cout << maxres; return 0;}
    for(int i=1; i<=n; i++){
        res[1][2] += b[i]*i;
    }
    for(int i=2; i<=n; i++){
        res[1][2] += a[i]*(2*n-i+1);
    }
    maxres = max(maxres, res[1][2]);
    for(int koji=4; koji<=n; koji+=2){
        res[1][koji] = res[1][koji-2];
        suma -= a[koji-1]+a[koji-2]+b[koji-2]+b[koji-3];
        ll bilo = 2*n-1;
        ll sad = koji*2-5;
        res[1][koji] -= (bilo-sad)*a[koji-2];
        bilo--;
        sad++;
        res[1][koji] -= (bilo-sad)*a[koji-1];
        res[1][koji] += 2*suma;
        maxres = max(maxres, res[1][koji]);
    }
    cout << maxres;
    return 0;
}