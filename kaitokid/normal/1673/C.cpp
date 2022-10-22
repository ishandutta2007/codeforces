#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
int dp[40009];
bool ch(int x)
{
    vector<int>g;
    while(x>0)
    {
        g.push_back(x%10);
        x/=10;
    }
    int l=0,r=g.size();
    r--;
    while(r>l)
    {
        if(g[l]!=g[r])return false;
        l++;
        r--;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0]=1;
    for(int i=1;i<40000;i++)
    {
        if(!ch(i))continue;
        for(int j=i;j<=40000;j++)dp[j]=(dp[j]+dp[j-i])%mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}