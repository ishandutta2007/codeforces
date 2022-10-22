#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
ll h[maxn];
int n; ll k;
const ll inf = 0x3f3f3f3f3f3f3f3f;
void init(){
    scanf("%d%lld", &n, &k);
    fors(i,1,n+1) scanf("%lld", &h[i]);
}
bool sol(){
    ll l, r;
    l = r = h[1] + k;
    fors(i,2,n+1){
        ll tl = max(l-k+1, h[i]+k);
        ll tr = min(r+k-1, h[i]+2*k-1);
        if(tl > tr) return false;
        l = tl; r = tr;
    }
    if(h[n]+k <= r && h[n]+k >= l)return true;
    else return false;
}
int main()
{
    int T; cin>>T;
    while(T--){
        init();
        if(sol()) printf("YES\n");
        else printf("NO\n");
    }
}