#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int res[1000];
int br[1000];
int niz[1000];
bool bio[1000];
int resb[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int x=0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        br[niz[i]]++;
        if(br[niz[i]] > 2) x++;
    }
    int a=0, b=0;
    for(int i=1; i<=n; i++){
        if(br[niz[i]] == 2) res[i] = 2;
        if(br[niz[i]] == 1){
            if(a > b){
                b++;
                res[i] = 2;
            }
            else{a++; res[i] = 1;}
        }
    }
    if(!x && a > b){cout << "NO"; return 0;}
    for(int i=1; i<=n; i++){
        if(br[niz[i]] < 3) continue;
        if(bio[niz[i]]){res[i] = resb[niz[i]]; continue;}
        bio[niz[i]] = 1;
        if(a > b){
            b++;
            res[i] = 2;
            resb[niz[i]] = 1;
        }
        else{
            res[i] = 2;
            resb[niz[i]] = 2;
        }
    }
    cout << "YES\n";
    for(int i=1; i<=n; i++){
        if(res[i] == 1) cout << "A";
        else cout << "B";
    }
    return 0;
}