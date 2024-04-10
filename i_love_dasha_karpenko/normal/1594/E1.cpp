//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("funroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MOD = 1e9+7;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k;
    cin>>k;
    ll ans = 1;
    for(int lev = 2;lev<=k;++lev){
        ans = ans*4*ans%MOD*4%MOD;
    }
    cout<<ans*6%MOD<<endl;
    return 0;
}