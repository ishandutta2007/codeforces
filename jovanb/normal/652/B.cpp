#include <bits/stdc++.h>
using namespace std;

int niz[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    sort(niz+1,niz+1+n);
    int k = ceil(n/2.0);
    for(int i=1; i<=k; i++){
        cout << niz[i] << " ";
        if(i+k <= n) cout << niz[i+k] << " ";
    }
    return 0;
}