/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    int len = n*m;

    int a[len+1], sum[len+1];

    sum[0]=0;
    for(int i=1; i<=len; i++)
    {
        char x; cin>>x;
        a[i] = (x-'0');
        sum[i]=sum[i-1]+a[i];
    }

    int r[len+1]={0};
    for(int i=1; i<=len; i++)
    {
        int lst = i-m;
        if(lst<0) lst=0;

        int cur=sum[i]-sum[lst];
        r[i]=r[lst];
        if(cur>0) r[i]++;
    }

    int alr[m+1]={0}, tot=0, c[len+1];
    for(int i=1; i<=len; i++)
    {
        int j = i%m;
        if(j==0) j=m;

        if(alr[j]==0 && a[i]==1)
        {
            alr[j]=1;
            tot++;
        }

        c[i]=tot;
    }

    for(int i=1; i<=len; i++) cout<<r[i]+c[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}