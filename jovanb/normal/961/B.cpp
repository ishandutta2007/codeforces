#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pre[100005];
ll niz[100005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int k, n;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    ll x;
    ll ukup=0;
    for(int i=1; i<=n; i++){
        cin >> x;
        pre[i] = pre[i-1];
        if(x == 1) ukup += niz[i];
        else pre[i] += niz[i];
    }
    ll maxi=0;
    for(int i=k; i<=n; i++){
        maxi = max(maxi, pre[i]-pre[i-k]);
    }
    cout << maxi+ukup;
    return 0;
}