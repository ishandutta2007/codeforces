#include <bits/stdc++.h>
#define DMAX 200009
using namespace std;

long long a[DMAX], n, k;
long long ans;
unordered_map <long long, long long> m, m2;

int main()
{
cin>>n>>k;


    for(long long i=1;i<=n;i++)
        cin>>a[i];

    if(k==1)
    {
    for(long long i=1;i<=n;i++)
    {
        if(m[a[i]]>=2)
        {
            ans+=m[a[i]]*(m[a[i]]-1)/2;
        }
        m[a[i]]++;
    }
    cout<<ans<<'\n';
    return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        if(a[i]%k==0)
        {
            if(m2.find(a[i]/k) != m2.end())
            ans+=m2[a[i]/k];

        if(m.find(a[i]/k) != m.end())
            m2[a[i]]+=m[a[i]/k];

        //cout<<m[a[i]/k]<<':';


        }

        m[a[i]]++;
    }

    cout<<ans<<'\n';
    return 0;
}