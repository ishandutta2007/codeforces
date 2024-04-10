//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
#define endl '\n'
const ll DIM = 1E6+7;
ll F[DIM],cnt[DIM][10];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(ll i = 1;i<DIM;++i){
        ll num = 0;
        if (i<10){
            num = i;
        }
        else{
            ll mult = 1;
            ll x = i;
            while(x){
                if (x%10)
                    mult*=x%10;
                x/=10;
            }
            num = F[mult];
        }
        F[i] = num;
        for(ll j = 1;j<10;++j)
            cnt[i][j] = cnt[i-1][j];
        cnt[i][num]++;
    }
    ll q;
    cin>>q;
    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        cout<<cnt[r][k]-cnt[l-1][k]<<endl;
    }

    return 0;
}