/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, a, b;
    cin>>n>>a>>b;

    int m = (n-1)/2;
    if(a>m || b>m || a+b>n-2) { cout<<-1<<endl; return; }

    int dif = abs(a-b);
    if(dif>1) { cout<<-1<<endl; return; }

    if(a>b)
    {
        int per[n+1];
        for(int i=1; i<=n; i++) per[i]=n+1-i;

        int cnt=1;
        for(int i=1; cnt<=a; i+=2, cnt++) swap(per[i], per[i+1]);

        for(int i=1; i<=n; i++) cout<<per[i]<<" ";
        cout<<endl;
    }

    if(a==b)
    {
        int per[n+1];
        for(int i=1; i<=n; i++) per[i]=i;

        int cnt=1;
        for(int i=2; cnt<=a; i+=2, cnt++) swap(per[i], per[i+1]);

        for(int i=1; i<=n; i++) cout<<per[i]<<" ";
        cout<<endl;
    }

    if(a<b)
    {
        int per[n+1];
        for(int i=1; i<=n; i++) per[i]=i;

        int cnt=1;
        for(int i=1; cnt<=b; i+=2, cnt++) swap(per[i], per[i+1]);

        for(int i=1; i<=n; i++) cout<<per[i]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}