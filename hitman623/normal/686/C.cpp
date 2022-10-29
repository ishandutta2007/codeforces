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
    map < vl , long > mp;
    long n,m,c1=0,c2=0,nn,mm,ans=0,i;
    vl v;
    for(i=0;i<7;++i)
    v.pb(i);
    cin>>n>>m;
    nn=n;
    mm=m;
    n--;
    while(n)
    n/=7,c1++;
    m--;
    while(m)
    m/=7,c2++;
    c1=max(1LL,c1);
    c2=max(1LL,c2);
    if(c1+c2>7) {cout<<0;return 0;}
    else
    {
        do
        {
            vl vv;
            for(i=0;i<c1+c2;++i)
            vv.pb(v[i]);
            long h=0,m=0,cur=1;
            for(i=c1-1;i>=0;--i)
            {
                h+=v[i]*cur;
                cur*=7;
            }
            cur=1;
            for(i=c1+c2-1;i>=c1;--i)
            {
                m+=v[i]*cur;
                cur*=7;
            }
            if(h<nn && m<mm && mp[vv]==0) ans++;
            mp[vv]=1;
        }
        while(next_permutation(v.begin(),v.end()));
    }
    cout<<ans;
    return 0;
}