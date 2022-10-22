#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=998244353;
int n;
int a[200009],b[200009];
bool bl[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int s;
        cin>>n>>s;
        int x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            a[x]=i;
            b[i]=-1;
            bl[i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x!=-1){b[x]=i;
            bl[i]=true;}
        }
        for(int i=1;i<=n;i++)if(!bl[a[i]])a[i]=-1;
        for(int i=1;i<=n;i++)bl[i]=false;
        int c=0;
        for(int i=1;i<=min(s,n);i++)
            if(a[i]==-1)c++;
            else bl[a[i]]=true;
            int ans=1;
            for(int i=1;i<=n;i++)
            {
                if(i+s<=n)
                {
                    if(a[i+s]==-1)c++;
                    else bl[a[i+s]]=true;
                }
                if(b[i]==-1){ans=(ans*1LL*c)%mod;c--;continue;}
                if(!bl[b[i]]){ans=0;break;}

            }
            cout<<ans<<endl;



        }
    return 0;
}