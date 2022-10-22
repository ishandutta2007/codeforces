#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll l;
    cin >> l;
    l *= 8;
    niz[0] = -500;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    sort(niz+1, niz+1+n);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(niz[i] != niz[i-1]) cnt++;
    }
    /*cout << cnt;
    return 0;*/
    ll k = l/n;
    if(k > 20){
        cout << 0;
        return 0;
    }
    ll K = (1 << k);
    if(cnt <= K){
        cout << 0;
        return 0;
    }
    int lf = 1;
    int tren = 0;
    int mn = n;
    for(int r=1; r<=n; r++){
        if(niz[r] != niz[r-1]) tren++;
        while(tren > K){
            lf++;
            if(niz[lf] != niz[lf-1]) tren--;
        }
        mn = min(mn, n - (r-lf+1));
    }
    cout << mn;
    return 0;
}