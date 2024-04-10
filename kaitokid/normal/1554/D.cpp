#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n==1){cout<<"a"<<endl;continue;}
        if((n%2)==1){cout<<"c";n--;}
        for(int i=0;i<n/2;i++)cout<<"a";
        cout<<"b";
        for(int i=1;i<(n/2);i++)cout<<"a";
        cout<<endl;
         }
    return 0;
}