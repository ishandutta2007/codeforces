#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll taxi[1000005];
ll niz[1000005];
ll disl[1000005];
ll disr[1000005];
ll res[1000005];
ll br[1000005];

int cnt=0;

const ll INF = 1000000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    n += m;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x) taxi[i] = ++cnt;
    }
    ll tren = INF;
    for(int i=1; i<=n; i++){
        if(taxi[i]){
            tren = 0;
            res[i] = i;
        }
        else{
            tren += niz[i]-niz[i-1];
            disl[i] = tren;
            res[i] = res[i-1];
        }
    }
    tren = INF;
    for(int i=n; i>=1; i--){
        if(taxi[i]){
            tren = 0;
            res[i] = i;
        }
        else{
            tren += niz[i+1]-niz[i];
            disr[i] = tren;
            if(disr[i] < disl[i]) res[i] = res[i+1];
        }
    }
    for(int i=1; i<=n; i++){
        if(taxi[i]) continue;
        br[taxi[res[i]]]++;
    }
    for(int i=1; i<=m; i++) cout << br[i] << " ";
    return 0;
}