#include<bits/stdc++.h>
using namespace std;
char a[103];
int main()
{
int n,k;
int g,t;
cin>>n>>k;
char x;
for(int i=0;i<n;i++)
{cin>>a[i];
if(a[i]=='G')g=i;
if(a[i]=='T')t=i;}

if((max(g,t)-min(g,t))%k!=0){cout<<"NO";return 0;}
for(int i=min(g,t);i<max(g,t);i+=k)
{if(a[i]=='#'){cout<<"NO";return 0;}
}
cout<<"YES";
return 0;
}