#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        ll u=r+1;
       if(l<=(u-1)/2)cout<<"NO\n";
       else cout<<"YES\n";

    }
    return 0;
}