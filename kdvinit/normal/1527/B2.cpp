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

    char a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int sym=0, asym=0;
    int m = (n+1)/2;

    for(int i=1; i<=n; i++)
    {
        if(a[i]=='1') continue;

        if(n%2==1 && i==m) { sym++; continue; }

        if(a[n+1-i]=='0') sym++;
        else asym++;
    }

    int alead=asym;

    if(sym%2==0)
    {
        if(sym>0)
        {
            if(asym==0) alead-=2;
            else alead+=1;
        }
    }
    else
    {
        if(sym==1) alead-=1;
        else alead+=1;
    }

    if(alead==0) cout<<"DRAW"<<endl;
    if(alead<0) cout<<"BOB"<<endl;
    if(alead>0) cout<<"ALICE"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}