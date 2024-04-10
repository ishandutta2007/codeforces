#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009],n,q;
ll lst[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
         cin>>n>>q;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            lst[i]=-1;
            sum+=a[i];
        }
        ll p=-2,g;
        for(int i=0;i<q;i++)
        {
            int t;
            cin>>t;
            if(t==2)
            {
                ll x;
                cin>>x;
                sum=n*x;
                p=i;
                g=x;
                cout<<sum<<endl;
                continue;
            }
            ll x,y;
            cin>>x>>y;
            if(lst[x]<p)a[x]=g;
            sum-=a[x];
            sum+=y;
            a[x]=y;
            lst[x]=i;
            cout<<sum<<endl;

        }

    return 0;
}