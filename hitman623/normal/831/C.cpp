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
    vl b;
    set < long > s;
    long n,k,i,a[2002],p[2002],c=0,j,x,t,f;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        p[i]=a[i]+(i?p[i-1]:0);
    }
    for(i=0;i<k;++i)
    {
        cin>>x;
        b.pb(x);
    }
    sort(b.begin(),b.end());
    for(i=0;i<n;++i)
    {
        t=b[0]-p[i];
        vl v;
        for(j=0;j<n;++j)
        v.pb(t+p[j]);
        sort(v.begin(),v.end());
        f=1;
        for(j=0;j<k;++j)
        if(!binary_search(v.begin(),v.end(),b[j]))
        {f=0;break;}
        if(f) s.insert(t);
    }
    cout<<s.size();
    return 0;
}