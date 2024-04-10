#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool str[1000];int cnt,n,k,a[1000],j=1;
int main()
{
   cin>>n>>k>>s;
   for(int i=0;i<k;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(s[j]=='B'&&s[j+1]=='G')s[j]='G',s[j+1]='B',j++;
       }
   }
cout<<s;

    return 0;
}