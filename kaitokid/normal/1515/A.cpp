#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[109];
int main()
{
int t;
cin>>t;
while(t--)
{
    ll n,s=0,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){cin>>a[i];s+=a[i];}
    if(s==x){cout<<"NO\n";continue;}
    cout<<"YES\n";
    sort(a,a+n);
    ll d=0;
    int i=0;
    while(i<n)
    {
        if((d+a[i])!=x){cout<<a[i]<<" ";d+=a[i];i++;continue;}
        cout<<a[i+1]<<" "<<a[i]<<" ";
        d+=a[i]+a[i+1];
        i+=2;
    }
    cout<<endl;
}


    return 0;
}