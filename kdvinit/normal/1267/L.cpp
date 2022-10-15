/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n,l,k,m;
    cin>>n>>l>>k;

    m=l*n;
    char a[m+1];
    for(int i=1;i<=m;i++) cin>>a[i];

    sort(a+1,a+m+1);

    if(k==1)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=l;j++) cout<<a[++cnt];
            cout<<endl;
        }
        return;
    }

    char ans[n+1][l+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=l;j++) ans[i][j]='?';
    }

    int cnt=0;

    int c=1,lst=1,tmp=1;
    while(c<=l)
    {
        lst=tmp;
        for(int i=tmp;i<=k;i++)
        {
            cnt++;
            if(cnt!=1 && a[cnt-1]!=a[cnt])
            {
                lst=i;
            }
            ans[i][c]=a[cnt];
        }
        if(lst==k) break;
        tmp=lst;
        c++;
    }

    for(int i=c+1;i<=l;i++) ans[k][i]=a[++cnt];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(ans[i][j]!='?') continue;
            ans[i][j]=a[++cnt];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=l;j++) cout<<ans[i][j];
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}