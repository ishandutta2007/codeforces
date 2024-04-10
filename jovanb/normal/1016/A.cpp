#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int niz[200005];
int res[200005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        res[i] = niz[i]/m;
        niz[i] %= m;
    }
    int suma=0;
    for(int i=1; i<=n; i++){
        suma += niz[i];
        res[i] += suma/m;
        suma %= m;
    }
    for(int i=1; i<=n; i++) cout << res[i] << " ";
    return 0;
}