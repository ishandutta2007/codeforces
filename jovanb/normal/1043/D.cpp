#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int ind[100005];
int pre[100005];
int niz[15][100005];
int res[100005];
int br[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> niz[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        pre[niz[1][i]] = niz[1][i-1];
        ind[niz[1][i]] = i;
    }
    for(int koji=1; koji<=m; koji++){
        for(int i=1; i<=n; i++){
            int x = niz[koji][i];
            if(pre[x] == niz[koji][i-1]) br[ind[x]]++;
        }
    }
    ll ukup=0;
    for(int i=1; i<=n; i++){
        if(br[i] == m) res[i] = res[i-1]+1;
        else res[i] = 1;
        ukup += res[i];
    }
    cout << ukup;
    return 0;
}