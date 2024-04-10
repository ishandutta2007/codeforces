#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        bool bl1=false,bl2=false;
        for(int i=0;i<n;i+=2)
        {
            if((s[i]-'0')%2)bl1=true;
        }
        for(int i=1;i<n;i+=2)
        {
            if((s[i]-'0')%2==0)bl2=true;
        }
        if(n%2)
        {if(bl1)cout<<1<<endl;
        else cout<<2<<endl;
        continue;}
        if(bl2)
            cout<<2<<endl;
        else cout<<1<<endl;

    }
    return 0;
}