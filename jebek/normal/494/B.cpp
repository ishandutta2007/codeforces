#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

const int P=37,MOD=1000000007;
string s,t;
long long hs1,hs[200000],f,p,dp[200000],sum[200000],sum1,ans,x;
bool mark[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>s>>t;
    p=1;
    for(int i=1;i<=t.size();i++)
        p=(p*P)%MOD;
    for(int i=0;i<t.size();i++)
        hs1=(hs1*P+int(t[i]-'a')+1)%MOD;
    for(int i=1;i<=s.size();i++)
        hs[i]=(hs[i-1]*P+int(s[i-1]-'a')+1)%MOD;
    for(int i=t.size();i<=s.size();i++)
    {
        long long a=hs[i],b=(hs[i-t.size()]*p)%MOD;
        a=(a-b+MOD)%MOD;
        if(a==hs1){
            dp[i]=i-t.size()+1-x;
            x=i-t.size()+1;
            mark[i]=true;
            //cout<<i<<" "<<dp[i]<<endl;
        }
    }
    for(int i=t.size();i<=s.size();i++)
    {
       dp[i]+=dp[i-1];
       sum1+=sum[i-t.size()];
       if(mark[i])
       {
           dp[i]=(dp[i]+sum1)%MOD;
           sum1=0;
       }
        sum[i]=(sum[i-1]+dp[i])%MOD;
         // cout<<i<<" "<<dp[i]<<" "<<sum[i]<<endl;
    }
    cout<<sum[s.size()]<<endl;
}