#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)998244353;
const LL NS = (LL)2e5 + 4;
LL N;
LL zeg[NS];
LL d[NS];

pair<LL, LL> ext_euc(LL a, LL b){
    if(b == 0) return make_pair(a, b);
    pair<LL, LL> gap = ext_euc(b, a % b);
    return make_pair(gap.second, gap.first - (a / b) * gap.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    zeg[0] = 1;
    zeg[1] = 1 * (ext_euc(MOD, 2).second + MOD) % MOD;
    for(LL i = 2; i < NS; ++i){
        zeg[i] = zeg[i - 1] * zeg[1] % MOD;
    }
    d[1] = zeg[1], d[2] = (zeg[1] * zeg[1]) % MOD;
    for(int i =3; i <= N; ++i){
        d[i] = (d[i - 1] * zeg[1] % MOD + d[i - 2] * zeg[2]) % MOD;
    }
    cout << d[N];
    return 0;
}