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
        ll n;
        cin>>n;
        ll c1,c2;
        c1=c2=(n/3);
        if(n%3==2)c2++;
        if(n%3==1)c1++;
        cout<<c1<<" "<<c2<<endl;
    }
    return 0;
}