#include<bits/stdc++.h>

using namespace std;

#define DIM 200007

long long t, n, k, pos, a[DIM], c[DIM];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i];
        c[1]=1;
        pos=-1;
        k=1;
        for(int i=2; i<=n; i++)
        {
            if(a[i]==a[i-1])
            {
                c[i]=c[i-1];
                pos=i;
            }
            else
            {
                if(c[i-1]==1) c[i]=2;
                else c[i]=1;
                k=max(k, c[i]);
            }
        }
        if(a[n]!=a[1] && c[n]==c[1])
        {
            if(pos==-1)
            {
                c[n]=c[n-1]+1;
                k=max(c[n], k);
            }
            else
            {
                for(int i=pos; i<=n; i++)
                {
                    if(c[i]==1) c[i]=2;
                    else c[i]=1;
                }
            }
        }
        cout<<k<<endl;
        for(int i=1; i<=n; i++) cout<<c[i]<<' ';
        cout<<endl;
    }
    return 0;
}