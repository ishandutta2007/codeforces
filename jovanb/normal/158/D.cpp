#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[100005];

int res;

int n;

void prb(int x){
    for(int j=1; j<=x; j++){
        int tren = 0;
        for(int i=j; i<=n; i+=x){
            tren += niz[i];
        }
        res = max(res, tren);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        res += niz[i];
    }
    for(int x=1; x*x<=n; x++){
        if(n%x == 0){
            if(n/x >= 3) prb(x);
            if(x >= 3) prb(n/x);
        }
    }
    cout << res;
    return 0;
}