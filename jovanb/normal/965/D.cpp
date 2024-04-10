#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll br[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll l, w;
    cin >> w >> l;
    for(int i=1; i<w; i++){
        cin >> br[i];
        br[i] += br[i-1];
    }
    ll maxres = 1000000000000;
    for(int i=l; i<w; i++){
        maxres = min(maxres, br[i]-br[i-l]);
    }
    cout << maxres;
    return 0;
}