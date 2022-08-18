/*
Night is falling
Brothers in blood
Invincible in their faith

Deceiver, believer,
Stronger than steel
Insanity is what I feel

Here I stand
Take my hand
Let us flee
To be free

I'm a liar
I'm a sinner
I feel pain
Running through my veins

I'm a liar
I'm a sinner
I feel pain
Of my own destiny

Fighting, dying,
Revenge in blood
Listen to the tongues of hate

Destroyer, betrayer,
Witness of love
Sadness is my lonley fate

Here I stand
Take my hand
Let us flee
To be free

I'm a liar
I'm a sinner
I feel pain
Running through my veins

I'm a liar
I'm a sinner
I feel pain
Of my own destiny
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,d,a[20000],x[20000],y[20000],l,r,m,bst[20000];
long td;
queue<long> qu;
long temp;

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>d;
for (int i=2;i<n;i++)
cin>>a[i];
for (int i=1;i<=n;i++)
cin>>x[i]>>y[i];

l=0;
r=1e9;
while (l<r)
{
//      cout<<l<<" "<<r<<endl;
 m=l+r;
 m/=2;
 for (int i=1;i<=n;i++)
 bst[i]=-1e9;
 bst[1]=m;
 qu.push(1);
 while (qu.size())
 {
  temp=qu.front();
  qu.pop();
  for (int i=1;i<=n;i++)
  if (i!=temp)
  {
   td=abs(x[i]-x[temp])+abs(y[i]-y[temp]);
   td*=d;
   td-=a[i];
   if (bst[temp]-td>=0&&bst[temp]-td>bst[i])
   {qu.push(i);bst[i]=bst[temp]-td;}
  }
 }
 if (bst[n]>=0)r=m;
 else l=m+1;
}
cout<<l<<endl;

cin.get();cin.get();
return 0;}