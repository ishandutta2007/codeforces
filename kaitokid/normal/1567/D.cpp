#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    ll n,s;

    cin>>s>>n;
    while(n>0)
    {
        if(n==1){cout<<s<<endl;break;}
        ll u=1000000000;
        while(s-u<n-1)u/=10;
        cout<<u<<" ";
        s-=u;
        n--;
    }
}
    return 0;

}