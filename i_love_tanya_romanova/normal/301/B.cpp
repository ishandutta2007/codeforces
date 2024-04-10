/*
Steal my sight and then
Fill my mind with foreign words
To keep me wanting
And speak now, child
And chill my heart with all the hurt
And keep me suffering

All these promises
Lectures and bold-faced lies
All these promises
Born of a shameless mind

Leave me to heal on my own
With those empty cruel promises
You stole my dreams
Yeah all my dreams are dead inside
Please let me feel my way home
Without reason or compromise
You stole my dreams
Now all I believe is dead inside

Be quick now, child
And soil my bed with all your dirt
Just keep me suffering

All these promises
Lectures and bold-faced lies
All these promises
Born of a shameless mind

Leave me to heal on my own
With those empty cruel promises
You stole my dreams
Yeah all my dreams are dead inside
Please let me feel my way home
Without reason or compromise
You stole my dreams
Now all I believe is dead inside

Dont let me sleep, take me back
But dont let me be comfortable
If I get too weak (please let me feel my way home)
Cut no slack, and dont let me be comfortable
Dont let me sleep (please let me feel my way home)
Take me back, but dont let me be comfortable

Leave me to heal on my own
With those empty cruel promises
You stole my dreams
Yeah all my dreams are dead inside
Please let me feel my way home
Without reason or compromise
You stole my dreams
Now all I believe is dead inside

If you say youre alive (please let me feel my way home)
When you pray youre alive
Oh you hate when Im right (please let me feel my way home)
And you lay in the fire
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