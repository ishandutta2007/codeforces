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
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans=c+abs(b-c);
        if(ans==a)cout<<3<<endl;
        if(ans<a)cout<<2<<endl;
        if(ans>a)cout<<1<<endl;

    }
    return 0;
}