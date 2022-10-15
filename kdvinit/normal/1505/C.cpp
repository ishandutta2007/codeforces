/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin>>s;

    int n = s.size();

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        a[i] = s[i-1] - 'A';
    }

    for(int i=3; i<=n; i++)
    {
        int x = a[i-2] + a[i-1];
        x%=26;
        if(a[i]==x) continue;
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}