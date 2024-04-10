#include <bits/stdc++.h> 
using namespace std ;
bool cover[30],r[30];
int v[30],num;
int main()
{ios::sync_with_stdio(0);
int n,m;
string s;
cin>>n>>s>>m;
for(int i=0;i<n;i++)
{if(s[i]!='*')cover[s[i]-'a']=true;}
string x;
for(int i=0;i<m;i++)
{bool d=false;
memset(r,0,sizeof r);
cin>>x;
for(int i=0;i<n;i++){if(s[i]!='*'&&x[i]!=s[i]){d=true;break;}
if(s[i]=='*'&&cover[x[i]-'a']){d=true;break;}}
if(d)continue;
num++;
for(int i=0;i<n;i++){if(s[i]=='*'&&r[x[i]-'a']==false){
v[x[i]-'a']++;r[x[i]-'a']++;}}
}
int ans=0;
for(int i=0;i<30;i++)
{if(v[i]==num)ans++;}
cout<<ans;
return 0;}