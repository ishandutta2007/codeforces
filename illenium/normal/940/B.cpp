#include<bits/stdc++.h>

using namespace std;

#define ll long long

int h[100000];

int main()
{
    ll n,k,a,b;cin>>n>>k>>a>>b;
    if(k == 1) {
        cout<<(n - 1) * a<<endl;
        return 0;
    }
    ll res = 0;
    while (n > 1)
    {
        if(n < k)
        {
            res += (n - 1) * a;
            break;
        }
        if( n % k != 0) {
            res += (n % k) * a;
        }
        n -= n % k;
        ll t = n/k;
        if((n - t) * a < b) {
            res += a*(n - t);
        } else res += b;
        n /= k;
    }
    cout<<res<<endl;
    return 0;
}