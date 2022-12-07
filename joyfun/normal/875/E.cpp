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
int n , x[N];

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
int _Max(int a,int b){
    return max(a , b);
}
int _Min(int a,int b){
    return min(a , b);
}
ST Max , Min;

int main(){
    scanf("%d%d%d",&n,x,x+1);
    n+=2;
    rep(i,2,n) scanf("%d",x+i);
    Max.Build(x,n,_Max);
    Min.Build(x,n,_Min);
    int l = abs(x[0] - x[1]) - 1, r = *max_element(x , x + n) - *min_element(x , x + n);
    while(l + 1 < r){
        int m=(l+r)>>1;
        int rightmost = 0;
        rep(i,0,n) {
            if(rightmost < i) break;
            int s = max(1 , i);
            int left = s , right = n;
            while(left + 1 < right){
                int mid = (left + right) >> 1;
                if(Max.query(s+1,mid)<=x[i]+m && Min.query(s+1,mid)>=x[i]-m)
                    left = mid;
                else right = mid;
            }
            rightmost = max(rightmost , left);
        }
        if(rightmost == n - 1) r = m;
        else l = m;
    }
    printf("%d\n",r);
    return 0;
}