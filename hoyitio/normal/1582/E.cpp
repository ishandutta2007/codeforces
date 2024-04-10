#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e5+5;
const int B = 605;
ll dp[maxn][B];
int n;
ll a[maxn]; ll s[maxn];
void init(){
    scanf("%d", &n);
    fors(i,1,n+1) {
        scanf("%lld", &a[i]);
    }
    fors(i,0,n+1) fors(j,0,B) dp[i][j] = -1;
    reverse(a+1, a+1+n);
    fors(i,1,n+1) s[i] = a[i]+s[i-1];
}
const ll inf = 0x3f3f3f3f3f3f3f3f;
void sol(){
    dp[0][0] = inf;
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        fors(j,0,B) dp[i][j] = dp[i-1][j];
        for(int j = 1; j < min(B,i+1); ++j){
            ll cur = s[i]-s[i-j];
            if(dp[i-j][j-1] > cur) dp[i][j] = max(dp[i][j], cur);
            if(dp[i][j] != -1) ans = max(ans, j);
//            cout<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<" cur:"<<cur<<endl;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T; cin>>T;
    while(T--){
        init();
        sol();
    }
    return 0;
}