/*
Belonging to an alliance
For better or for worse
Disloyalty gets punished
If you tear down the wall
Your strength of will, built on sand
Pootprints on your face
No dream and no reality
Will save you from yourself
No dream and no reality
Will save you from yourself

Code Red...

Discriminated without permission
Against the chosed one
Who was your bother hand in hand
When the war began
Infecting total facism
To a crawling wimp
They let you run the gauntlet
And worship their defeat
They let you run the gauntlet
And worship their defeat

Code Red...

Exasperated defamations
Barbarian rebirth
Mobilized the inner beast
Indulge your natural curse
Reclaiming of your dignity
Privacy lost in cries
Unheard, pounding screams of hate
At the wall of lies
Unheard, pounding screams of hate
At the wall of lies

Code Red...
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

long n,m,k,ar[1100][1100],s1[1100][1100],s2[1100][1100];
long long temp;
long long tsum[2000];

long s;
long long atemp,aa,ab;
long mx;

int main(){
//freopen("scanner.in","r",stdin);
//freopen("scanner.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  {cin>>ar[i][j];mx=max(mx,ar[i][j]);}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 s1[i][j]=s1[i-1][j-1]+ar[i][j];

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  s2[i][j]=s2[i-1][j+1]+ar[i][j];
  
  atemp=-1;
  
  for (int i=k-1;i;--i)
  tsum[i]=tsum[i+1]+4*i*(k-i);
  
for (int a=k;a<=n-k+1;a++)
 for (int b=k;b<=m-k+1;b++)
 {
     
     temp=ar[a][b]*k+ar[a-1][b]*(k-1)+ar[a+1][b]*(k-1)+ar[a][b-1]*(k-1)+ar[a][b+1]*(k-1);
    // cout<<" "<<a<<" "<<b<<" "<<temp<<endl;
     for (int span=2;span<k;span++)
     {
      if (temp+1ll*tsum[span]*mx<=atemp)break;
      s=s1[a][b+span]-s1[a-span-1][b-1];
      s+=s1[a+span][b]-s1[a-1][b-span-1];
      temp+=1ll*s*(k-span);
      s=s2[a-1][b-span+1]-s2[a-span][b];
      s+=s2[a+span-1][b+1]-s2[a][b+span];
   //    cout<<a<<" "<<b<<" "<<s<<endl;
     temp+=1ll*s*(k-span); 
      
     }
 //    cout<<a<<" "<<b<<" "<<temp<<endl;
     if (temp>atemp){atemp=temp;aa=a;ab=b;}
 }
 cout<<aa<<" "<<ab<<endl;
 
cin.get();cin.get();
return 0;}