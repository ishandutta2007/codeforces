/*
  ,    `  ?
      .
      ,
 ,    .

  
    
   .
  
     
  ,
   ...

       
      
   -      
 ,     .

  
    
   .
  
     
  ,
   ...
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long long pw[1<<23],s[5555555],sr[5555555],pal[1<<23];
string st,st1;
long p,q;
long long v1,v2,ans;

long long gett(long l,long r)
{
 long long res=s[r];
 res-=s[l-1];
 res*=pw[(1<<23)-l-5];
 return res;
}

long long gettr(long l,long r)
{
 l=st.size()-l+1;
 r=st.size()-r+1;
 swap(l,r);
 long long res=sr[r];
 res-=sr[l-1];
 res*=pw[(1<<23)-l-5];
 return res;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

getline(cin,st);
st1=st;
reverse(st1.begin(),st1.end());

pw[0]=1;
for (int i=1;i<(1<<23);i++)
 pw[i]=pw[i-1]*173;

for (int i=1;i<=st.size();i++)
 s[i]=s[i-1]+st[i-1]*pw[i];

for (int i=1;i<=st1.size();i++)
 sr[i]=sr[i-1]+st1[i-1]*pw[i];
 
pal[1]=1;

for (int i=2;i<=st.size();i++)
{
    p=i/2;
    q=i-p+1;
    
    v1=gett(1,p);
    v2=gettr(q,i);
    if (v1!=v2)
    pal[i]=0;
    else pal[i]=pal[p]+1;
}

for (int i=1;i<=st.size();i++)
 ans+=pal[i];
cout<<ans<<endl;

cin.get();cin.get();
return 0;}