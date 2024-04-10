/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

char compare(string a, string b)
{
    int al = a.size();
    int bl = b.size();

    int aa = a[al-1];
    int bb = b[bl-1];

    if(aa>bb) return '<';
    if(aa<bb) return '>';

    if(aa=='S') swap(al, bl);

    if(al>bl) return '>';
    if(al<bl) return '<';

    return '=';
}

void solve()
{
    string a, b;
    cin>>a>>b;
    cout<<compare(a, b)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}