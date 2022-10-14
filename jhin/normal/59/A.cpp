#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool r[11],c[11];int cnt,n,k,a[1000],j=1,mx,mn;
int main()
{

   cin>>s;
   for(int i=0;i<s.size();i++)if(int(s[i])>90)n++;else k++;
   if(k>n)for(int i=0;i<s.size();i++){j=int(s[i]);if(j>90)cout<<char(j-32);else cout<<s[i];}
   else   for(int i=0;i<s.size();i++){j=int(s[i]);if(j<=90)cout<<char(j+32);else cout<<s[i];}



    return 0;
}