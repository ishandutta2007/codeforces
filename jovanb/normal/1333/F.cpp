#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int mndiv[500005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    mndiv[1] = 1;
    for(int j=2; j<=n; j++){
        if(mndiv[j]) continue;
        mndiv[j] = j;
        for(ll i=1LL*j*j; i<=n; i+=j){
            if(!mndiv[i]) mndiv[i] = j;
        }
    }
    for(int i=1; i<=n; i++){
        mndiv[i] = i/mndiv[i];
    }
    sort(mndiv+1, mndiv+1+n);
    for(int i=2; i<=n; i++) cout << mndiv[i] << " ";
    return 0;
}