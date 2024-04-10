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
    long n,m,k[201],f[201],i,j;
    set < long > v;
    cin>>n>>m;
    for(i=0;i<m;++i)
    cin>>k[i]>>f[i];
    for(i=1;i<=200;++i)
    {
        for(j=0;j<m;++j)
        if(f[j]!=(k[j]+i-1)/i) break;
        if(j==m)
        v.insert((n+i-1)/i);
    }
    if(v.size()!=1)
    cout<<-1;
    else cout<<*v.begin();

    return 0;
}