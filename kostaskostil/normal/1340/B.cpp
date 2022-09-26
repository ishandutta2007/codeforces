#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

const int nmax=5e5+100;
#define int long long

int n, k;
    vector<string> d={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[nmax];
int pr[nmax];
int to(string s1, string s2)
{
    int ans=0;
    for (int i=0; i<7; i++)
        if ((s1[i]=='1') and (s2[i]=='0'))
            return 1e9;
        else
            if (s1[i]!=s2[i])
                ans++;
    return ans;
}

int mn(string s1)
{
    int ans=1e9;
    for (int i=0; i<10; i++)
        ans=min(ans, to(s1, d[i]));
    return ans;
}

int mx[2010][2010];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>s[i];

    for (int j=1; j<=k; j++)
        mx[n+1][j]=-1;
    mx[n+1][0]=0;
    for (int i=n; i>=1; i--)
    {
        for (int j=0; j<=k; j++)
            mx[i][j]=-1;
        for (int t=0; t<10; t++)
        {
                int dt=to(s[i], d[t]);
            for (int j=0; j<=k; j++)
            {
                if (dt<=j)
                    if (mx[i+1][j-dt]>=0)
                        mx[i][j]=0;
            }
        }
    }
    if (mx[1][k]==-1)
        cout<<mx[1][k]<<"\n";
    else
    {
        for (int i=1; i<=n; i++)
        {
            for (int t=9; t>=0; t--)
            {
                int dt=to(s[i], d[t]);
                if (k>=dt)
                    if (mx[i+1][k-dt]>=0)
                {
                    cout<<t;
                    k-=dt;
                    break;
                }
            }
        }
    }
}