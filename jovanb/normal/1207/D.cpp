#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

ll add(ll a, ll b){
    return (a+b)%MOD;
}

ll mul(ll a, ll b){
    return (a*b)%MOD;
}

int ima1[300005];
int ima2[300005];
int fact[300005];

pair <int, int> niz[300005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    fact[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = mul(fact[i-1], i);
    }
    int res = fact[n];
    for(int i=1; i<=n; i++){
        cin >> niz[i].first >> niz[i].second;
        ima1[niz[i].first]++;
        ima2[niz[i].second]++;
    }
    int r = 1;
    for(int i=1; i<=n; i++){
        r = mul(r, fact[ima1[i]]);
    }
    res = add(res, MOD-r);
    r = 1;
    for(int i=1; i<=n; i++){
        r = mul(r, fact[ima2[i]]);
    }
    res = add(res, MOD-r);
    //cout << res << " je na pocetku\n";
    sort(niz+1, niz+1+n);
    r = 1;
    int ch = 0;
    for(int i=1; i<=n; i++){
        if(niz[i].second < niz[i-1].second) r = 0;
        if(niz[i] == niz[i-1]) ch++;
        else{
            r = mul(r, fact[ch]);
            ch = 1;
        }
    }
    r = mul(r, fact[ch]);
    res = add(res, r);
    cout << res;
    return 0;
}