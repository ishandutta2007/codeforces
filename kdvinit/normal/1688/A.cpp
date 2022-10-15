/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int x;
    cin>>x;

    int cntb=0;
    int fst=-1;

    for(int i=0; i<31; i++)
    {
        int y = pow(2, i);
        if((x&y)==0) continue;
        if(fst==-1) fst=y;
        cntb++;
    }

    if(cntb>1)
    {
        cout<<fst<<endl;
        return;
    }

    if(x==1) cout<<3<<endl;
    else cout<<fst+1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}