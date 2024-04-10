#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t,n;
cin>>t;
while(t--)
{
    cin>>n;
    if(n==1){cout<<0<<endl;continue;}
    if(n==2){cout<<1<<endl;continue;}
    if(n%2==0){cout<<2<<endl;continue;}
    if(n==3){cout<<2<<endl;continue;}
    cout<<3<<endl;
}
    return 0;
}