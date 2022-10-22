#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld niz[1000];

int n;

ld resi(int i){
    ld res=0;
    for(int x=1; x<=i; x++){
        ld s = niz[x];
        for(int j=1; j<=i; j++){
            if(j == x) continue;
            s *= 1.00-niz[j];
        }
        res += s;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    sort(niz+1, niz+1+n);
    reverse(niz+1, niz+1+n);
    ld maxres = niz[1];
    if(abs(niz[1]-1) < 1e-9){cout << 1; return 0;}
    for(int i=1; i<=n; i++){
        maxres = max(maxres, resi(i));
    }
    cout << maxres;
    return 0;
}