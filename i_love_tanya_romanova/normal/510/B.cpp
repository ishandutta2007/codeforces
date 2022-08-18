/*
  
 ,   , 
 
     
   
      
 
    

:
   
     
  
  ,   

   
     
  
     
   
    
   
      

 (2)

   
     
   
    
   
    
   
      


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
string st;
long cycle;
long ar[100][100];
long used[100][100];

long gpa,gpb;
long ga,gb;

bool hot(long a,long b)
{
 if (a==gpa&&b==gpb)return false;
 return used[a][b]==1;
}

bool cmove(long a,long b)
{
 if (a<1||a>n||b<1||b>m||ar[a][b]!=ar[ga][gb])return false;
 if (a==gpa&&b==gpb)return false;
 if (used[a][b])return false;
 return true;
}

void dfs(long a,long b,long pa,long pb)
{
 gpa=pa;
 gpb=pb;
 ga=a;
 gb=b;
 used[a][b]=1;
 
 if (hot(a-1,b)||hot(a+1,b)||hot(a,b-1)||hot(a,b+1))
  cycle=1;
 
 if (cmove(a-1,b))
  dfs(a-1,b,a,b);
 if (cmove(a+1,b))
  dfs(a+1,b,a,b);
 if (cmove(a,b-1))
  dfs(a,b-1,a,b);
 if (cmove(a,b+1))
  dfs(a,b+1,a,b);
  
 used[a][b]=2;
}

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
 cin>>st;
 for (int j=1;j<=m;j++)
  ar[i][j]=st[j-1]-48;
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  if (used[i][j]==0)
  {
   dfs(i,j,i,j);
  }
 }

if (cycle)
cout<<"Yes"<<endl;
else cout<<"No"<<endl;

cin.get();cin.get();
return 0;}