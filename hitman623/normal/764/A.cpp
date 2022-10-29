#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define bs binary_search
#define all(a) a.begin(),a.end()
using namespace std;
long gcd(ll a,ll b)
{
    if(a==0) return b;
    if(a<b)
    {
        return gcd(b%a,a);
    }
    else return gcd(a%b,b);
}
int main()
{
    ll n,m,z,h;
    cin>>n>>m>>z;
    h=(n*m)/gcd(n,m);
    cout<<(z/h);
    return 0;
}