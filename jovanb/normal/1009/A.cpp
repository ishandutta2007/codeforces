#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz1[100005];
ll niz2[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> niz1[i];
    }
    for(int j=1; j<=m; j++){
        cin >> niz2[j];
    }
    ll br=0;
    ll j=1;
    ll ukup=0;
    for(int i=1; i<=n; i++){
        if(j > m) break;
        if(niz1[i] <= niz2[j]){
            j++;
            ukup++;
        }
        if(j > m) break;
    }
    cout << ukup;
    return 0;
}