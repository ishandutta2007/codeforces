/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int C = 1e6 + 5;
int chk[C], pre[C];

void solve()
{
    int n, c;
    cin>>n>>c;

    for(int i=0; i<=c; i++) chk[i]=0, pre[i]=0;

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        chk[x]=1;
    }

    for(int i=1; i<=c; i++)
    {
        pre[i]=pre[i-1]+chk[i];
    }

    if(chk[1]==0) { cout<<"No"<<endl; return; }

    for(int i=2; i<=c; i++)
    {
        if(chk[i]==0) continue;
        for(int j=1; 1; j++)
        {
            int l = i*j;
            int r = (i*(j+1))-1;
            r = min(r, c);

            if(l>c) break;
            int cnt = pre[r]-pre[l-1];

            if(cnt==0) continue;
            if(chk[j]==0) { cout<<"No"<<endl; return; }
        }
    }

    cout<<"Yes"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}