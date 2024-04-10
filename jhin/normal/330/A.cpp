#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s[11];bool r[11],c[11];int cnt,n,k,a[1000],j=1,mx,mn;
int main()
{
   cin>>n>>k;
   for(int i=0;i<n;i++)for(int j=0;j<k;j++){cin>>s[i][j];if(s[i][j]=='S')r[i]=true,c[j]=true;}
   for(int i=0;i<n;i++)
   {   if(!r[i])
       for(int j=0;j<k;j++)
           s[i][j]='*';
   }
    for(int i=0;i<k;i++)
   {   if(!c[i])
       for(int j=0;j<n;j++)
           s[j][i]='*';
   }
   for(int i=0;i<n;i++)for(int j=0;j<k;j++)if(s[i][j]=='*')cnt++;
   cout<<cnt;


    return 0;
}