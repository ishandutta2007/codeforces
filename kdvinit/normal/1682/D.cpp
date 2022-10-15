/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
//#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    int cnt1=0;
    int f=-1;

    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i]=x-'0';
        cnt1+=a[i];
        if(a[i]==1 && f==-1) f=i;
    }

    if(cnt1%2==1 || cnt1==0) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;

    int cur=1;
    vector<array<int, 2>> e;

    int ex1=-1;
    int ex2=f;

    for(int i=f+1; 1; i++)
    {
        if(i>n) i-=n;
        if(i==f) break;
        cur+=a[i];

        int lst=i-1;    if(i==1) lst=n;
        int nxt=i+1;    if(i==n) nxt=1;
        lst=a[lst];

        if(a[i]==0) e.push_back({i, nxt});

        if(cur<cnt1-1)
        {
            if(lst==1) e.push_back({f, i});
        }
        else if(cur==cnt1-1)
        {
            if(a[i]==1 && lst==1) e.push_back({f, i});
            if(a[i]==0 && lst==1) ex1=i;
        }
        else
        {
            if(ex1==-1) ex1=i;
            if(lst==1 && a[i]==0) ex2=i;
        }
    }

    e.push_back({ex1, ex2});

    for(auto cur: e) cout<<cur[0]<<" "<<cur[1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}