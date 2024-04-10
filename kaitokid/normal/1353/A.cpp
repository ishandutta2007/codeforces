#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{ios::sync_with_stdio(0);
ll t,n,k;
cin>>t;
while(t--)
{
    cin>>n>>k;
    if(n==1){cout<<0<<endl;continue;}
    if(n==2){cout<<k<<endl;continue;}
    cout<<2*k<<endl;
}
    return 0;
}