#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 50505;
int n , m , u , v , a[N] , b[N];
vi g[N] , has[N];
int id[N];
int col[1000010];
set<int> S , T;

int main(){
    srand(777777);
    scanf("%d%d",&n,&m);
    rep(i,0,m){
        scanf("%d%d",&u,&v);
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    rep(i,0,n) a[i] = i;
    int Max = 0;
    rep(i,0,n){
        int TT;
        scanf("%d",&TT);
        rep(j,0,TT){
            scanf("%d",&u);
            Max = max(Max , u);
            has[i].pb(u);
        }
    }
    random_shuffle(a , a + n);
    rep(i,0,n){
        int u = a[i] , A = 0 , B = 0;
        for(auto e : g[u]){
            if(S.find(e) != S.end()) A++;
            if(T.find(e) != T.end()) B++;
        }
        if(A >= B) T.insert(u) , id[u] = 1;
        else S.insert(u) , id[u] = 0;
    }
    random_shuffle(a , a + n);
    S.clear();T.clear();
    rep(i,0,n){
        int u = a[i];
        random_shuffle(all(has[u]));
        if(id[u] == 0){
            bool fd = false;
            for(auto e : has[u]) if(S.find(e) != S.end()){
                b[u] = e;col[e] = 1;fd = true;break;
            }
            if(!fd) for(auto e : has[u]) if(T.find(e) == T.end()){
                b[u] = e;col[e] = 1;break;
            }
            S.insert(b[u]);
        } else {
            bool fd = false;
            for(auto e : has[u]) if(T.find(e) != T.end()){
                b[u] = e;col[e] = 2;fd = true;break;
            }
            if(!fd) for(auto e : has[u]) if(S.find(e) == S.end()){
                b[u] = e;col[e] = 2;break;
            }
            T.insert(b[u]);
        }
    }
    rep(i,0,n) printf("%d%c",b[i]," \n"[i+1==n]);
    rep(i,1,Max+1) printf("%d%c",col[i] == 2 ? 2 : 1 , " \n"[i==Max]);
    return 0;
}