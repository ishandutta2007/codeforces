#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int br[65];
int niz[200005];
ll a[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int tren = 0;
    int mx = 0;
    for(int i=1; i<=n; i++){
        ll x;
        cin >> x;
        a[i] = x;
        int cnt = 0;
        while(x%2 == 0){
            cnt++;
            x /= 2;
        }
        niz[i] = cnt;
        br[cnt]++;
        if(mx < br[cnt]){
            mx = br[cnt];
            tren = cnt;
        }
    }
    cout << n-mx << "\n";
    for(int i=1; i<=n; i++){
        if(niz[i] != tren) cout << a[i] << " ";
    }
    return 0;
}