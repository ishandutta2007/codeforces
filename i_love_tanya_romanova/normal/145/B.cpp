/*
Shadows dance 
on visions fabric veil
Reality becomes obsolete
as I walk through the wormholes
Through the forlorn stars
by thoughts gone too far
So many realms held
open in this night

I will forsake the light
the guiding lifelight of humans
For I have learned to look this life
from the aspects of the stars

"No rest under the cross
No solace for the wanderer's heart
Reach deep within
to darkness beyond the stars
How far one can wander
into the dreams of the dead?"

A soul eternal
tied into this flesh and skin
an old wandering soul
from the darkness beyond the stars
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long a1,a2,a3,a4;

string solve()
{
 string res;
 if (abs(a3-a4)>1)return "-1";
 if (a3<a4)
 {
  res="";
  for (int j=1;j<=a4;j++)
   res+="74";
 }
 else
 {
  res="";
  for (int j=1;j<=a3;j++)
  {
   res+="47";
  }
  if(a3==a4)res+="4";
 }
 
 //-------------
 if (a3==a4) // 2ways
 {
  if (a1==a3&&a1<a2)
  {
   for (int i=0;i<res.size();i++)
    if (res[i]=='4')res[i]='7';else res[i]='4';
  }
 }
 
// cout<<res<<endl;
 for (int j=0;j<res.size();j++) 
  if (res[j]=='4')--a1;
  else --a2;
 if (a1<0||a2<0)return "-1";
 
 long f4,l7;
 f4=1e9;
 l7=-1;
 
 string st=res;
// cout<<res<<endl;
 for (long i=0;i<st.size();i++)
 {
  if (st[i]=='4')f4=min(f4,i);
  else l7=max(l7,i);
 }
 
 res="";
 for (int i=0;i<st.size();i++)
 {
     res+=st[i];
     if (i==f4)for (int j=0;j<a1;j++)
      res+='4';
     if (i==l7)for (int j=0;j<a2;j++)
      res+='7';  
 }
 return res;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a1>>a2>>a3>>a4;
cout<<solve()<<endl;

cin.get();cin.get();
return 0;}