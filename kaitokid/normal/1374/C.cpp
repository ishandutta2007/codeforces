#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,x,y;

int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)

{
    string s;
    cin>>n>>s;
    ll ans=0,sum=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')sum++;
        else sum--;
        if(sum<0){ans++;sum++;}
    }
cout<<ans<<endl;
}    return 0;
}