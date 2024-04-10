// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

int n;
map<int,vi> game;
map<int,int> vis;

int dfs(int mask){
    if(mask == 0) return 0;
    if(vis.count(mask)) return vis[mask];
    set<int> S;
    int top = 1;
    while((1 << top) <= mask) ++top;
    for(int j=0;j<top;++j){
        int nmask = 0;
        rep(k,0,j) if(mask>>k&1) nmask |= 1 << k;
        rep(k,j,top) if(mask>>k&1 && (k > j)) nmask |= 1 << (k - (j + 1));
        S.insert(dfs(nmask));
    }
    int&res=vis[mask];
    while(S.count(res)) ++res;
    return res;
}

int SG(vi v){
    int mask = 0;
    for(auto e : v) mask |= 1 << (e - 1);
    return dfs(mask);
}

int sg[100];
void test(){
    sg[0] = 0;
    rep(i,1,100){
        set<int> S;
        int top = 1;
        while((1 << top) <= i) ++top;
        for(int j=0;j<top;++j){
            int nmask = 0;
            rep(k,0,j) if(i>>k&1) nmask |= 1 << k;
            rep(k,j,top) if(i>>k&1 && (k > j)) nmask |= 1 << (k - (j + 1));
            S.insert(sg[nmask]);
        }
        int&res=sg[i];
        while(S.count(res)) ++res;
        cout << i << " " << res << endl;
    }
}

int main(){
    //test();
    scanf("%d",&n);
    rep(i,0,n){
        int x;
        scanf("%d",&x);
        for(int t=2;t*t<=x;++t) if(x%t==0){
            int times=0;while(x%t==0) times++,x/=t;
            game[t].pb(times);
        }
        if(x > 1) game[x].pb(1);
    }
    int sg = 0;
    for(auto e : game) sg ^= SG(e.se);
    puts(sg ? "Mojtaba" : "Arpa");
    return 0;
}