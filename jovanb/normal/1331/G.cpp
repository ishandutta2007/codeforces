#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(2);
    cout << fixed;
    
    for(int i=1; i<=11; i++) cin >> niz[i];
    for(int i=11; i>=1; i--){
        ld a = niz[i];
        //cout << a << endl;
        a = a*a*a*5;
        a += sqrtl(1.0*abs(niz[i]));
        if(a >= 400) cout << "f(" << niz[i] << ") = MAGNA NIMIS!\n";
        else cout << "f(" << niz[i] << ") = " << a << "\n";
    }
    return 0;
}