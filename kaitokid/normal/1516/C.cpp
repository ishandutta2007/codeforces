#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[109];
bool dp[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    dp[0]=true;
    if(sum%2){cout<<0;return 0;}
    for(int i=0;i<n;i++)
    {
        int u=a[i];
        for(int j=200000;j>=0;j--)if(dp[j])dp[u+j]=true;

    }
    sum/=2;
    if(dp[sum]==false){cout<<0;return 0;}
    int mx=1000,ans;
    for(int i=0;i<n;i++)
    {
        int d=0;
        while((a[i]%2)==0){d++;a[i]/=2;}
    if(d<mx){mx=d;ans=i+1;}
    }
    cout<<1<<endl<<ans;
    return 0;
}