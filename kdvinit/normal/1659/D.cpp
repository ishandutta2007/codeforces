/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int b[2*n+10]={0};
    int k=0;
    int nz=0;

    for(int i=1; i<=n; i++)
    {
        if(k>=n) break;
        if(k<i)
        {
            if(a[i]==0) { b[++k]=0; nz++; continue; }
            a[i] -= (i-1);

            int c = a[i];
            int en = min(k+c, n);

            for(int j=k+1; j<=en; j++) b[j]=1;
            b[en+1]=0;
            k=en+1;
            nz++;
        }
        else
        {
            int tmp = (b[i]*(i-1)) + (k-(i-1));
            a[i] -= tmp;

            int c = a[i];
            int en = min(k+c, n);

            for(int j=k+1; j<=en; j++) b[j]=1;
            b[en+1]=0;
            k=en+1;
            nz++;
        }
    }

    for(int i=1; i<=n; i++) cout<<b[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}