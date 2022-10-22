#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map <ll, ll> pos;
ll niz[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<=n; i++){
        while(pos[niz[i]] != 0){
            niz[pos[niz[i]]] = -1;
            pos[niz[i]] = 0;
            niz[i] *= 2;
        }
        pos[niz[i]] = i;
    }
    ll br=0;
    for(int i=1; i<=n; i++){
        if(niz[i] != -1) br++;
        //cout << niz[i] << " ";
    }
    cout << br << "\n";
    for(int i=1; i<=n; i++){
        if(niz[i] != -1) cout << niz[i] << " ";
    }
    return 0;
}