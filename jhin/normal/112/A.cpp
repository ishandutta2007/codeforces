#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s,s1,s2;bool r[11],c[11];int cnt1,cnt2,a[1000],j=1,mx,mn,k,l,m,n,sum;

int main()
{

   cin>>s1>>s2;
   for(int i=0;i<s1.size();i++){k=int(s1[i]);if(k>90)s1[i]=char(k-32);}
   for(int i=0;i<s2.size();i++){k=int(s2[i]);if(k>90)s2[i]=char(k-32);}
   for(int i=0;i<s1.size();i++)
   {
       if(s1[i]<s2[i]) return cout<<-1,0;
       if(s1[i]>s2[i]) return cout<<1,0;
   }
   cout<<0;

    return 0;
}