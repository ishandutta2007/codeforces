#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

long long level(long long node)
{
    long long c=1;
    while(node%2==0)
    {
        node/=2;
        c++;
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,q,m,i,u,po[100],l,L;
    po[0]=1;
    for(i=1;i<100;++i)
    po[i]=2*po[i-1];
    char a[100005];
    cin>>n>>q;
    L=level((n+1)/2);
    while(q--)
    {
        cin>>u;
        cin>>a;
        m=strlen(a);
        for(i=0;i<m;++i)
        {
            l=level(u);
            if(a[i]=='U')
            {
                if(l==L) continue;
                if(u%po[l+1]<po[l])
                u+=po[l-1];
                else u-=po[l-1];
            }
            if(a[i]=='L')
            {
                if(l==1) continue;
                u-=po[l-2];
            }
            if(a[i]=='R')
            {
                if(l==1) continue;
                u+=po[l-2];
            }
        }
        cout<<u<<endl;
    }
    return 0;
}