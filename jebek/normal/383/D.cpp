#include <iostream>
#include<algorithm>

using namespace std;

const int MOD=1000000007;
long long n,a,ans,t[22000][1100];

int main()
{
    cin>>n;
    cin>>a;
    t[10000+a][0]=1;
    t[10000-a][0]=1;
    ans=t[10000][0];
    for(int i=1;i<n;i++)
    {
        cin>>a;
        t[10000+a][i]=1;
        t[10000-a][i]=1;
        for(int j=a;j<=20000;j++)
        {
            t[j-a][i]+=t[j][i-1];
            if(t[j-a][i]>=MOD)
                t[j-a][i]%=MOD;
            t[j+a][i]+=t[j][i-1];
            if(t[j+a][i]>=MOD)
                t[j+a][i]%=MOD;
        }
        ans+=t[10000][i];
        if(ans>=MOD)
            ans=ans%MOD;
    }
    cout<<ans<<endl;
}