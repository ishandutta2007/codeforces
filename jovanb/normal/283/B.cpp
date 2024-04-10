#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[200005];
ll n;
ll resenje[200005];

ll res(int x){
    if(x <= 0 || x > n) return 0;
    if(resenje[x] != -2) return resenje[x];
    resenje[x] = -1;
    int x1 = x+niz[x];
    if (x1 > n) return resenje[x] = niz[x];
    int x2 = x1-niz[x1];
    ll res1 = res(x2);
    if (res1 >= 0) return resenje[x] = niz[x]+niz[x1]+res1;
    return resenje[x] = -1;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<=n; i++) resenje[i] = -2;
    for(int i=2; i<=n; i++) cin >> niz[i];
    for(int i=1; i<n; i++){
        niz[1] = i;
        resenje[1] = -2;
        cout << res(1) << "\n";
    }
    return 0;
}