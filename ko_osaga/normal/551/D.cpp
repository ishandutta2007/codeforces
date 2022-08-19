#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lint;

lint n, k, l, m;

struct mat{
    lint a[2][2];
    void init(){
        memset(a,0,sizeof(a));
    }
};

mat operator*(mat a, mat b){
    mat c;
    c.init();
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++) {
                c.a[i][j] += a.a[i][k] * b.a[k][j] % m;
                c.a[i][j] %= m;
            }
        }
    }
    return c;
}

lint pw(lint t){
    lint ret = 1, piv = 2;
    while (t) {
        if(t&1) ret = (ret * piv) % m;
        piv = (piv * piv) % m;
        t >>= 1;
    }
    return ret;
}

lint solve(lint t){
    mat ret, piv;
    ret.init();
    piv.init();
    ret.a[0][0] = ret.a[1][1] = 1;
    piv.a[0][1] = piv.a[1][0] = piv.a[1][1] = 1;
    while (t) {
        if(t&1) ret = (ret * piv);
        piv = (piv * piv);
        t >>= 1;
    }
    lint res = ret.a[0][0] + ret.a[0][1] + ret.a[1][0] + ret.a[1][1];
    return res % m;
}

int main(){
    scanf("%lld %lld %lld %lld",&n,&k,&l,&m);
    for (int i=(int)l; i<64; i++) {
        if((k >> i) & 1){
            puts("0");
            return 0;
        }
    }
    lint zero_val = solve(n-1);
    lint one_val = (pw(n) - zero_val + m) % m;
    lint ret = 1 % m;
    for (int i=0; i<l; i++) {
        if((k >> i) & 1) ret *= one_val;
        else ret *= zero_val;
        ret %= m;
    }
    printf("%lld",ret);
}