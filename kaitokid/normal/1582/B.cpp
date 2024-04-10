#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll r=1,u=0,n,x;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x==0)r=r*2;
            if(x==1)u++;
        }
        cout<<(u*r)<<endl;
    }
    return 0;
}