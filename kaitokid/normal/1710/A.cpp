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
        ll n,m,k;
        cin>>n>>m>>k;
        ll u=0,v=0,x;
        bool blu=false,blv=false;
        for(int i=0;i<k;i++)
        {
            cin>>x;
            if((x/m)>1)u+=(x/m);
            if((x/m)>2)blu=true;
            if((x/n)>1)v+=(x/n);
            if((x/n)>2)blv=true;
        }
    if(u>=n)
    {
        if((n%2)==0){cout<<"YES"<<endl;continue;}
        if(blu){cout<<"YES"<<endl;continue;}
    }

    if(v>=m)
    {
        if((m%2)==0){cout<<"YES"<<endl;continue;}
        if(blv){cout<<"YES"<<endl;continue;}
    }
    cout<<"NO"<<endl;
    }
    return 0;
}