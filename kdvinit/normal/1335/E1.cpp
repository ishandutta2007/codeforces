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

    int a[n+2],freq[n+1][27]={0},ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=26;j++)
        {
            freq[i][j]=freq[i-1][j];
        }
        freq[i][a[i]]++;
        ans=max(ans,freq[i][a[i]]);
    }

    for(int i=1;i<=26;i++)
    {
        for(int j=1;j<=26;j++)
        {
            if(i==j) continue;
            if(freq[n][i]==0 || freq[n][j]==0) continue;

            a[0]=i; a[n+1]=i;
            int strt=0,nd=n+1,cnt=0;
            while(1)
            {
                strt++;
                nd--;
                while(a[strt]!=i) strt++;
                while(a[nd]!=i) nd--;

                cnt++;
                if(nd<=strt) break;

                int tmp=(2*cnt)+(freq[nd-1][j]-freq[strt][j]);
                ans=max(ans,tmp);

            }
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}