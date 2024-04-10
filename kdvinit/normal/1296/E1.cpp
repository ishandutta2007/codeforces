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

    int ans[n+1],a[n+1];
    int lst0=0,lst1=0;

    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        a[i]=x-96;
    }

    for(int i=1;i<=n;i++)
    {
        int x=a[i];

        if(min(lst0,lst1)>x) { cout<<"NO"<<endl; return; }
        if(max(lst0,lst1)<=x)
        {
            if(lst0>lst1) { lst0=x; ans[i]=0; }
            else { lst1=x; ans[i]=1; }
            continue;
        }
        if(lst0<=x && x<lst1) { lst0=x; ans[i]=0; }
        if(lst1<=x && x<lst0) { lst1=x; ans[i]=1; }
    }

    cout<<"YES"<<endl;

    for(int i=1;i<=n;i++) cout<<ans[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}