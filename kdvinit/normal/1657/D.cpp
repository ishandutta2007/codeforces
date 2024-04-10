/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1e6 + 5;
int mxp[N];

void solve()
{
    int n, C;
    cin>>n>>C;

    for(int i=1; i<=C; i++) mxp[i]=0;

    for(int i=1; i<=n; i++)
    {
        int c, d, h;
        cin>>c>>d>>h;
        int p= (d*h);
        mxp[c]=max(mxp[c], p);
    }

    int mxpos[C+1];
    for(int i=1; i<=C; i++) mxpos[i]=0;

    for(int i=1; i<=C; i++)
    {
        for(int j=1; 1; j++)
        {
            int k = (i*j);
            if(k>C) break;

            int p=mxp[j];
            if(p==0) continue;

            int r = (i*p) - 1;
            mxpos[k]=max(mxpos[k], r);
        }
    }

    for(int i=2; i<=C; i++) mxpos[i] = max(mxpos[i], mxpos[i-1]);

    int m; cin>>m;

    for(int i=1; i<=m; i++)
    {
        int d, h;
        cin>>d>>h;
        int p=d*h;
        if(p>mxpos[C]) { cout<<-1<<" "; continue; }

        int l=0, r=C;
        while(l+1!=r)
        {
            int mid=(l+r)/2;
            if(mxpos[mid]>=p) r=mid;
            else l=mid;
        }

        cout<<r<<" ";
    }

    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}