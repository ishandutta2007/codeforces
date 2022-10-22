#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int z1 = 0, z2 = 0;
    char c;
    for(int i=1; i<=3; i++){
        cin >> c;
        niz[i] = c-'0';
        z1 += niz[i];
    }
    for(int i=4; i<=6; i++){
        cin >> c;
        niz[i] = c-'0';
        z2 += niz[i];
    }
    if(z1 == z2){
        cout << 0;
        return 0;
    }
    if(z1 < z2){
        int z = z2-z1;
        for(int i=1; i<=3; i++){
            niz[i] = 9-niz[i];
        }
        sort(niz+1, niz+1+6);
        reverse(niz+1, niz+1+6);
        for(int i=1; i<=6; i++){
            z -= niz[i];
            if(z <= 0){
                cout << i;
                return 0;
            }
        }
    }
    else{
        int z = z1-z2;
        for(int i=4; i<=6; i++){
            niz[i] = 9-niz[i];
        }
        sort(niz+1, niz+1+6);
        reverse(niz+1, niz+1+6);
        for(int i=1; i<=6; i++){
            z -= niz[i];
            if(z <= 0){
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}