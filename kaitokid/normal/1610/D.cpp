#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll p[200009];
ll fr[47];
ll s[47];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=1;
    for(int i=1;i<=200002;i++)p[i]=(p[i-1]*2)%mod;

    int n;
    cin>>n;
    ll ans=p[n]-1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x%2)continue;
        int d=0;
        while(x%2==0){d++;x/=2;}
        fr[d]++;
    }
    for(int i=40;i>=0;i--)s[i]=s[i+1]+fr[i];
    for(int i=40;i>0;i--)
    {
       if(fr[i]==0)continue;
       ll d=p[fr[i]-1];
       d*=p[s[i+1]];
       d%=mod;
       ans=(ans-d+mod)%mod;
    }

    cout<<ans<<endl;

    return 0;
}