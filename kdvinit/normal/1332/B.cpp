/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int p[12]={1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve()
{
    int n, m=0;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int col[n+1]={0};

    for(int j=1; j<=11; j++)
    {
        int x = p[j], cnt=0;
        m++;
        for(int i=1; i<=n; i++)
        {
            if(col[i]!=0) continue;
            if(a[i]%x!=0) continue;
            col[i]=m;
            cnt++;
        }
        if(cnt==0) m--;
    }

    cout<<m<<endl;
    for(int i=1; i<=n; i++) cout<<col[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}