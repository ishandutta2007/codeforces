#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    ll t,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        if(a<c)cout<<"1 ";else cout<<-1<<" ";
        if(b*a>c)cout<<b<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}