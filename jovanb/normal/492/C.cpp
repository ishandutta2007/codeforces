#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

pair <ll, ll> niz[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    ll r;
    ll avg;
    cin >> n >> r >> avg;
    avg *= n;
    ll res=0;
    for(int i=1; i<=n; i++){
        cin >> niz[i].second >> niz[i].first;
        avg -= niz[i].second;
    }
    sort(niz+1, niz+1+n);
    for(int i=1; i<=n; i++){
        ll moze = max(0LL, min(r-niz[i].second, avg));
        avg -= moze;
        res += moze*niz[i].first;
    }
    cout << res;
    return 0;
}