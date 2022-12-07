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

const int P = 1e9 + 7; // P is prime
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
int inv(int x){return x==1?x:P-ll(P/x)*inv(P%x)%P;}
void FWT(int *a,int len,int o){ // o : 1(+) , -1(-)
    int inv2=inv(2);
    for(int k=0;1<<k<len;++k) rep(i,0,len) if(~i>>k&1){
        int j=i^(1<<k),x,y;
        x=(a[i]+a[j])%P , y=(a[i]-a[j]+P)%P; // xor
        if(o==-1) x=ll(x)*inv2%P , y=ll(y)*inv2%P;
        a[i]=x,a[j]=y;
    }
}
const int N = 1 << 20;
int n , f[N] , pw2[22]={1};
char s[N + 10];
int main(){
    rep(i,1,22) pw2[i]=pw2[i-1]*2;
    scanf("%d%s",&n,s);
    rep(i,0,1<<n) f[i] = s[i] == '1';
    FWT(f,1<<n,1);
    rep(i,0,1<<n) f[i]=1ll*f[i]*f[i]%P;
    FWT(f,1<<n,-1);
    int ans=0;
    rep(i,0,1<<n) pp(ans,3ll*f[i]*pw2[n-__builtin_popcount(i)]%P);
    printf("%d\n",ans);
    return 0;
}