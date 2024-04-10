#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000007;

/*struct broj{
    int p, q;
    bool operator==(const broj &b){
        return p*b.q == b.p*q;
    }
} raz[100005];*/

/*struct brr{
    bool operator()(broj a, broj b){
        return a.p*b.q < b.p*a.q;
    }
};*/

ld divide(int a, int b){
    if(a == 0) return 0;
    if(b == 0) return INF;
    return (1.0*a)/b;
}

int niz[100005];
int novi[100005];
ld raz[100005];
//map <broj, int, brr> br;
map <ld, int> br;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    if(n == 1){
        cout << 0;
        return 0;
    }
    if(n == 2){
        if(niz[1] == 0 && niz[2] != 0){
            cout << 1;
        }
        else cout << 0;
        return 0;
    }
    for(int i=2; i<=n; i++){
        raz[i] = divide(niz[i], niz[i-1]);
        br[raz[i]]++;
    }
    if(br[raz[2]] == n-1){
        cout << 0;
        return 0;
    }
    if(n <= 10){
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                novi[j-1] = niz[j];
            }
            ld r1 = divide(novi[2], novi[1]);
            for(int j=2; j<n; j++){
                ld r2 = divide(novi[j], novi[j-1]);
                if(r1 != r2) break;
                if(j == n-1){
                    cout << 1;
                    return 0;
                }
            }
            novi[i] = niz[i];
        }
        cout << 2;
        return 0;
    }
    if(br[raz[3]] == n-2){
        if(!(raz[2] == raz[3])){
            cout << 1;
            return 0;
        }
        if(!(raz[n] == raz[3])){
            cout << 1;
            return 0;
        }
    }
    for(int i=2; i<=n; i++){
        if(br[raz[i]] >= n-3){
            for(int j=2; j<n; j++){
                if(!(raz[j] == raz[i])){
                    ld a = divide(niz[j+1], niz[j-1]);
                    /*cout << a << endl;
                    cout << raz[i] << endl;*/
                    if(a == raz[i]){
                        cout << 1;
                        return 0;
                    }
                }
            }
        }
    }
    cout << 2;
    return 0;
}