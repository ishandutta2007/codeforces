#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long long n,q,e=0,o=0,x,y,i,p[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    while(q--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>y;
            e+=y;o+=y;
        }
        else
        {
            if(e%2==0)
            {
                o++;e--;
            }
            else
            {
                e++;o--;
            }
        }
    }
    for(i=1;i<=n;++i)
    {
        if(i%2==0)
        p[(i+e+n*2000000)%n+n*!((i+e+n*2000000)%n)]=i;
        else p[(i+o+n*2000000)%n+n*!((i+o+n*2000000)%n)]=i;
    }
    for(i=1;i<=n;++i)
    cout<<p[i]<<" ";
    return 0;
}