#include<iostream>
#include<set>
#include<algorithm>
#include<cstring>
#include<map>
#include<tuple>
#include<cassert>
#include<cstring>
#include<vector>
#include<bitset>
#include<queue>
#include<deque>
#include<cmath>
#define inf 1e8
#define eps 1e-9
#define maxm 100005
#define maxn 300005
#define ls (tot << 1)
#define rs (tot << 1 | 1)
#define PII pair<int, int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const double pi = acos(-1);
const ll mod = 998244353;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

void init(){}

int qpow(int a, int b){
    int ans = 1, base = a;
    while(b){
        if(b & 1) ans = 1ll * ans * base % mod;
        base = 1ll * base * base % mod;
        b >>= 1;
    }
    return ans;
}

int app[15], b[150], d[150], mx[15];

void solve(){
    int n = read();
memset(app, 0, sizeof(app));
    memset(mx, 0, sizeof(mx));
    for(int i = 1; i <= n; i++){
        b[i] = read(), d[i] = read();
        app[d[i]] = 1;
    }
    bool f = 0;
    for(int i = 1; i <= 10; i++) if(!app[i]) f |= 1;
    if(f) puts("MOREPROBLEMS");
    else{
        for(int i = 1; i <= n; i++){
            mx[d[i]] = max(mx[d[i]], b[i]);
        }
        int ans = 0;
        for(int i = 1; i <= 10; i++) ans += mx[i];
        printf("%d\n", ans);
    }
}

int main(){
    init();
    int t = read(), cnt = 0;
    while(t--) {
        solve();
    }
    return 0;
}

/*

*/