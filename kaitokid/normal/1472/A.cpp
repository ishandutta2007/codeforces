#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,w,h,n;
    cin>>t;
    while(t--)
    {
        cin>>w>>h>>n;
        ll u=1;
        while(h%2==0){u*=2;h/=2;}
        while(w%2==0){u*=2;w/=2;}
        if(u>=n)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}