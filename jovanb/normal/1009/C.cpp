#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    cout<<fixed;

    ll sum = 0;
    ll tren;
    ll n, m;
    cin >> n >> m;
    while(m--){
        ll x, d;
        cin >> x >> d;
        tren = 0;
        if(d >= 0) tren += (n*(n-1))/2;
        else if(n == 1){
        }
        else if(n == 2){
            tren += 1;
        }
        else{
            if(n%2 == 1){
                ll s1 = n/2;
                tren += (s1*(s1+1));
            }
            else{
                ll s1 = n/2;
                ll s2 = n/2-1;
                tren += (s1*(s1+1)/2);
                tren += (s2*(s2+1)/2);
            }
        }
        sum += tren*d+n*x;
    }
    ld res = sum;
    cout << res/n;
    return 0;
}