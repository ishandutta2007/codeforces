/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

bool Check_Pal(string s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    return rs==s;
}

void solve()
{
    string s;
    cin>>s;

    if(!Check_Pal(s+'a')) cout<<"YES"<<endl<<s+'a'<<endl;
    else if(!Check_Pal('a'+s)) cout<<"YES"<<endl<<'a'+s<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}