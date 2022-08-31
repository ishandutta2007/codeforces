#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    if(n&1)
    {
        cout<<0;
        return 0;
    }
    int x = n>>1;
    cout<<(x-1)/2;
}