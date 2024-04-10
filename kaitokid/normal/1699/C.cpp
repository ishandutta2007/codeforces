#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
int pos[100009],p[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p[0]=1;
    for(int i=1;i<=100002;i++)
        p[i]=(p[i-1]*1LL*i)%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            pos[x]=i;
        }
        int ans=1,l=pos[0],r=pos[0];
        for(int i=1;i<n;i++)
        {
            if((pos[i]<=r)&&(pos[i]>=l)){ans=(ans*1LL*(r-l+1-i))%mod;continue;}
            if(pos[i]<l){l=pos[i];continue;}
            if(pos[i]>r){r=pos[i];continue;}

        }
        cout<<ans<<endl;


        }

    return 0;
}