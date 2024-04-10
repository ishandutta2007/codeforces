/*
    
     
    
    

:
  
  
  
   

   
 ,  
     
    
   
  
    
   



   
    
   
    
     
    
  
  


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
#define MAG 10000

using namespace std;

long n,m;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
 {
  if (i%4==1||i%4==3)
  {
   cout<<"#";continue;
  }
  if (i%4==2&&j==m){
   cout<<"#";continue;}
   if (i%4==0&&j==1)
    {cout<<"#";continue;}
   cout<<".";
 }
 cout<<endl;
}
 
cin.get();cin.get();
return 0;}