#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    ll x;
    cin>>x;
    ll u=1,z=x;
    while(z>9)
    {
        z/=10;
        u*=10;
    }
    cout<<x-u<<endl;

}

return 0;
}