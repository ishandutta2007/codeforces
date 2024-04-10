/*
    
      
     
    

    
    
     
    
    

    
   
     
   

    
    
      
       

H     
    
     
    
    

    
   
     
   

      
       
H          
     
         

H     
    
     
    
    

    
   
     
   

    
   
     
   
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,k,a,b,temp,answ;
long w[1<<20];
long cost[1<<20];
long r;

long get(long x)
{
 if (x==w[x])return w[x];
 long temp=get(w[x]);
 cost[x]+=cost[w[x]];
 cost[x]%=bs;
 w[x]=temp;
 return temp;
}

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;

for (int i=1;i<=n;i++)
{
 cin>>k;
 w[i]=i;
 for (int j=1;j<=k;j++)
 {
  cin>>a>>b;
  if (b<0)b+=bs;
  r=get(a);
  temp=cost[a];
  temp+=b;
  temp%=bs;
  answ+=temp;
  answ%=bs;
  if (answ<0)answ+=bs;
 // cout<<r<<"   "<<i<<" "<<temp<<" "<<cost[a]<<endl;
  w[r]=i;
  cost[r]=temp;
 }
}
cout<<answ<<endl;

cin.get();cin.get();
return 0;}