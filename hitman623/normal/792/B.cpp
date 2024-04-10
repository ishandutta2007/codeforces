#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int main()
{
    long long n,k,i,a[101],l=1,c=0,s,m;
    cin>>n>>k;
    vector < long long > v;
    for(i=1;i<=n;++i)
    v.pb(i);
    for(i=0;i<k;++i)
    cin>>a[i];
    while(k--)
    {
        s=v.size();
        m=(l+a[c])%s+s*!((l+a[c])%s);
        cout<<v[m-1]<<" ";
        v.erase(v.begin()+m-1);
        l=m;
        c++;
    }
    return 0;
}