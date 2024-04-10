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

    int freq[27]={0};
    int sus=0;

    char lst;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        int y = x-'A'+1;

        if(i!=1 && x==lst) continue;

        if(freq[y]==1) sus=1;
        freq[y]=1;
        lst=x;
    }

    if(sus==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}