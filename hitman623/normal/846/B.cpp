#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    long n,k,m,i,j,t[50],ans=0,cnt,ss=0,d;
    cin>>n>>k>>m;
    for(i=0;i<k;++i)
    {
        cin>>t[i];
        ss+=t[i];
    }
    sort(t,t+k);
    for(i=0;i<=n;++i)
    {
        d=m-i*ss;
        if(d<0) break;
        cnt=i*(k+1);
        for(j=0;j<k;++j)
        if(d>0)
        {
            cnt+=min(n-i,d/t[j]);
            d-=t[j]*min(n-i,d/t[j]);
        }
        else break;
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}