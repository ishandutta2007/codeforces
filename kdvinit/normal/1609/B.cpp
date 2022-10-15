/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

string s;
int n, q;

bool check(int i)
{
    return (i>=0 && i+2<n && s[i]=='a' && s[i+1]=='b' && s[i+2]=='c');
}

void solve()
{
    cin>>n>>q>>s;

    int ans=0;
    for(int i=1; i<=n; i++) ans+=check(i-1);

    while(q--)
    {
        int pos; char x;
        cin>>pos>>x;

        pos--;
        for(int i=-2; i<=2; i++) ans-=check(pos+i);
        s[pos]=x;
        for(int i=-2; i<=2; i++) ans+=check(pos+i);

        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}