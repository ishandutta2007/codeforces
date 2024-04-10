/*
:
      
        
      
      
      
        
      
       

    ,  ,  
     ,    
,   ,   
    " "
         
        
    ,  ,   
   " ",   ,   
     ,   
    ,   
  ,   
  ,   
    , , ,  
     ,    
  ,   ,    
 ,  ,    



  ,    
        
  ,    
   ,   
  ,   
    
        
  ,   
"  ,     "
  ,    
" ,  ,    "
   . "    ?"
"  ,     ,
      
    ",       -,
   ,    



"  ",    
"          
        
  ,     
 ,       
 ,   ,    
    ,    
    ,      "


*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n;
string s;
long z[200000];
long l,r;
long ovr[300000];
vector<pair<long,long> > ans;
long calc[200000];
long t;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>s;
n=s.size();
for (long i=1,l=0,r=0;i<n;i++)
{
 if (i<=r)z[i]=min(r-i+1,z[i-l]);
 while (i+z[i]<n&&s[z[i]]==s[i+z[i]])
  z[i]++;
 if (i+z[i]-1>r)l=i,r=i+z[i]-1;
}

/*for (int i=0;i<n;i++)
cout<<z[i]<<" ";
cout<<endl;
*/
z[0]=s.size();

for (int i=0;i<n;i++)
{
    calc[z[i]]++;
}
for (int i=150000;i+1;--i)
{
 ovr[i]=calc[i]+ovr[i+1];
}
/*
for (int i=0;i<s.size();i++)
cout<<z[i]<<" ";
cout<<endl;
*/

for (int i=0;i<s.size();i++)
{
 t=n-i;
 if (z[i]<t)continue;
 ans.push_back(make_pair(t,ovr[t]));
}

sort(ans.begin(),ans.end());
cout<<ans.size()<<endl;

for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

cin.get();cin.get();
return 0;}