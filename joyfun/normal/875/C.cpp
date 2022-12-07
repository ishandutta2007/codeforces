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

const int N = 1e5 + 10;
int n , m , tosmall[N];
vector<vi> V;
vi g[N];

int main(){
    scanf("%d%d",&n,&m);
    rep(i,0,n){
        int l;scanf("%d",&l);
        vi v(l , 0);
        rep(i,0,l) scanf("%d",&v[i]);
        V.pb(v);
    }
    bool err = false;
    rep(i,0,n-1){
        vi&a = V[i] , &b = V[i+1];
        int len = min(sz(a) , sz(b));
        int diff = false;
        rep(i,0,len){
            if(a[i] == b[i]) continue;
            if(a[i] > b[i]) {
                tosmall[a[i]] = true;
                diff = true;
                break;
            }
            if(a[i] < b[i]){
                g[b[i]].pb(a[i]);
                diff = true;
                break;
            }
        }
        if(!diff && sz(a) > sz(b)){
            err = true;
            break;
        }
    }
    if(err) puts("No");
    else {
        vi q;
        rep(i,1,m+1) if(tosmall[i]) q.pb(i);
        rep(i,0,sz(q)){
            int c=q[i];
            for(auto e : g[c]) if(!tosmall[e])
                tosmall[e] = true , q.pb(e);
        }
        rep(i,0,n-1){
            vi&a = V[i] , &b = V[i+1];
            int len = min(sz(a) , sz(b));
            rep(i,0,len){
                if(a[i] == b[i]) continue;
                if(a[i] > b[i]) {
                    if(tosmall[a[i]] && !tosmall[b[i]]);
                    else err = true;
                    break;
                }
                if(a[i] < b[i]){
                    if(tosmall[a[i]] >= tosmall[b[i]]);
                    else err = true;
                    break;
                }
            }
        }
        if(err) puts("No");
        else {
            puts("Yes");
            vi ans;
            rep(i,1,m+1) if(tosmall[i]) ans.pb(i);
            printf("%d\n",sz(ans));
            rep(i,0,sz(ans)) printf("%d%c",ans[i]," \n"[i+1==sz(ans)]);
        }
    }
    return 0;
}