/*
I was alone
I was tied
And you saved me
You set my heart on fire
You gave me life
Now you rise
Headed for the Sun
And I know Im right behind you
Live like you feel
Reach for the unknown
And know my fire is always with you
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

long n,k,ar[1<<20];
double dp[250][44][44];

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;

for (int i=0;i<n;i++)
 cin>>ar[i];
 
for (int i=0;i<n;i++)
{
 for (int j=i;j<n;j++)
 {
   dp[0][i][j]=(ar[i]>ar[j]);
 }
}

double ans=0;
long ttl=n*(n+1)/2;

for (int i=0;i<k;i++)
{
    for (int l=0;l<n;l++)
     for (int r=l;r<n;r++)
     {
      for (int a=0;a<n;a++)
       for (int b=a;b<n;b++)
       {
        long na,nb;
        
        if (a>=l&&a<=r&&b>=l&&b<=r)
        {
         na=l+(r-a);
         nb=l+(r-b);
         dp[i+1][nb][na]+=(1.0-dp[i][a][b])*1.0/ttl;
        }
        else 
        {
         if (a>=l&&a<=r)
          na=l+(r-a);
         else na=a;
         if (b>=l&&b<=r)
          nb=l+(r-b);
          else nb=b;
         dp[i+1][na][nb]+=dp[i][a][b]*1.0/ttl;
        }
       }   
     }
}

for (int i=0;i<n;i++)
 for (int j=i+1;j<n;j++)
   ans+=dp[k][i][j];

cout.precision(9);

cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}