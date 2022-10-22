#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[200005];
ll ima[200005];
ll k[200005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    sort(niz+1, niz+1+n);
    int l, r;
    while(q--){
        cin >> l >> r;
        ima[l]++;
        ima[r+1]--;
    }
    ll ukup=0;
    for(int i=1; i<=n; i++){
        ukup += ima[i];
        k[i] = ukup;
    }
    sort(k+1, k+1+n);
    ukup = 0;
    for(int i=1; i<=n; i++) ukup += niz[i]*k[i];
    cout << ukup;
    return 0;
}