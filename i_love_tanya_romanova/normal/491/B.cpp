/*
There are secrets that you keep
There are secrets that you keep
There are secrets that you tell to me alone

I can't reach things I can't see
You don't see this strange world
Quite the same as me

Don't deny me what I am
Nothing hidden still you fail to see the truth
These are things you can't reveal
These are things you can't reveal

We are part of some strange plan
Why the slaughter of the 'Brotherhood Of Man?'
Infernal sacrifice of hell

Fire breathing, lead the way
Mounds of bodies as they all burn into one
Revenge is living in the past
Time to look into a new millennium

Spiral path leads through the maze
Down into the fiery underworld below
Fire breathing, lead the way
Lucifer was just an angel led astray

Free your soul and let it fly
Give your life to the Lord of Light
Keep your secrets and rain on me
All I see are mysteries

Free your soul and let it fly
Give your life to the Lord of Light
Keep your secrets and rain on me
All I see are mysteries

We are not worthy in your black
And blazing eyes
We gather demons in the mirror every day
The bridge of darkness casts
A shadow on us all
All our sins to you we give this day

Others wait their turn
Their lives were meant to last
Use yours wisely as the light is fading fast
Free your soul and let if fly
Mine was caught, I couldn't try
Time returns again to punish all of us

We are cast out by our bloody father's hand
We are strangers in this lonely promised land
We are the shadows of the one unholy ghost
In our nightmare world, the only one we trust

Free your soul and let it fly
Give your life to the Lord of Light
Keep your secrets and rain on me
All I see are mysteries

Free your soul and let it fly
Give your life to the Lord of Light
Keep your secrets and rain on me
All I see are mysteries
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long n,m,x1[1<<20],y1[1<<20],x2[1<<20],y2[1<<20];
long long a,b;
long long l,r;
long long mid;
long long lx,rx,ly,ry;
long long tx1,ty1,tx2,ty2;

long long check(long long l)
{
 lx=-1e9;
 rx=2e9;
 ly=-1e9;
 ry=2e9;
 for (int i=1;i<=n;i++)
 {
  tx1=x1[i]-l;
  tx2=x1[i]+l;
  ty1=y1[i]-l;
  ty2=y1[i]+l;
  lx=max(lx,tx1);
  rx=min(rx,tx2);
  ly=max(ly,ty1);
  ry=min(ry,ty2);
 }
 for (int i=1;i<=m;i++)
 {
  if (x2[i]>=lx&&x2[i]<=rx&&y2[i]>=ly&&y2[i]<=ry)
   return i;
 }
 return -1;
}

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>n;
for (int i=1;i<=n;i++)
 {
         cin>>a>>b;
         x1[i]=a+b;
         y1[i]=a-b;
 }
cin>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    x2[i]=a+b;
    y2[i]=a-b;
}

l=0;
r=2e9;

while (l<r)
{
 mid=l+r;
 mid/=2;
 if (check(mid)!=-1) r=mid;
 else l=mid+1;
}

cout<<l<<endl<<check(l)<<endl;

cin.get();cin.get();
return 0;}