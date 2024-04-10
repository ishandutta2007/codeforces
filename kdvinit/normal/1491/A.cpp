/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, q;
    cin>>n>>q;

    int a[n+1], cnt1=0;
    for(int i=1;i<=n;i++) { cin>>a[i]; cnt1+=a[i]; }

    while(q--)
    {
        int t, k;
        cin>>t>>k;

        if(t==1)
        {
            if(a[k]==0) { cnt1++; a[k]=1; }
            else { cnt1--; a[k]=0; }
        }
        else
        {
            if(cnt1>=k) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}