#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, l, r;
    cin >> n >> l >> r;
    ll res = 0;
    for(int i=0; i<l; i++){
        res += (1LL << i);
        n--;
    }
    cout << res+n << " ";
    for(int i=l; i<r; i++){
        res += (1LL << i);
        n--;
    }
    cout << res+(1LL<<(r-1))*n << " ";
    return 0;
}