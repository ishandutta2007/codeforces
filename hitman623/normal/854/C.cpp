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
#define hell 99991
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long n,k,c[300005],i,v[300005],ans=0;
int main()
{
    io
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>c[i];
    set<pll>s;
    set<pll>::iterator it;
    for(i=0;i<k;++i)
    s.insert({c[i],i});
    for(i=0;i<n;++i)
    {
        if(i+k<n)
        s.insert({c[i+k],i+k});
        it=s.end();
        it--;
        v[it->y]=i+k+1;
        ans+=it->x*(i+k-it->y);
        s.erase(it);
    }
    cout<<ans<<endl;
    for(i=0;i<n;++i)
    cout<<v[i]<<" ";
    return 0;
}