#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,bool> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{int n;
string s;
mp.clear();
cin>>n>>s;
for(int i=0;i<n;i++)
    {
        string u="";
        u+=s[i];
        mp[u]=1;}
for(int i=0;i<n-1;i++)
{
    string u="";
    u+=s[i];
    u+=s[i+1];
    mp[u]=1;
}
for(int i=0;i<n-2;i++)
{ string u="";
    u+=s[i];
    u+=s[i+1];
    u+=s[i+2];
    mp[u]=1;
}
string ans="";
for(int i=0;i<=26;i++)
   for(int j=0;j<=26;j++)

    for(int d=1;d<=26;d++)
{
    if(ans!="")break;
    if((i>0)&&(j==0))continue;
    string u="";
    if(i>0)u+=char('a'+i-1);
    if(j>0)u+=char('a'+j-1);
    u+=char('a'+d-1);
    if(mp[u]==0){ans=u;break;}
}
cout<<ans<<endl;

}
    return 0;
}