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
long n,x[5][1005],i,j,f,k;
long dot(long i,long j,long k)
{
    long ii,s=0;
    for(ii=0;ii<5;++ii)
    s+=(x[ii][j]-x[ii][i])*(x[ii][k]-x[ii][i]);
    return s<=0;
}
int main()
{
    io
    vl v;
    cin>>n;
    for(i=0;i<n;++i)
    for(j=0;j<5;++j)
    cin>>x[j][i];
    if(n>20) {cout<<0;exit(0);}
    for(i=0;i<n;++i)
    {
        f=1;
        for(j=0;j<n;++j)
        if(i!=j)
        {
            for(k=0;k<n;++k)
            if(k!=i && k!=j)
            {
                if(!dot(i,j,k))
                {f=0;break;}
            }
            if(!f) break;
        }
        if(f) v.pb(i);
    }
    cout<<v.size()<<endl;
    for(i=0;i<v.size();++i)
    cout<<v[i]+1<<endl;
    return 0;
}