#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[1000000];
ll n=0;

ll MAX = 1'000'000'000'000'000'000;

void generisi(ll br, int brs){
    niz[++n] = br;
    if(MAX/10 < br) return;
    generisi(br*10, brs);
    if(brs >= 3) return;
    for(int i=1; i<=9; i++){
        generisi(br*10+i, brs+1);
    }
}

ll bs(ll x){
    ll l=1, r=n, maxres=0;
    while(l <= r){
        ll mid = (l+r)/2;
        if(niz[mid] <= x){maxres = mid; l = mid+1;}
        else r = mid-1;
    }
    return maxres;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    for(int i=1; i<=9; i++) generisi(i, 1);
    sort(niz+1, niz+1+n);
    int q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        cout << bs(b)-bs(a-1) << "\n";
    }
    return 0;
}