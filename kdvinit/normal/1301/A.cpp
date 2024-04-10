/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string a,b,c;
    cin>>a>>b>>c;

    int n=a.size();

    for(int i=0;i<n;i++)
    {
        if(a[i]==c[i] || b[i]==c[i]) continue;
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}