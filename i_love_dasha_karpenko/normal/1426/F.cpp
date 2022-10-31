#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll MOD = 1E9+7;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll cnt[] = {1,0,0,0};
    for(ll i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        if (ch=='a'){
            cnt[1]=(cnt[1]+cnt[0])%MOD;
        }
        if (ch=='b'){
            cnt[2]=(cnt[2]+cnt[1])%MOD;
        }
        if (ch=='c'){
            cnt[3] = (cnt[3]+cnt[2])%MOD;
        }
        if (ch=='?'){
            cnt[3] = (cnt[3]*3)%MOD;
            cnt[3] = (cnt[3]+cnt[2])%MOD;
            cnt[2] = (cnt[2]*3)%MOD;
            cnt[2]=(cnt[2]+cnt[1])%MOD;
            cnt[1] = (cnt[1]*3)%MOD;
            cnt[1] = (cnt[1]+cnt[0])%MOD;
            cnt[0] = (cnt[0]*3)%MOD;
        }
    }
    cout<<cnt[3]<<endl;
    return 0;

}