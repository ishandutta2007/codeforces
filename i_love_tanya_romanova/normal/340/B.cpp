/*
Story starts, quiet town
Small town boy, big time frown
Never talks, never plays
Different path, lost his way

Dead streets are red, red I'm afraid
No confetti, no parade
Nothing happens in this boring place
But oh my god, how that all did change
Now they all pray
Blood stains wash away

He said "lost my way"
This bloody day
Lost my way
I heard him, he said "lost my way"
This bloody day
Lost my way
All things wash away
But blood stained the sun red today

I always said, somethin' wrong
With little strange Ronnie Long
Never laughed, never smiled
Talked alone, for miles and miles and miles

Gallow calls, son I say
Keep your smile, and laugh all day
Think once again, in this boring place
For little boys, how they soon change

Now they all pray
Blood stains wash away

He said "lost my way"
This bloody day
Lost my way
Yeah, I heard him, he said "lost my way"
This bloody day
Lost my way
All things wash away
But blood stained the sun red today

Yeah, well all the green things died
When Ronnie moved to this place
He said, "Don't you dare ask why
I'm cursed to wear this face"

Now we all know why children called him
Ronnie Frown
When he pulled that gun from his pocket
And they'd all fall down down down

He said "lost my way"
This bloody day
Lost my way
Yeah, I heard him, he screamed "lost my way"
This bloody day
Lost my way
All things wash away
But blood stained the sun red today
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
#include <memory.h>

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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long n,x[1000],y[1000],bl,br,ts,answ;

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>x[i]>>y[i];

for (int i=1;i<=n;i++)
for (int j=i+1;j<=n;j++)
{
 bl=br=-1;
 for (int q=1;q<=n;q++)
 {
     ts=(x[j]-x[i])*(y[q]-y[i])-(y[j]-y[i])*(x[q]-x[i]);
     if (ts<0){bl=max(bl,abs(ts));}
     else //if (ts>0)
     br=max(br,abs(ts));
 }
 if (bl>0&&br>0)
 answ=max(answ,bl+br);
}

cout<<fixed<<answ*0.5<<endl;

cin.get();cin.get();
return 0;}