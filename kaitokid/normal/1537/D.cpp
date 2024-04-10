#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n%2){cout<<"Bob"<<endl;continue;}
        ll u=0;
        ll x=n;
        while((x%2)==0){u++;x/=2;}
        if(x!=1){cout<<"Alice"<<endl;continue;}
        if(u%2){cout<<"Bob"<<endl;continue;}
        cout<<"Alice"<<endl;
        }
    return 0;

}