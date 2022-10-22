#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string ans[]={"Alice","Bob"};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll r=n*k;
        ll u=r/2,v=(r+1)/2;
        if(((u%k) !=0) || ((v%k)!=0)){cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
        int h=0;
        for(int i=1;i<=n*k;i+=2)
        {
            cout<<i<<" ";
            h++;
            if(h==k){cout<<endl;h=0;}

        }

        for(int i=2;i<=n*k;i+=2)
        {
            cout<<i<<" ";
            h++;
            if(h==k){cout<<endl;h=0;}

        }
               }
    return 0;
}