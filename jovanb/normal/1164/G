#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int add(int a, int b){
    return (a+b+MOD)%MOD;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int dp[500005];

struct polje{
    int i, j;
    bool operator <(const polje &b){
        if(i < b.i) return 1;
        if(i > b.i) return 0;
        return j < b.j;
    }

} niz[2005];

int fact[500005];
int invfact[500005];

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int bin(int a, int b){
    int res = fact[a];
    int d1 = invfact[a-b];
    int d2 = invfact[b];
    res = mul(res, d1);
    res = mul(res, d2);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);

    fact[0] = 1;
    invfact[0] = 1;
    for(int i=1; i<=500000; i++){
        fact[i] = mul(i, fact[i-1]);
        invfact[i] = pw(fact[i], MOD-2);
    }
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i].i >> niz[i].j;
    }
    n++;
    niz[n].i = h;
    niz[n].j = w;
    sort(niz+1, niz+1+n);
    for(int i=1; i<=n; i++){
        dp[i] = bin(niz[i].i+niz[i].j-2, niz[i].i-1);
        for(int j=1; j<i; j++){
            if(niz[j].i <= niz[i].i && niz[j].j <= niz[i].j){
                dp[i] = add(dp[i], -mul(dp[j], bin(niz[i].i-niz[j].i+niz[i].j-niz[j].j, niz[i].j-niz[j].j)));
            }
        }
    }
    cout << dp[n];
    return 0;
}