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
long n,q,m,a[200005],i,x,t[200005],l[200005],r[200005],j;
int main()
{
    io
    cin>>n>>q>>m;
    for(i=1;i<=n;++i)
    cin>>a[i];
    for(i=0;i<q;++i)
    cin>>t[i]>>l[i]>>r[i];
    vl v;
    for(i=0;i<m;++i)
    {
        cin>>x;
        for(j=q-1;j>=0;j--)
        {
            if(t[j]==1)
            {
                if(x<l[j] || x>r[j]) continue;
                if(l[j]==x)
                x=r[j];
                else x=x-1;
            }
            else if(x>=l[j] && x<=r[j])
            {
                x=l[j]+r[j]-l[j]+1-(x-l[j]+1);
            }
        }
        v.pb(a[x]);
    }
    for(i=0;i<v.size();++i)
    cout<<v[i]<<" ";
    return 0;
}