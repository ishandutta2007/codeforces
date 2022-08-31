/*

I see my red door and I want it painted black
No colors anymore I want them to turn black

I see the girls walk by dressed in their summer clothes
I have to turn my head until my darkness goes

I see a line of cars and they're all painted black
With flowers and my love both never to come back

I see people turn their heads and quickly look away
Like a new born baby it just happens every day

I look inside myself and see my heart is black
I see my red door, I must have it painted black

Maybe then I'll fade away and not have to face the facts
It's not easy facin' up when your whole world is black

No more will my green sea go turn a deeper blue
I could not foresee this thing happening to you

If I look hard enough into the settin' sun
My love will laugh with me before the mornin' comes

I see a red door and I want it painted black
No colors anymore I want them to turn black

I see the girls walk by dressed in their summer clothes
I have to turn my head until my darkness goes

I wanna see your face, painted black
Black as night, black as coal

I wanna see the sun blotted out from the sky
I wanna see it painted, painted, painted, painted black
Yeah!
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
//#include <memory.h>

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
//#define N 120000

using namespace std;

long pw[1200000],ps,q,ttl[1200000];
long res,n,temp;
long ar[1200000];

long cb(long x)
{
 long s=0;
 for (int i=0;i<=21;i++)
 if (x&(1<<i))++s;
 return s;
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pw[0]=1;
for (int i=1;i<=(1<<20);i++)
 pw[i]=pw[i-1]*2%bs;

cin>>n;
for (int i=1;i<=n;i++)
{cin>>ar[i];ttl[ar[i]]++;}


for (int bit=20;bit>=0;bit--)
{
 for (int j=(1<<bit);j<=(1<<20);j++)
 if (j&(1<<bit))
  ttl[j-(1<<bit)]+=ttl[j];
 /*
 for (int j=0;j<=4;j++)
  cout<<ttl[j]<<" ";
  cout<<endl;*/
}
/*
for (int i=0;i<=4;i++)
 cout<<i<<"  "<<ttl[i]<<endl;
 */
res=pw[n];
res=res-1+bs;
res%=bs; // all

for (int i=1;i<=(1<<20);i++)
{
 temp=pw[ttl[i]];
 temp--;
 temp+=bs;
 temp%=bs; // clc & i
 if (cb(i)%2)res-=temp;
 else res+=temp;
 res=res%bs;
 if (res<0)res+=bs;
}
cout<<res<<endl;

cin.get();cin.get();
return 0;}