#include <bits/stdc++.h>
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
        string x,y;
        cin>>x>>y;
        if(y=="a"){cout<<1<<endl;continue;}
        bool bl=false;
        for(int i=0;i<y.size();i++)if(y[i]=='a')bl=true;
        if(bl){cout<<-1<<endl;continue;}
        ll ans=1;
        for(int i=0;i<x.size();i++)ans*=2;
        cout<<ans<<endl;
    }

    return 0;
}