/*
By day I sleep, at night I weep!

Ooh Death, come near me!
Be the one for me, be the one who stays.
My rivers are frozen, and mischosen,
and the shadows around me sickens my heart.

Ooh Death, come near me,
and stay (by my side). Hear my silent cry!
In sadness I'm veiled, to the cross I am nailed,
and the pain around me freezes my world.
My cold world...

In life I've failed,
for years I've wailed.
Frozen in time... left behind...
The rapture of grief is all to find...
The rapture of grief is all!

Behind the shadow of life the lost hopes are grieving.
I seek the night and hope to find love...
So I drown in the silence of lifes short eternity.
The tears fills the void in my heart astray...

Embrace me now, delightful ease!
Give me a world of wonderous peace!
Calm the desperate scream in my heart!

Ooh Death, come near me,
save me from this empty, cold world!
Ooh Life, you have killed me,
so spare me from this couldron of misery!

In life I cry, away I fly...
Chosen to fall within these walls.
The rapture of grief is all to find
The rapture of grief is all...

Ooh, shed a tear for the loss of innocense,
for the forsaken spirits who aches... in us.
Cry for the heart who surrenders to pain,
for the solitude of those left behind!

Behold the pain and sorrow of the world,
dream of a place away from this nightmare.
Give us love and unity, under the heart of night.
Oh Death, come near us, and give us life!
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long n,k,ans,ar[200][200],s,m;
long v1,v2,t1,t2;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cin>>ar[i][j];

ans=k+1;

if (m<=10)
{
 for (int mask=0;mask<(1<<m);mask++)
 {
  s=0;
  for (int j=0;j<m;j++)
   {if (ar[1][j+1]>0&&((mask&(1<<j))==0))++s;
   if (ar[1][j+1]==0&&((mask&(1<<j))>0))++s;}
  for (int i=2;i<=n;i++){t1=t2=0;
   for (int j=1;j<=m;j++)
   {
    v1=(mask&(1<<(j-1)));
    v2=ar[i][j];
    if (v1>1)v1=1;
    if (v1!=v2)++t1;else ++t2;
   }s+=min(t1,t2);}
   ans=min(ans,s);
 }
}
else
{
 for (int i=1;i<=n;i++)
 {
   s=0;
   for (int j=1;j<=n;j++)
    {t1=t2=0;
    for (int q=1;q<=m;q++)
    {
     if (ar[j][q]!=ar[i][q])++t1;else ++t2;
    }
    s+=min(t1,t2);
    }
   ans=min(ans,s);
 }
}
//cout<<ans<<endl;
if (ans>k)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}