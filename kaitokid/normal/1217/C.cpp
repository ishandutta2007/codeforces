#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long long n,t;
string s;
int nz[200009];
int main()
{
    cin>>t;
    while(t--)
    {
cin>>s;
ll ans=0;
for(int i=1;i<(int)s.size();i++)
    if(s[i-1]=='0')nz[i]=nz[i-1]+1; else nz[i]=0;
for(int i=(int)s.size()-1;i>=0;i--)
{
    ll u=1,now=0;
    for(int j=i;j>=max(0,i-40);j--)
    {
        if(s[j]=='1')now+=u;
        u*=2;
        if(s[j]=='0')continue;
        if(now<i-j+1)continue;
        if(now<=i-j+1+nz[j]){ans++;}
    }

}
cout<<ans<<endl;
    }
    return 0;
}