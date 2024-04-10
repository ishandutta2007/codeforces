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
const int maxn = 202, base = 1e9+7;
    bool dp[maxn][2*maxn][2*maxn] ;//= {0};
int main()
{
    //files1;
    int n;
    fast_io;
    cin>>n;
    string s;
    cin>>s;
    int r,g,b;
    r=g=b = 0;
    for (int i=0;i<n;i++)
        {
            if (s[i] =='B')
                b++;
            if (s[i] =='R')
                r++;
            if (s[i] =='G')
                g++;
        }
    dp[n][r][g] = 1;
    for (int i=n;i>1;i--)
        for (int j=400;j>=0;j--)
            for (int k=400;k>=0;k--){
                if (dp[i][j][k]){

                    int b1 = i-j-k;
                    //if (b1>b)
                    //    continue;
                    if (b1 < 0)
                        continue;
                  //  cerr<<j<<k<<b1<<endl;
                    if (j&&k)
                        dp[i-1][j-1][k-1] = 1;
                    if (j&&b1)
                        dp[i-1][j-1][k+1] = 1;
                    if (b1&&k)
                        dp[i-1][j+1][k-1] = 1;
                    if (j>=2)
                        dp[i-1][j-1][k] = 1;
                    if (b1>=2)
                        dp[i-1][j][k] = 1;
                    if (k>=2)
                        dp[i-1][j][k-1] = 1;
                }
    }

    if (dp[1][0][0])
        cout<<"B";
    if (dp[1][0][1])
        cout<<"G";
    if (dp[1][1][0])
        cout<<"R";
    return 0;
}