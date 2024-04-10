#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll k,n,s,p;
int main()
{
    cin>>k>>n>>s>>p;
    cout<<(ll)(ceil((ll)(ceil(n/(double)(s)))*k/(double)(p)));
}