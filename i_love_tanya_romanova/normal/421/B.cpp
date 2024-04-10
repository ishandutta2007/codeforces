/*
       .
-  ,    
 ,  .
        
   ,  .
    ,     .
---, -, -- -- 
---, ----, -- -- 
    ,
    .
 ,   .
    .
     .
     .
     .
     .
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
 
 string st,st1;

bool bad(char c)
{
 if (c=='W')return false;
 if (c=='Y')return false;
 if (c=='V')return false;
 if (c=='T')return false;
 if (c=='U')return false;
 if (c=='I')return false;
 if (c=='O')return false;
 if (c=='A')return false;
 if (c=='H')return false;
 if (c=='X')return false;
 if (c=='M')return false;
 return true;
}

 string solve()
 {
  if (st!=st1)
  {
   return "NO";
  }
  for (int i=0;i<st.size();i++)
   if (bad(st[i]))return "NO";
  return "YES";
 }
 
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
 cin>>st;
 st1=st;
 reverse(st1.begin(),st1.end());
 cout<<solve()<<endl;
 
cin.get();cin.get();
return 0;}