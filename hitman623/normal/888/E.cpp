#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    io
    long n,m,i,t1,t2,d1,d2,a[101],ans=0,j;
    cin>>n>>m;
    for(i=0;i<n;++i)
    cin>>a[i];
    t1=n/2;
    d1=(1<<t1);
    t2=n-t1;
    d2=(1<<t2);
    set < long > st1,st2;
    for(i=0;i<d1;++i)
    {
        long s=0;
        for(j=0;j<t1;++j)
        if(i&(1<<j))
        s=(s+a[j])%m;
        st1.insert(s);
    }
    for(i=0;i<d2;++i)
    {
        long s=0;
        for(j=0;j<t2;++j)
        if(i&(1<<j))
        s=(s+a[t1+j])%m;
        st2.insert(s);
    }
    for(auto i:st1)
    {
        auto j=st2.lower_bound(m-i);
        if(j!=st2.end())
        ans=max(ans,(i+*j)%m);
        if(*j>=m-i)
        {
            if(j!=st2.begin())
            j--;
        }
        ans=max(ans,(i+*j)%m);
    }
    cout<<ans;
    return 0;
}