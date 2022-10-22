#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


ll niz[500005];


int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll sum1=0;
    ll sum2=0;
    ll mn=1000000000;
    ll mx=-1000000000;
    bool ima1=0, ima2=0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        if(niz[i] == 0){
            ima1=1;
            ima2=1;
        }
        else if(niz[i] < 0){
            mx = max(mx, niz[i]);
            sum1 += niz[i];
            ima1=1;
        }
        else{
            mn = min(mn, niz[i]);
            sum2 += niz[i];
            ima2=1;
        }
    }
    if(n == 1){cout << niz[1]; return 0;}
    if(!ima1){
        cout << sum2-2*mn;
    }
    else if(!ima2){
        cout << 2*mx-sum1;
    }
    else cout << sum2-sum1;
    return 0;
}