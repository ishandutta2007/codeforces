
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        ll u=1;
        bool ans=true;

        int n;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            u*=3;
            if(u>1000000000){ans=false;break;}
        }
       if(!ans){cout<<"NO"<<endl;continue;}
       cout<<"YES"<<endl;
       u=1;
       for(int i=0;i<n;i++){cout<<u<<" ";u*=3;}
       cout<<endl;
    }
    return 0;
}