#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int vert[1000005];
int niz[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> vert[i];
    sort(vert+1, vert+1+n);
    int tm=0;
    for(int i=1; i<=m; i++){
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if(x1 == 1){
            niz[++tm] = x2;
        }
    }
    m = tm;
    sort(niz+1, niz+1+m);
    vert[++n] = 1000000000;
    int res=n+m;
    for(int i=0; i<n; i++){
        int lim = vert[i+1];
        int l=1, r=m, mx = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(lim > niz[mid]){l = mid+1; mx = mid;}
            else r = mid-1;
        }
        res = min(res, i+m-mx);
    }
    cout << res;
    return 0;
}