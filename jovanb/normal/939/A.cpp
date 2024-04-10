#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int niz[10000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) continue;
            int c = niz[i];
            if(niz[c] == j && niz[j] == i){cout << "YES"; return 0;}
        }
    }
    cout << "NO";
    return 0;
}