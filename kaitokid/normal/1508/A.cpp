#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mc(string s1,string s2)
{
    int d[2][2];
    d[0][0]=d[0][1]=d[1][0]=d[1][1]=0;
    for(int i=0;i<s1.size();i++)
    {
        d[0][s1[i]-'0']++;
        d[1][s2[i]-'0']++;

    }

    return max(min(d[0][0],d[1][0]),min(d[0][1],d[1][1]));
}

string mx(string s1,string s2)
{
    int d[2][2];
    d[0][0]=d[0][1]=d[1][0]=d[1][1]=0;
    for(int i=0;i<s1.size();i++)
    {
        d[0][s1[i]-'0']++;
        d[1][s2[i]-'0']++;

    }
  int u=0;
if(min(d[0][0],d[1][0])<min(d[0][1],d[1][1]))u=1;
int r=1-u;
vector<int>v;
if(d[0][u]<d[1][u])swap(s1,s2);
int f=0;
for(int i=0;i<s1.size();i++)
{
    if(s2[i]-'0'==u){v.push_back(f);f=0;}
    else f++;

}
v.push_back(f);
string ans="";
int g=0;
for(int i=0;i<s1.size();i++)
{
    if(s1[i]-'0'!=u){ans+=s1[i];continue;}
 if(g<v.size()) for(int j=0;j<v[g];j++)ans+='0'+r;
 ans+=s1[i];
 g++;
}
if(g<v.size())   for(int i=0;i<v[g];i++)ans+='0'+r;
return ans;
}
int main()
{ios::sync_with_stdio(0);
int t;
cin>>t;
string s[3];
while(t--)
{
    int n;
    cin>>n;
cin>>s[0]>>s[1]>>s[2];
bool bl=false;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    if(i!=j&&mc(s[i],s[j])>=n){cout<<mx(s[i],s[j])<<endl;bl=true;break;}

if(bl)break;
}
}
    return 0;
}