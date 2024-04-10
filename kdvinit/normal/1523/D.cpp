/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int r)      //returns random number between [0 to r-1]
{
   uniform_int_distribution<int> uid(0,r-1);
   return uid(rng);
}

int mx_cnt=0;
string ans;

const int N = 2e5 + 1;
int n, m, p;
int bit[N][61];

void check(int ind)
{
    //Find on positions in bit[i]
    vector<int> pos;
    for(int j=1; j<=m; j++)
    {
        if(bit[ind][j]==1) pos.push_back(j);
    }
    int mp2 = pos.size();
    int mx2 = (1<<mp2);

    if(mp2<=mx_cnt) return;
    int dp[mx2]={0};


    //Initialise_DP(pos, dp);
    for(int i=1; i<=n; i++)
    {
        int mask = 0;
        for(int j=0; j<mp2; j++) if(bit[i][pos[j]]==1) mask|=(1<<j);
        dp[mask]++;
    }


    //SOS_DP(dp, mp2);
    int p2=1;   //power of 2
    //int mp2 = max_number of bits;
    //int mx2 = 1<<mp2;
    for(int i=0; i<mp2; i++)
    {
        //p2 = 1<<i;
       for(int mask=0; mask<mx2; mask++)
       {
           if(mask & p2) dp[mask ^ p2] += dp[mask];
       }
       p2*=2;
    }


    //bm_mx(dp, mx2)
    int cur_bm = 0;
    int cur_cnt = 0;
    for(int i=0; i<mx2; i++)
    {
        if(dp[i]>=(n+1)/2)
        {
            int tmp = __builtin_popcount(i);
            if(tmp>cur_cnt) { cur_cnt=tmp; cur_bm=i; }
        }
    }
    int bm = cur_bm;
    if(cur_cnt<=mx_cnt) return;


    //Change Answer if more optimal
    mx_cnt = cur_cnt;
    ans.clear(); ans.assign(m, '0');
    for(int j=0; j<mp2; j++)
    {
        if(bm&(1<<j)) ans[pos[j]-1]='1';
    }
}

void solve()
{
    cin>>n>>m>>p;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            bit[i][j] = x-'0';
        }
    }

    ans.clear();
    ans.assign(m, '0');
    for(int i=1; i<=10; i++)
    {
        int x = getRand(n) + 1;
        check(x);
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}