#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[100005];
bool bio[100005];
bool ima[100005];
int brd[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int i=n; i>1; i--){
        brd[i] = brd[i+1];
        if(ima[niz[i]]) continue;
        ima[niz[i]] = 1;
        brd[i]++;
    }
    ll ukup=0;
    for(int i=1; i<n; i++){
        if(bio[niz[i]]) continue;
        bio[niz[i]] = 1;
        ukup += brd[i+1];
    }
    cout << ukup;
    return 0;
}