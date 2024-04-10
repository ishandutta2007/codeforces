#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009],s[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<=100000;i++)s[i]=0;
        for(int i=0;i<n;i++)
            cin>>a[i];

            for(int i=0;i<n;i++)
            {

                s[a[i]+1]=1000000000;
                int u=sqrt(a[i]);
                for(int g=1;g<=10+u;g++){
                if(a[i]<g){s[g]=max(s[g],1000000000);continue;}
                int d=a[i]/g;
                s[g]=max(s[g],a[i]/min(d,k));
                }
                for(int g=1;g<=min(u,k);g++)
                {
                    int ff=1+(a[i]/(g+1));
                  s[ff]=max(s[ff],a[i]/g);
                }
                s[0]=max(s[0],a[i]/k);

            }
            int ans=100009,d=0;
            for(int i=0;i<=100000;i++)
            {
                d=max(d,max(i,s[i]));
               // cout<<i<<" "<<d<<endl;
                ans=min(ans,d-i);
            }
            cout<<ans<<endl;

    }
    return 0;
}