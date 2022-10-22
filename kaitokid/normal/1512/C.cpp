#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    int a,b;
    string s;
    cin>>a>>b>>s;
int n=a+b;
bool ans=true;
for(int i=0;i<n;i++)
{
    if(s[i]=='?')continue;
    if(s[n-i-1]!='?'&&s[n-i-1]!=s[i]){ans=false;break;}
    s[n-i-1]=s[i];
}
int fr[2]={0,0};
for(int i=0;i<n;i++)if(s[i]!='?')fr[s[i]-'0']++;
if(a<fr[0]||b<fr[1]||(ans==false)){cout<<-1<<endl;continue;}
a-=fr[0],b-=fr[1];
if((a%2)&&(b%2)){cout<<-1<<endl;continue;}
for(int i=0;i<n/2;i++)
{
    if(s[i]!='?')continue;
    if(a>1){a-=2;s[i]=s[n-i-1]='0';continue;}
    b-=2;
    s[i]=s[n-i-1]='1';
}
if(a)s[n/2]='0';
if(b)s[n/2]='1';
cout<<s<<endl;
}
    return 0;
}