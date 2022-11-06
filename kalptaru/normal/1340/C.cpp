
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 #define int long long

#define all(X) (X).begin(), (X).end()
#define reset(X) memset(X, 0, sizeof(X))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define fi first
#define se second

 
 
using namespace __gnu_pbds;
using namespace std;
 const int mod=1e9+7;
 // const int mod=998244353;
 // const int mod=1e9+9;
const int INF=4e18+10;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define read(n) int n; cin>>n;
#define readv(x, n) vector<int> x(n); for(auto &i:x) cin>>i; 
int multiply(int a, int b, int in_mod){return (a*b)%in_mod;} 
int mult_identity(int a){return 1;}


auto power(auto a, int b, int in_mod)
{
    auto prod=mult_identity(a);
    auto mult=a%in_mod;
    while(b!=0)
    {
        if(b%2)
        {
            prod=multiply(prod,mult, in_mod);

        }
        mult=multiply(mult, mult,in_mod);
        b/=2;
    }
    return prod;
}
int mod_inv(int q, int in_mod)
{

    return power(q, in_mod-2,in_mod);
}

const int MAXM=1e3+10;
const int MAXN=1e4+10;
vector<vector<int>>  dp(MAXN, vector<int> (MAXM, INF));

void solve()
{
    int n, m;
    cin>>n>>m;
    readv(d,m);
    sort(all(d));

    int g, r;
    cin>>g>>r;
    dp[0][0]=0;

    // to reach dp[n]
    //bfs 
    deque<pair<int, int> > q;
    q.push_back(make_pair(0,0));
    while(!q.empty())
    {
        auto t= q.front();
        q.pop_front();
        //go ahedad and back
        for(int i=t.fi -1 ;i<=t.fi+1;i+=2)
        {
            if(i<0 || i>m-1)
                continue;
            int dist = abs(d[i]-d[t.fi]);
            int total = dist + t.se;
            if(total<g && dp[i][total]>dp[t.fi][t.se])
            {
                dp[i][total]=dp[t.fi][t.se];
                q.push_front({i,total}); 
            }
            else if(total==g&& dp[i][0]>dp[t.fi][t.se]+1)
            {
                dp[i][0]= dp[t.fi][t.se]+1;
                q.push_back({i, 0});
            }
        }
    }
    int mn=INF;
    for(int i=0;i<g;i++)
    {
        if(dp[m-1][i]<INF)
        mn= min(mn, dp[m-1][i]*(g+r) + i  + (i==0?-r:0));
    }
    if(mn==INF)
        mn=-1;
    cout<<mn<<endl;

}

 
 
signed main()
 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        if(fopen("INPUT.txt","r"))
        {
            freopen ("INPUT.txt" , "r" , stdin);
            freopen ("OUTPUT.txt" , "w" , stdout);
        }
    #endif
    auto clk=clock(); 
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // -------------------------------------Code starts here---------------------------------------------------------------------     
 
    int t=1;
    // cin>>t;
    for(int test=1;test<=t;test++)
    {
        // cout<<"Case #"<<test<<": ";
        solve();
        // cout<<endl;
 
    }
 
    // -------------------------------------Code ends here------------------------------------------------------------------
 
 
    clk = clock() - clk;
    cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
 }