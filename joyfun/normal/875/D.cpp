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

const int N = 2e5 + 10;
int n , a[N];

struct ST{
    int a[20][N] , lg[N] , (*f)(int,int);
    void Build(int *v,int n,int (*_f)(int,int)){
        f = _f;rep(i,0,n) a[0][i] = v[i];
        rep(i,2,n+1) lg[i] = lg[i>>1]+1;
        rep(i,1,lg[n]+1) rep(j,0,n-(1<<i)+1) a[i][j]=f(a[i-1][j],a[i-1][j+(1<<i>>1)]);
    }
    int query(int x,int y){
        if(x>y) swap(x,y);
        int i=lg[y-x+1];
        return f(a[i][x] , a[i][y+1-(1<<i)]);
    }
};
ST Max , Or;
int _Max(int a,int b){
    return max(a,b);
}
int _Or(int a,int b){
    return a | b;
}

int main(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",a + i);
    Max.Build(a,n,_Max);
    Or.Build(a,n,_Or);
    ll ans = 0;
    rep(r,0,n) {
        int l=r;
        while(l>=0){
            int left = -1 , right = l;
            while(left + 1 < right){
                int mid = (left + right) >> 1;
                if(Or.query(mid , r) == Or.query(l , r)) right = mid;
                else left = mid;
            }
            int need = Or.query(l , r);
            int sl = right , sr = l;
            left = sl - 1 , right = sr + 1;
            while(left + 1 < right) {
                int mid = (left + right) >> 1;
                if(Max.query(mid , r) >= need) left = mid;
                else right = mid;
            }
            ans += max(0 , sr - right + 1);
            l = sl - 1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}