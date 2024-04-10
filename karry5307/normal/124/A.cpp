#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll n,a,b;
int main()
{
    cin>>n>>a>>b;
    cout<<n-max(a+1,n-b)+1;
}