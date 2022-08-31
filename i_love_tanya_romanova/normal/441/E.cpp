/*
    
    
     
    
   
    
    
 

  
  
     
  
  
   
    
  

    
    
     
   
    
    
    
 

   
  
    
     

   
  
   
     

  
*/

#pragma comment(linker, "/STACK:16777216")
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

using namespace std;

long x,k,p,calc,pp;
vector<long> tv;
double dp[2][512][250][2];
double p0,p1,answ;
long nrem;
long t;
pair<long, long> temp;

long gett(long x)
{
 long r=0;
 while (r<9&&x%2==0){r++;x/=2;}
 return r;
}
long avl;

pair<long, long> upd1(long sz,long tp,long nw)
{
 if (nw<512)avl=0;else avl=1;
 if (tp!=avl)sz=1;else sz++;
 if (sz>220)sz=220;
 return make_pair(sz,avl);
}

pair<long, long> upd2(long sz,long tp,long nw)
{
 if (nw<512)return make_pair(sz,tp);// no cngs
 if (tp==0)return make_pair(1,1);
 return make_pair(sz,0);          
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x>>k>>p;

calc=0;
pp=(x>>9);
while (pp>0){tv.push_back(pp%2);pp/=2;}
calc=0;
while (calc+1<=tv.size()&&tv[calc]==tv[0])
++calc;
if (calc==0)calc=1;

dp[0][x&511][calc][tv.size()>0&&tv[0]==1]=1.0;

for (int i=0;i<k;i++)
{
 for (int j=0;j<512;j++)
  for (int q=0;q<=225;q++)
   for (int e=0;e<=1;e++)
    dp[1-i%2][j][q][e]=0;
    
 for (int rem=0;rem<512;rem++)
  for (int ovr=1;ovr<=225;ovr++)
   for (int otp=0;otp<=1;otp++)
   {
    if (dp[i%2][rem][ovr][otp]<1e-60)continue;
    p0=dp[i%2][rem][ovr][otp]*p*.01;
    p1=dp[i%2][rem][ovr][otp]*(100-p)*.01;
    
    nrem=rem*2;
    temp=upd1(ovr,otp,nrem);
    nrem%=512;
    dp[1-i%2][nrem][temp.first][temp.second]+=p0;
    nrem=rem+1;
    temp=upd2(ovr,otp,nrem);
    nrem%=512;
    dp[1-i%2][nrem][temp.first][temp.second]+=p1;
   }
}

answ=0;
for (int rem=0;rem<512;rem++)
 for (int ovr=0;ovr<225;ovr++)
 {
  if (rem==0)t=9+ovr;
  else t=gett(rem);
  answ+=dp[k%2][rem][ovr][0]*t;
 }
for (int rem=0;rem<512;rem++)
 for (int ovr=0;ovr<225;ovr++)
 {
  t=gett(rem);
  answ+=dp[k%2][rem][ovr][1]*t;
 }

cout.precision(10);

cout<<fixed<<answ<<endl;

cin.get();cin.get();
return 0;}