#include <bits/stdc++.h>
using namespace std ;
int a[30][10004];
int main (){
    string s1,s2 ;
cin>>s1>>s2;
memset(a,-1,sizeof a) ;
//for(int i=0;i<26;i++)memset(a[i],-1,sizeof a[i]) ;
for(int i=0;i<s1.size();i++)
{
a[int(s1[i])-int('a')][i]= i;
}
for(int i=0;i<26;i++)
{int d=-1;
for(int j=s1.size();j>=0;j--)
{if(a[i][j]==-1){a[i][j]=d;}
d=a[i][j];}}
int res=1,l=0;
for(int i=0;i<s2.size();i++)
{
if(a[int(s2[i])-int('a')][0]==-1){cout<<-1;return 0;}

if(a[int(s2[i])-int('a')][l]==-1)
{res++;l=a[int(s2[i])-int('a')][0]+1;continue;}

l=a[int(s2[i])-int('a')][l]+1;}
cout<<res;
return 0 ;}