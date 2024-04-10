#include<bits/stdc++.h>
#define maxn 5005
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,dp[maxn],one[maxn],two[maxn],res_one,res_two,ans,zero;
ii a[maxn];

ii its(ii x,ii y){
    ii z = ii{n+1,n+1};
    if( x.s > y.s ) swap(x,y);
    z.f = max(x.f,y.f);
    z.s = min(x.s,y.s);
    if( z.f > z.s ) return ii{n+2,n+2};
    return z;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        cin >> a[i].f >> a[i].s;
        dp[a[i].f]++;
        dp[a[i].s+1]--;
    }

    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1] + dp[i];
        zero += ( dp[i] == 0 );
        one[i] = one[i-1] + ( dp[i] == 1 );
        two[i] = two[i-1] + ( dp[i] == 2 );
    }

    for(int i=1; i<=m; i++)
        for(int j=i+1; j<=m; j++){
            res_one = one[a[i].s] - one[a[i].f-1] + one[a[j].s] - one[a[j].f-1];
            int l1 = a[i].f, l2 = a[j].f , r1 = a[i].s , r2 = a[j].s;

            ii inter = its(a[i],a[j]);
            res_two = two[inter.s] - two[inter.f-1];
            res_one -= one[inter.s] - one[inter.f-1];

            ans = max( ans , n - zero - res_one - res_two );
        }

    cout << ans;

    return 0;
}