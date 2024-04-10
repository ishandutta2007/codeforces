#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>

#define NO "NO"
#define YES "YES"
#define forn(n) for(int i=0; i<(n); i++)
#define pb push_back
#define sz size()
#define IgorI_sollution int main()
#define std_v(N) long long n,k,l,h,ans; int a[(N)],b[(N)],m[(N)]; string s; vector<int> v;
#define I i++

using namespace std;
 char str[1000700];
 vector<int> v;
 int k;
int f(int check)
{
     int z=check;
     int i=0;
     int ans=0;
     while(i<v.sz)
     {
          z=check;
      while(i<v.sz && z>=v[i])
      {
           
           z-=v[i];
           i++;
           
      }
      ans++;
      if(ans>k)
      {
           return 0;
      }
      
     }
     return 1;
}
 
 
IgorI_sollution
{
     
     cin>>k;
    
     gets(str);
     gets(str);
     string s=str;
     for(int i=0; i<s.sz; I)
     {
          if(s[i]=='-')
             s[i]=' ';
     }
     stringstream r(s);
     string a;
     
     while(r>>a)
     v.pb(a.sz+1);
     
     v[v.sz-1]--;
     
     
     int min1=1; int max1=1000000;
    
     int ans=max1;
     
     while(max1>=min1)
     {
           int check=(min1+max1)/2;
          if(f(check)==1)
             {max1=check-1;ans=check;}
          else
            min1=check+1;
          
     }
     cout<<ans<<endl;
     
     
     
}