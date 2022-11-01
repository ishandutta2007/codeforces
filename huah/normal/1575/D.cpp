#include<bits/stdc++.h>
using namespace std;
const int N=20;
char s[N];
int n;
int sol()
{
    if(n>1&&s[1]=='0') return 0;
    int dp[N][25];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<25;j++)
    {
        int l,r;
        if(s[i+1]=='_') l=0,r=9;
        else l=r=s[i+1]-'0';
        for(int k=l;k<=r;k++)
        {
            if(n>1&&k==0&&(i+1)==1) continue;
            dp[i+1][(j*10+k)%25]+=dp[i][j];
        }
    }
    return dp[n][0];
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    vector<int>vc;
    for(int i=1;i<=n;i++)
        if(s[i]=='X') vc.push_back(i);
    int ans=0;
    if(vc.size())
    {
        for(int i=0;i<=9;i++)
        {
            for(int x:vc) s[x]=char(i+'0');
            ans+=sol();
        }
    }
    else ans+=sol();
    printf("%d\n",ans);
}