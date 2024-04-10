#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, d;

int niz[1000];
map <int, int> bio;

int checc(int k){
    int mindis = abs(niz[1]-k);
    for(int i=1; i<=n; i++){
        mindis = min(mindis, abs(k-niz[i]));
    }
    if(mindis == d) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;


    cin >> n >> d;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    int ukup=0;
    for(int i=1; i<=n; i++){
        int x = niz[i]-d;
        if(!bio[x]){
            bio[x] = 1;
            ukup += checc(x);
        }
        x = niz[i]+d;
        if(!bio[x]){
            bio[x] = 1;
            ukup += checc(x);
        }
    }
    cout << ukup;
    return 0;
}