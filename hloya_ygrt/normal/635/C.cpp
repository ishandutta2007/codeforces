#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define pf push_front
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output1.txt","w",stdout)
#define mp make_pair
#define int long long
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 2e5+5, base = 1e9+7,maxm= 1e4+5;

int dp[50][2];

vector<int> get(int x)

{
    vector<int> ans;
    while(x)
    {
        ans.pb(x%2);
        x/=2;
    }

    return ans;
}
main()
{
    int n, x;
    cin >> n >> x;
    vector<int> sum = get(n);
    vector<int> xr = get(x);
    
    //int os = min(xr.size(),sum.size());
    while (sum.size() > xr.size())
        xr.pb(0);
    while (sum.size() < xr.size())
        sum.pb(0);
        int os = sum.size();
    // base
    if (sum[0] == 0 && xr[0] == 0){
        dp[1][1] = 1;
        dp[1][0] = 1;
    }
    if (sum[0] == 1 && xr[0] == 1){
        dp[1][0] = 2;
    }

    for (int i=1;i<sum.size();i++){
            for (int c1 = 0 ; c1 <=1;c1++)
                for (int c2 = 0 ; c2<=1;c2++){
                    for (int per = 0; per <= 1 ;per++){
                    if ( (c1 ^ c2) == xr[i] && (c1 + c2 + per)%2 == sum[i]){
                        int nv = c1 + c2 + per;
                        int np;
                        if (nv >= 2)
                            np = 1;
                        else
                            np = 0;
                        dp[i+1][np] += dp[i][per];
                    }
            }
        }
    }
    if (n == x)
        dp[os][0] -= 2;
    cout<<dp[os][0];
    return 0;
}