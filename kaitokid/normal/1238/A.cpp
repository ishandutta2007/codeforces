#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(x==y+1)cout<<"NO\n";
            else cout<<"YES\n";
    }
    return 0;
}