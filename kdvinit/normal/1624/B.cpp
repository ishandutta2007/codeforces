/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int a, b, c;
    cin>>a>>b>>c;

    int aa = (b - (c-b));
    int bb = (a+c)/2;
    int cc = (b+(b-a));

    if(aa>0 && aa%a==0) return true;
    if(bb>0 && (a+c)%2==0 && bb%b==0) return true;
    if(cc>0 && cc%c==0) return true;

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}