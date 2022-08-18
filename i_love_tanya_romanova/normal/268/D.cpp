/*
A time in the future, not too far away
The death of our world, we are told
Destroyed by neglect, now breeding despair
The home of mankind is despoiled
Polluted oceans, unbreathable air
The life of the land under siege
Cancer is spreading and wasting the world
And mankind is now the disease

Look upon the world you knew
And say goodbye, it dies with you
Those who live when we are dead
Will curse our names, they 've inherited Hell

The forests are gone and the ocean destroyed
The world we once knew now is dead
The animals slaughtered, wild life in its grave
The sun burns too bright overhead
Cities collapsing and famine runs rampant
A nightmare where once there was life
Radiation and toxins a part of the children
Who will hate us until they die

We never stopped to think or reflect
On what we have done to the world
The heritage we live our children is Hell
A short life in pain what we mold
We 've squandered resources and wasted the land
And left little for those to come
They will have nothing to claim for their own
Except for the Hell we have shown
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long dp[5][5][40][40][40];

long long n,h;
long long answ;

long move(long x)
{
 if (x==0)return x;
 if (x+1==h)return 0;
 return x+1;
}

bool isok(long hh,long x)
{
 if (x>0)return 1;
 if (hh<h)return 1;
 return 0;
}

int main(){
//freopen("scanner.in","r",stdin);
//freopen("scanner.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

dp[1][1][0][0][0]=4;
cin>>n>>h;
for (int qh=1;qh<=n;qh++)
{
    
 for (int i=0;i<=h;i++)
  for (int j=0;j<=h;j++)
   for (int q=0;q<=h;q++)
    {dp[1-qh%2][1][i][j][q]=0;dp[1-qh%2][0][i][j][q]=0;
     while (dp[qh%2][1][i][j][q]>=bs)dp[qh%2][1][i][j][q]-=bs;
     while (dp[qh%2][0][i][j][q]>=bs)dp[qh%2][0][i][j][q]-=bs;
    }
      
 for (int i=0;i<=h;i++)
  for (int j=0;j<=h;j++)
   for (int q=0;q<=h;q++)
    if (dp[qh%2][0][i][j][q]+dp[qh%2][1][i][j][q])
    {
       dp[(qh+1)%2][1][move(i)][move(j)][move(q)]+=dp[qh%2][1][i][j][q];// same
       dp[(qh+1)%2][0][move(i)][move(j)][move(q)]+=dp[qh%2][0][i][j][q];
        
       dp[(qh+1)%2][isok(qh,i)][0][move(j)][move(q)]+=dp[qh%2][0][i][j][q];
       dp[(qh+1)%2][isok(qh,i)][(h==1?0:1)][move(j)][move(q)]+=dp[qh%2][1][i][j][q];
       
       dp[(qh+1)%2][isok(qh,j)][0][move(i)][move(q)]+=dp[qh%2][0][i][j][q];
       dp[(qh+1)%2][isok(qh,j)][(h==1?0:1)][move(i)][move(q)]+=dp[qh%2][1][i][j][q];
       
       dp[(qh+1)%2][isok(qh,q)][0][move(j)][move(i)]+=dp[qh%2][0][i][j][q];
       dp[(qh+1)%2][isok(qh,q)][(h==1?0:1)][move(j)][move(i)]+=dp[qh%2][1][i][j][q];
   }   
}

for (int i=0;i<=h;i++)
 for (int j=0;j<=h;j++)
  for (int q=0;q<=h;q++)
  {
      if (i||j||q)answ+=dp[n%2][0][i][j][q];
     // cout<<i<<" "<<j<<" "<<q<<" "<<dp[n%2][0][i][j][q]<<" "<<
     // dp[n%2][1][i][j][q]<<endl;
      answ+=dp[n%2][1][i][j][q];
  }
  cout<<answ%bs<<endl;
  
cin.get();cin.get();
return 0;}