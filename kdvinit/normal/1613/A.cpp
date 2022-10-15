/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int digi(int x)
{
    int ans=0;
    while(x!=0) { x/=10; ans++; }
    return ans;
}

char solve()
{
    int x1, p1, x2, p2;
    cin>>x1>>p1>>x2>>p2;

    int dif=p1-p2;

    p1+=digi(x1);
    p2+=digi(x2);

    if(p1>p2) return '>';
    if(p1<p2) return '<';

    if(dif<0)
    {
        dif*=-1;
        while(dif--) x2*=10;
    }
    else while(dif--) x1*=10;

    if(x1>x2) return '>';
    if(x1<x2) return '<';

    return '=';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) cout<<solve()<<endl;
    return 0;
}