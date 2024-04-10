#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define lowbit(x) (x&(-(x)))
#define all(x) x.begin(),x.end()
using namespace std;
const int maxn = 1e5+5;
int a[maxn], n;
void init(){
    scanf("%d", &n);
    fors(i,1,n+1) scanf("%d", &a[i]);
}
const int mod = 998244353;
void sol(){
    #define P pair<int,int>
    vector<P> f, g; f.clear(); g.clear();
    f.pb(P(1,0));
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        g.clear();
        for(int l = 1, r; l <= a[i]; l = r+1){
            int d = a[i]/l;
            r = a[i]/d;
            //t-1 is ex
            int v1 = d, v2 = d;
            if(a[i]%l) v2++;
            int pos = upper_bound(all(f), P(v1, mod+1))-f.begin(); pos--;
            int cur = ((ll)(l-1)*i%mod + f[pos].second)%mod;
            g.pb(P(v2, cur));
            if(l < r && a[i]%r == 0){
                int v = a[i]/r;
                pos = upper_bound(all(f), P(v, mod+1))-f.begin(); pos--;
                cur = ((ll)(r-1)*i%mod + f[pos].second)%mod;
                g.pb(P(v, cur));
            }

            if(l == 1) {
                ans = (ans + cur)%mod;
            }
        }
        reverse(all(g));
        f.swap(g);

    }
    printf("%d\n", ans);
}
int main(){

    int T; cin>>T;
    while(T--){
        init();
        sol();
    }
    return 0;
}