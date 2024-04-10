#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        string s;
        cin>>n>>m>>s;
        int l=1,r=n,g=0,ans=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='D')
                {
                g++;
                if(r+g>n)r--;
            if(r<l){ans=l;break;}
                }
               if(s[i]=='U')
               {
                   g--;
                   if(l+g<1)l++;
                 if(r<l){ans=r;break;}
               }
        }
        if(ans==-1)ans=l;
        cout<<ans<<" ";

         l=1,r=m,g=0,ans=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')
                {
                g++;
                if(r+g>m)r--;
            if(r<l){ans=l;break;}
                }
               if(s[i]=='L')
               {
                   g--;
                   if(l+g<1)l++;
                 if(r<l){ans=r;break;}
               }
        }
        if(ans==-1)ans=l;
        cout<<ans<<endl;
    }
    return 0;
}