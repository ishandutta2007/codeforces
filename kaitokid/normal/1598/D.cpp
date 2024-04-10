#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[200009][5];
ll a[200009],b[200009],fra[200009],frb[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    c[0][0]=1;
    for(int i=1;i<=200009;i++)
    {
        c[i][0]=1;
        for(int j=1;j<4;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)fra[i]=frb[i]=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
            fra[a[i]]++;
            frb[b[i]]++;
        }


        ll ans=c[n][3];

        for(int i=0;i<n;i++)
            ans-=(fra[a[i]]-1)*(frb[b[i]]-1);


        cout<<ans<<endl;
    }
    return 0;
}