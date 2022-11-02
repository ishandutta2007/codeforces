#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

struct mat {
    ll val[3][3];
    mat operator * (const mat &X) {
        mat tmp;
        for(int i=0;i<3;i++) {
            for(int j=i;j<3;j++) {
                tmp.val[i][j] = 0;
                for(int k=0;k<3;k++) {
                    tmp.val[i][j] += val[i][k] * X.val[k][j];
                }
                tmp.val[i][j] %= mod;
                tmp.val[j][i] = tmp.val[i][j];
            }
        }
        return tmp;
    }
}cur, def;

ll calc (ll X, ll Y) {
    if(!Y) return 1;
    ll ret = calc(X, Y/2);
    ret = (ret * ret) % mod;
    if(Y%2) ret = (ret*X) % mod;
    return ret;
}

int main()
{
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cur.val[i][j] = 1;
        }
        cur.val[i][2-i] = 0;
    }
    ll q, minv = calc(2, mod-2);
    scanf("%lld",&q);
    while(q--) {
        ll tmp;
        scanf("%lld",&tmp);
        tmp %= (mod-1);
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                def.val[i][j] = cur.val[i][j];
                cur.val[i][j] = (i==j);
            }
        }
        ll x = 1;
        while(2*x<=tmp) x *= 2;
        while(x) {
            cur = cur*cur;
            if(x&tmp) cur = cur*def;
            x>>=1;
        }
    }
    printf("%lld/%lld\n",(cur.val[1][1]*minv)%mod, ((cur.val[0][1]+cur.val[1][1]+cur.val[2][1])*minv)%mod);
}