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

string s;
cin>>s;
ll msk=0,u=0,ans=1;
for(int i=0;i<s.size();i++)
{
    int z=s[i]-'a';
    if(msk&(1<<z))continue;
    u++;
    if(u>3){ans++;u=1;msk=(1<<z);continue;}
    msk|=(1<<z);
}
cout<<ans<<endl;
}

return 0;
}