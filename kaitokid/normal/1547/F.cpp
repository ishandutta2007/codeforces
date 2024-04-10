#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>wh[2000009];
int pr[1000009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   for(int i=2;i<1000;i++)
   {
       if(pr[i])continue;
       for(int j=i*i;j<=1000000;j+=i)pr[j]=i;
   }
   for(int i=2;i<=1000000;i++)if(pr[i]==0)pr[i]=i;
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    ll x;
    set<int>d;
    ll gc=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        gc=__gcd(x,gc);
        while(x>1)
        {
            ll g=pr[x],f=pr[x];
            while((x%g)==0){wh[f].push_back(i);x/=g;d.insert(f);f*=g;}

        }
    }
    set<int>::iterator it=d.begin();
    int ans=0;
    while(it!=d.end())
    {
        int r=(*it);
        if((gc%r)==0){wh[r].clear();it++;continue;}

        int d=1;
        for(int i=1;i<wh[r].size();i++)
        {
            if(wh[r][i]==(wh[r][i-1]+1)){d++;continue;}
            ans=max(ans,d);
            d=1;
        }
        ans=max(ans,d);
        int w=-1,f=n;
        for(int i=0;i<wh[r].size();i++)
        {
            if(wh[r][i]!=(w+1))break;
            w++;

        }
        for(int i=wh[r].size()-1;i>=0;i--)
        {
            if(wh[r][i]!=(f-1) )break;
            f--;
        }
        ans=max(ans,w+1+n-f);
        wh[r].clear();
        it++;
    }
    cout<<ans<<endl;
}
    return 0;
}