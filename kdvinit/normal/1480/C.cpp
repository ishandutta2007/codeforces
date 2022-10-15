/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int z;
    if(n<=100)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"? "<<i<<endl;
            cin>>z;

            if(z==1) { cout<<"! "<<i<<endl; return; }
        }
    }

    int x=1,y=n;
    while(1)
    {
        int a,b,c;

        if(x+1==y)
        {
            cout<<"? "<<x<<endl;
            cin>>a;
            cout<<"? "<<y<<endl;
            cin>>b;

            if(a<b) cout<<"! "<<x<<endl;
            else cout<<"! "<<y<<endl;

            return;
        }

        int mid=(x+y)/2;
        cout<<"? "<<mid-1<<endl;
        cin>>a;
        cout<<"? "<<mid<<endl;
        cin>>b;
        cout<<"? "<<mid+1<<endl;
        cin>>c;

        if(b<c && b<a)
        {
            cout<<"! "<<mid<<endl;
            return;
        }

        if(a<b)
        {
            y=mid;
        }
        else
        {
            x=mid;
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}