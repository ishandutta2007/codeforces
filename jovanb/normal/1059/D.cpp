#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld ml = 0.00000001;

int n;

ld x[100005];
ld y[100005];

bool resi(ld r){
    ld levo = -60000000000000LL;
    ld desno = 60000000000000LL;
    for(int i=1; i<=n; i++){
        if(2*r < y[i]) return 0;
        ld xx = sqrtl((2*r-y[i])*(y[i]));
        levo = max(levo, x[i]-xx);
        desno = min(desno, x[i]+xx);
    }
    return levo <= desno;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    int poz = 0, neg = 0;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
        if(y[i] > 0) poz = 1;
        else neg = 1;
    }
    if(poz && neg){cout << -1; return 0;}
    for(int i=1; i<=n; i++){
        y[i] = abs(y[i]);
    }
    ld l = 0, r = 60000000000000LL, res=60000000000000LL;
    int cnt=500;
    while(cnt-- && l <= r){
        ld mid = (l+r)/2;
        if(resi(mid)){
            r = mid-ml;
            res = mid;
        }
        else l = mid+ml;
    }
    cout << res;
    return 0;
}