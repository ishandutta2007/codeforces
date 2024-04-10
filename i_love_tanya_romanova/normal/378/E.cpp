/*
My eyes seek reality
My fingers seek my veins
Theres a dog at your back step
He must come in from the rain

I fall cause I let go
The net below has rot away
So my eyes seek reality
And my fingers seek my veins

The trash fire is warm
But nowhere safe from the storm
And I can't bare to see
What I've let me be
So wicked and worn

So as I write to you
Of what is done and to do
Maybe you'll understand
And won't cry for this man
'Cause low man is due

Please forgive me

My eyes seek reality
My fingers feel for faith
Touch clean with a dirty hand
I touched the clean to the waste

The trash fire is warm
But nowhere safe from the storm
And I can't bare to see
What I've let me be
So wicked and worn

So as I write to you
Of what is done and to do
Maybe you'll understand
And won't cry for this man
'Cause low man is due

Please forgive me
Please forgive me
Please forgive me

So low the sky is all I see
All I want from you is forgive me
So you bring this poor dog in from the rain
Though he just wants right back out again

And I cry, to the alley way
Confess all to the rain
But I lie, lie straight to the mirror
The one I've broken, to match my face

The trash fire is warm
But nowhere safe from the storm
And I can't bare to see
What I've let me be
So wicked and worn

So as I write to you (yeah)
Of what is done and to do (yeah)
Maybe you'll understand
And won't cry for this man
'Cause low man is due

Please forgive me
Please forgive me

So low the sky is all I see
All I want from you is forgive me
So you bring this poor dog in from the rain
Though he just wants right back out again

My eyes seek reality
My fingers seek my veins
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string temp;
long n,m,mv[2000];
long tp[2000];
char ans1[22][1100000];
long ans2[22][1100000];
long cost[2000];

long solve(long a,long b)
{
 if (a==m)return 0;
 if (ans1[a][b])return ans2[a][b];
 ans1[a][b]=1;
 // pUt d
 
 long qbest;
 
 if (mv[a]==1)qbest=-1e9;
  else qbest=1e9;// h P7
 
 long tscore;
 
 for (int i=0;i<m;i++)
  if ((b&(1<<i))==0)
   {
    tscore=solve(a+1,b|(1<<i));//gb
    if (tp[a]==1)
    {
     if (mv[a]==1)tscore+=cost[i];
     else tscore-=cost[i];
    }
    if (mv[a]==1)qbest=max(tscore,qbest);
    else qbest=min(tscore,qbest);// mm|min
   }     
 
 /*if (tp[a]==2)// qPout
 {
  tscore=solve(a+1,b);
  if (mv[a]==1)qbest=max(tscore,qbest);
  else qbest=min(tscore,qbest);
 }
 */
 ans2[a][b]=qbest;//done
 return qbest;
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
  
cin>>n;
for (int i=0;i<n;i++)
cin>>cost[i];
sort(cost,cost+n);
reverse(cost,cost+n);

cin>>m;
/*for (int i=0;i<=m;i++)
 for (int mask=0;mask<(1<<m);mask++)
 {
     ans1[i][mask]=0;
 }
 */
 
 for (int i=0;i<m;i++)
 {
     cin>>temp;
     if (temp=="p")tp[i]=1;else tp[i]=2;
     cin>>mv[i];
 }
 
 cout<<solve(0,0)<<endl;
 
cin.get();cin.get();
return 0;}