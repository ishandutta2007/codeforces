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
const int maxn = 1e5+5, base = 1e9+7;
const int C = 2002;
ll dp[2002][2002];
    string s;
    int n,m;
int main()
{
    //files1;
   // //files2;
   //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    cin >> n >>m ;

    cin >>s;

    int balance = 0;

    int mn = 0;
    for (int i=0;i<s.length();i++){
        if (s[i] == ')')
            balance--;
        else
            balance++;
        mn  = min(mn,balance);
    }

    dp[1][1] = 1;
    dp[0][0] = 1;
    for (int len=1;len<2001;len++)
    for (int blc = 0;blc<2001;blc++){
        dp[len][blc] %= base;
        dp[len+1][blc+1] += dp[len][blc];
        if (blc!=0){
                dp[len+1][blc-1] += dp[len][blc];
    }
    }
   // cerr<<dp[2][0];
    ll ans = 0;
    if (mn < 0)
        mn*=-1;
    for (int lenp = 0;lenp<=n-m;lenp++){

        for (int blc = mn;blc < 2001;blc++){
            int lenq = n - m - lenp;
            int blq = blc + balance;

            if (blq < 0)
                blq *= -1;
             if (blq >= 2001)
                 continue;
         /*  if (dp[lenp][blc] * dp[lenq][blq] != 0)
               {
                   cerr<<"Lenp="<<lenp<<" Lenq= "<<lenq<<endl;
                   cerr<<"Blp= "<<blc<< " Blq= "<<-blq<<endl;
                   cerr<<"+ "<<dp[lenp][blc] * dp[lenq][blq]<<endl<<endl;
               }*/
            ans += (dp[lenp][blc] * dp[lenq][blq]);
            ans%=base;
        }
    }

    printf("%I64d\n",ans);
    //exit(0);
   // return 0;
}