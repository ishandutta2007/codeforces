#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;
const ll MOD = 1E9+7;
const ll SZ = 10;
const ll LOG = 32;
ll cur[SZ][DIM];
ll mas[SZ][DIM][SZ];
ll solve(ll num,ll steps){
    return cur[num][steps];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(ll cl = 1;cl<DIM;++cl){
        for(ll num = 0;num<SZ;++num){
            if (cl==1){
                if (num<9)
                    mas[num][cl][num+1] = 1;
                else
                    mas[num][cl][0] = mas[num][cl][1] = 1;

            }
            else
                for(ll snum1 = 0;snum1<SZ;++snum1){
                    if (snum1<9){
                        mas[num][cl][snum1+1] = (mas[num][cl][snum1+1]+mas[num][cl-1][snum1])%MOD;
                    }
                    else{
                        mas[num][cl][0] = (mas[num][cl][0]+mas[num][cl-1][snum1])%MOD;
                        mas[num][cl][1] = (mas[num][cl][1]+mas[num][cl-1][snum1])%MOD;
                    }
                }
            for(ll snum1 = 0;snum1<SZ;++snum1){
                cur[num][cl] = (cur[num][cl]+mas[num][cl][snum1])%MOD;
            }
        }
    }
    ll t;
    scanf("%lld",&t);
    while(t--){

        ll n,m;
        scanf("%lld%lld",&n,&m);
        ll res = 0;
        while(n){
            res = (res+solve(n%10,m))%MOD;
            n/=10;
        }

        printf("%lld\n",res);
    }
    return 0;
}