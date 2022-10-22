#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
ll t;
cin>>t;
while(t--)
{
    ll x,y;
    cin>>x>>y;
    if(y==1){cout<<"NO\n";continue;}
    cout<<"YES\n";
    cout<<(x*y)<<" "<<x<<" "<<x*(y+1)<<endl;

}

    return 0;
}