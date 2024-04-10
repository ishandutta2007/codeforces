#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[3000];
int niz1[3000];
map <int, int> br;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        niz1[i] = niz[i];
    }
    sort(niz1+1, niz1+1+n);
    reverse(niz1+1, niz1+1+n);
    int zb=0;
    for(int i=1; i<=k; i++){
        br[niz1[i]]++;
        zb += niz1[i];
    }
    int cnt=0;
    cout << zb << "\n";
    int brs = k-1;
    if(brs == 0){
        cout << n;
        return 0;
    }
    for(int i=1; i<=n; i++){
        cnt++;
        if(br[niz[i]]){
            br[niz[i]]--;
            cout << cnt << " ";
            cnt = 0;
            brs--;
            if(brs <= 0){
                cout << n-i;
                return 0;
            }
        }
    }
    return 0;
}