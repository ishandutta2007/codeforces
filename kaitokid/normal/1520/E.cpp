#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pr[1000009],suf[1000009],ans[1000009];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        string s;
        cin>>n>>s;
        for(int i=0;i<=n;i++)ans[i]=pr[i]=suf[i]=0;
        ll d=0;
        for(int i=0;i<n;i++)
        if(s[i]=='*'){
        pr[i-d+1]++;
        suf[i-d-1]++;
        d++;
        }
        d=0;
        ll r=0;
        for(int i=0;i<n;i++){
            d+=pr[i];
            r+=d;
            ans[i]+=r;
        }

         d=0;
         r=0;
        for(int i=n;i>=0;i--)
        {
            d+=suf[i];
            r+=d;
            ans[i]+=r;
        }
      ll res=ans[0];
      for(int i=1;i<n;i++)res=min(res,ans[i]);
      cout<<res<<endl;
    }
    return 0;
}