#include <bits/stdc++.h>
using namespace std;
int n,k,nr;
long double b,a[300110];
map <long double,int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b;
        if(!a[i])
        {
            if(!b)
                nr++;
            continue;
        }
        k=max(k,++m[b/a[i]]);
    }
    cout<<nr+k;
    return 0;
}