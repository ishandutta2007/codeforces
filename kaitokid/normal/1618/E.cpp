#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200009],ans[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll sum=0;
        for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
        ll r=n*(n+1)/2;
        if(sum%r!=0){cout<<"NO"<<endl;continue;}
        sum/=r;
        bool res=true;
        for(int i=0;i<n;i++)
        {
            ll p=a[i]-a[(i-1+n)%n];
            p=sum-p;
            if(p<=0 || ((p%n) !=0)){res=false;break;}
            ans[i]=p/n;
        }
        if(!res) {cout<<"NO"<<endl;continue;}
        ll ss=0,g=0;
        for(int i=0;i<n;i++)
        {
            ss+=ans[i];
            g+=ans[i]*(n-i);
        }
        if(ss!=sum || g!=a[n-1]){cout<<"NO"<<endl;continue;}

        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        cout<<endl;

    }
    return 0;
}