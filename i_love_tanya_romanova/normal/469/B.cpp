/*
Once there was a time of a never-ending dream
Of being free, of immortality
When a song was a mystery
And the stars so easy to reach
But something changed now the sand's trickling slow
The time of innocence is over now

I know the rivers won't be flowing on forevermore
The wind of time blows right into my eyes
My flower withers and so do they all
Nothing lasts forevermore

Why is my fate that I will never see
The story's end, the final truth to be
And to you lights that help me through the dark
My greatest fear is losing your spark

I know the rivers won't be flowing on forevermore
The wind of time blows right into my eyes
My flower withers and so do they all
Nothing lasts forevermore

I see the days go by and feel the snow is falling down
I've seen the end is waiting by my side
The dream is lost, once I was told
It's gone forevermore

I know the rivers won't be flowing on forevermore
The wind of time blows right into my eyes
My flower withers and so do they all
Nothing lasts forevermore
Forevermore
Forevermore
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

using namespace std;

long p,q,l,r,a[1<<10],b[1<<10],er,ans;
long c[1<<10],d[1<<10];

bool inter(long l1,long r1,long l2,long r2)
{
 return max(l1,l2)<=min(r1,r2);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>p>>q>>l>>r;
for (int i=1;i<=p;i++)
 cin>>a[i]>>b[i];
for (int i=1;i<=q;i++)
 cin>>c[i]>>d[i];

for (int i=l;i<=r;i++)
{
 er=0;
 for(int aa=1;aa<=p;aa++)
  for (int bb=1;bb<=q;bb++)
   if (inter(a[aa],b[aa],c[bb]+i,d[bb]+i))
   er=1;
  ans+=er;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}