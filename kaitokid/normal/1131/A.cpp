#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    ll w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;
    ll ans=(w1+2)*(h1+2)+(w2+2)*h2;
    ans-=w1*h1+w2*h2;
    cout<<ans;
    
    return 0;
}