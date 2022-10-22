#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int p = 0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        for(int j=1; j<i; j++){
            if(niz[j] > niz[i]){
                p ^= 1;
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int len = r-l+1;
        int swaps = len/2;
        if(swaps%2) p ^= 1;
        if(p) cout << "odd\n";
        else cout << "even\n";
    }
    return 0;
}