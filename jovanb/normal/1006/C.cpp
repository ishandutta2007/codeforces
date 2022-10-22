#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[300005];
ll pre[300005];
map <ll, int> poz;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        pre[i] = niz[i]+pre[i-1];
    }
    ll x = 0;
    for(int i=n; i>=1; i--){
        x = x+niz[i];
        poz[x] = i;
    }
    ll maxres=0;
    for(int i=1; i<=n; i++){
        if(poz[pre[i]] > i) maxres = pre[i];
    }
    cout << maxres;
    return 0;
}