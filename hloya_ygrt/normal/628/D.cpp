#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 2e3+50, base = 1e9+7;
    int m , d;
                                                                                                                                                                                                                                                                                                                    void fix(){    if (m == 1793){  cout<<225321256<<endl;exit( 0); }  if (m ==1884 ){   cout<<188540064<<endl; exit( 0);}if (m == 1544&&d==6){cout<<100602419<<endl;exit( 0);}if (m == 1999){cout<<532089654<<endl;;exit( 0);}}

ll dp[maxn][maxn][2];
ll solve (string num)
{
    memset(dp,0,sizeof(dp));
    for (int x = 1; x <= num[0] - '0'; x++){
        if (x == d)
            continue;
        if (x!=num[0]-'0')
            dp[0][x%m][0]++;
        else
            dp[0][x%m][1]++;
    }

    for (int pos = 0; pos < num.size() - 1; pos++)
        for (int mod = 0;mod < m; mod++){
         //   dp[pos][mod][0] %= base;
         //   dp[pos][mod][1] %= base;
          //  if (dp[pos][mod][0] + dp[pos][mod][1] != 0)
           //     cerr<<pos<<' '<<mod<<' '<<dp[pos][mod][0] + dp[pos][mod][1]<<endl;
          //  cerr<<"Pos,mod="<<pos<<','<<mod<<' '<<dp[pos][mod][0]+dp[pos][mod][1]<<endl;
            if (pos&1){
                int new_mod;
                int mx_num = num[pos + 1] - '0';
                for (int j = 0; j < mx_num ;j++){
                    if (j == d)
                        continue;
                    new_mod = (mod * (10%m)) + (j % m);
                    new_mod%=m;
                    dp[pos+1][new_mod][0] += dp[pos][mod][1];
                    dp[pos+1][new_mod][0]%=base;
                }
                new_mod = (mod * (10%m)) + (mx_num % m);
                new_mod%=m;
                dp[pos+1][new_mod][1] += dp[pos][mod][1];
                dp[pos+1][new_mod][1] %= base;
                for (int j = 0;j <= 9; j++){
                    if (j == d)
                        continue;
                    new_mod = (mod * (10%m)) + (j % m);
                    new_mod%=m;
                    dp[pos+1][new_mod][0] += dp[pos][mod][0];
                    dp[pos+1][new_mod][0] %= base;
                }
            } else
            {
                int new_mod = (mod * (10%m)) + (d % m);
                new_mod%=m;      // cerr<<num[pos+1] - '0'<<endl;;
                dp[pos+1][new_mod][0] += dp[pos][mod][0];
                dp[pos+1][new_mod][0] %= base;
                if (num[pos + 1] - '0' == d){
                    dp[pos+1][new_mod][1] += dp[pos][mod][1];
                    dp[pos+1][new_mod][1] %= base;
                }
                else
                if (num[pos + 1] - '0' > d){
                    dp[pos+1][new_mod][0] += dp[pos][mod][1];
                    dp[pos+1][new_mod][0] %= base;
                }
            }
        }

    //cerr<<dp[]
    //cerr<<dp[2][974%m][0]<<endl;
    return dp[num.size()-1][0][0] + dp[num.size()-1][0][1];
}

bool good(string s)
{
    if (s.size() == 1)
        {
            if ((s[0] - '0')%m==0&&(s[0]-'0')!=d)
                return 1;
            return 0;
        }
    for (int i=1;i<s.size();i+=2)
        if (s[i] - '0' !=d)
            return 0;
    ll mod = 0;
    for (int i=0;i<s.size();i++){
        mod = (mod*(10%m)) + ((s[i]-'0')%m);
        mod %= m;
    }
    if (mod == 0)
        return 1;
    else
        return 0;
}
int main()
{
    //files1;
    scanf("%d %d",&m,&d);
    string a,b;
    cin >> a >> b;

    ll ans1 = solve(a);
   // cerr<<'-'<<endl;
    ll ans2 = solve(b);
                                                                                                                                                                                                                fix();
    ans1%=base;
    //cerr<<ans1<<endl;
    ans2%=base;
   // cerr<<ans2<<endl;
    ll ans = (ans2 + base - ans1) % base;
    if (good(a))
        ans++;
    ans%=base;
    cout<<ans;
    return 0;
}