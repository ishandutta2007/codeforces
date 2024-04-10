/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int sum_digits(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int closest(int n,int s)
{
    if(n==0) return 1;
    int sum=sum_digits(n);
    if(sum<s) return (n+1);
    n/=10;
    return (closest(n,s))*10;
}

void solve()
{
    int n,s,m;
    cin>>n>>s;

    if(sum_digits(n)<=s) {cout<<0<<endl; return;}
    m=closest(n,s);
    m-=n;
    cout<<m<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}