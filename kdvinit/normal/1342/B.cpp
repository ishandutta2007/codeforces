#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin>>s;

    int n=s.size();

    int all_same=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[0]) all_same=0;
    }

    if(all_same)
    {
        cout<<s<<endl;
        return;
    }

    for(int i=1;i<=(2*n);i++)
    {
        cout<<(i%2);
    }
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}