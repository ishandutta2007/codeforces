#include <cstdio>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include <unistd.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pii pair < int, int >
#define x first
#define y second
#define pb push_back
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int Mod = 1000000007;
class mint{
public:
    int x;
    mint(ll y = 0){
        y %= Mod;
        if (y < 0) y += Mod;
        x = y;
    }
};
mint operator+(mint a, mint b){return mint(a.x + b.x);}
mint operator-(mint a, mint b){return mint(a.x - b.x);}
mint operator*(mint a, mint b){return mint((ll)a.x * b.x);}
void operator+=(mint &a, mint b){a = a + b;}
void operator*=(mint &a, mint b){a = a * b;}

mint fact[200006];
mint inv[200006];

mint pow(mint a, int x){
    mint r = 1;
    while (x){
        if (x & 1) r *= a;
        a *= a;
        x /= 2;
    } return r;
}

mint choose(int a, int b){
    return fact[a] * inv[b] * inv[a - b];
}

int h, w, n;
pii in[2005];

vector < pair < int, mint > > E[2005];
mint val(int a, int b){
    return choose(in[b].x + in[b].y - in[a].x - in[a].y, in[b].x - in[a].x);
}

int Cnt[2005];
pair < mint, mint > st[2005];

int main(){
    fact[0] = 1;
    REP(200005,i) fact[i+1] = fact[i] * (i+1);
    REP(200005,i) inv[i] = pow(fact[i], Mod - 2);

    scanf("%d%d%d", &h, &w, &n);
    REP(n,i) scanf("%d%d", &in[i].x, &in[i].y);
    in[n++] = {1, 1};
    in[n++] = {h, w};
    REP(n,i) REP(n,j) if (i != j){
        if (in[i].x > in[j].x || in[i].y > in[j].y) continue;
        E[i].pb({j, val(i, j)});
    }
    REP(n,i) for (auto x : E[i]) ++Cnt[x.x];
    //REP(n,i) TRACE(Cnt[i]);
    queue < int > Q;
    Q.push(n-2);
    st[n-2] = {1, 0};
    while (!Q.empty()){
        int id = Q.front(); Q.pop();
        auto t = st[id];
        swap(t.x, t.y);
        for (auto x : E[id]){
            st[x.x].x += x.y * t.x;
            st[x.x].y += x.y * t.y;
            if (--Cnt[x.x] == 0) Q.push(x.x);
        }
    } printf("%d\n", (st[n-1].y - st[n-1].x).x);
    return 0;
}