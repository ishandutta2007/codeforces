#include <bits/stdc++.h>
using namespace std;

int niz[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> niz[i];
    sort(niz+1, niz+1+n);
    if(k == n){cout << niz[n]; return 0;}
    if(k == 0){
        if(niz[1] == 1) cout << -1;
        else cout << 1;
        return 0;
    }
    if(niz[k] == niz[k+1]){cout << "-1\n";}
    else cout << niz[k];
    return 0;
}