/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int Num_Bits(int n)
{
    int ans=0;
    while(1)
    {
        if(n%2==1) break;
        ans++;
        n/=2;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    int sum=0;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum%2==1)
    {
        cout<<0<<endl;
        return;
    }

    int mx = 2e5 + 2001;
    int pos[mx]={0};
    pos[0]=1;

    for(int i=1; i<=n; i++)
    {
        for(int j=2e5; j>=0; j--)
        {
            if(pos[j]==1) pos[j+a[i]]=1;
        }
    }

    if(pos[sum/2]==0)
    {
        cout<<0<<endl;
        return;
    }

    cout<<1<<endl;

    int Ind=0, Val=100;

    for(int i=1; i<=n; i++)
    {
        int tmp = Num_Bits(a[i]);
        if(tmp<Val)
        {
            Ind=i;
            Val=tmp;
        }
    }

    cout<<Ind<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}