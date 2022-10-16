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

    int ans[n+1];
    int cnt=0,lst=0;


    set<int> inof,used;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            if(used.find(a[i])!=used.end()) { cout<<-1<<endl; return; }
            inof.insert(a[i]);
            used.insert(a[i]);
        }
        else
        {
            int x=a[i]*(-1);
            if(inof.find(x)==inof.end()) { cout<<-1<<endl; return; }
            inof.erase(x);
        }

        if(inof.size()==0)
        {
            used.clear();
            ans[++cnt]=i-lst;
            lst=i;
        }
    }

    if(inof.size()!=0) { cout<<-1<<endl; return; }

    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}