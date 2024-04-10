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
long n,a[100005],b[100005],i,visi[100005],d=0,c,dd[100005],j;
int main()
{
    io
    ml p,pp;
    vector < vl > vv;
    vl v;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
        p[a[i]]=i;
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i)
    pp[a[i]]=i;
    for(i=1;i<=n;++i)
    if(!visi[i])
    {
        j=i;
        v.clear();
        c=0;
        while(!visi[j])
        {
            c++;
            v.pb(j);
            visi[j]=1;
            j=pp[b[j]];
        }
        dd[d]=c;
        vv.pb(v);
        d++;
    }
    cout<<d<<"\n";
    for(i=0;i<d;++i)
    {
        cout<<dd[i]<<" ";
        for(j=0;j<dd[i];++j)
        cout<<vv[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}