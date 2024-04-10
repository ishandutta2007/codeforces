#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

map <int, bool> ima;
map <int, bool> ima2;
int niz[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    int res = n-1;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<=n; i++){
        if(ima[niz[i]]) break;
        ima[niz[i]] = 1;
        ima2 = ima;
        res = min(res, n-i);
        for(int j=n; j>i; j--){
            if(ima2[niz[j]]) break;
            ima2[niz[j]] = 1;
            res = min(res, j-1-i);
        }
    }
    ima.clear();
    for(int i=n; i>=1; i--){
        if(ima[niz[i]]) break;
        ima[niz[i]] = 1;
        res = min(res, i-1);
    }
    cout << res;
    return 0;
}