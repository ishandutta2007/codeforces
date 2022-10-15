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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n+1);

    int al=0,bo=0;
    for(int i=1;i<=n;i++)
    {
        int x=a[n+1-i];
        if(i%2==1)
        {
            if(x%2==0) al+=x;
        }
        else
        {
            if(x%2==1) bo+=x;
        }
    }

    if(al>bo) cout<<"Alice"<<endl;
    if(al==bo) cout<<"Tie"<<endl;
    if(al<bo) cout<<"Bob"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}