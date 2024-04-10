/*
Come break my bones, come spread my ashes.
Come wear me down, come wear me down.

In life a king, in death a failure.
Come help me cry, come help me cry.

"I wanted to be changed by the road.
I so wanted to change the road.
But somehow we both resisted change.
Somehow we were both too strong.
And yet we both winded away, unsure of where we head.
And it's like we're both confused as to who is who.
As if, late in the night, you can't tell the runner from the road - the walker from the walked.
Maybe I am just the road, dreaming the I walk"

Dust in my throat, dust in my nostrils.
Dust in my mouth, dust in my eyes.
From dust I come, through dust I wander.
Dust I'll remain - dust all I am.
Dust I'll remain - dust all I am.
Dust I'll remain - dust all I am.
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

using namespace std;

string st1,st2,st3;
long x1,y1,x2,y2,x3,y3,beat[2000][200],used[200][200],er;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1;
cin>>st2;
x1=st1[0]-'a'+1;
y1=st1[1]-'0';
x2=st2[0]-'a'+1;
y2=st2[1]-'0';

cin>>st3;
x3=st3[0]-'a'+1;
y3=st3[1]-'0';
used[x1][y1]=1;
used[x2][y2]=1;
used[x3][y3]=1;

for (int i=x1-1;i>=1;--i)
{
beat[i][y1]=1;
if (used[i][y1])break;
}
for (int i=x1+1;i<=8;++i)
{
beat[i][y1]=1;
if (used[i][y1])break;
}
for (int i=y1-1;i>=1;--i)
{
beat[x1][i]=1;
if (used[x1][i])break;
}
for (int i=y1+1;i<=8;++i)
{
beat[x1][i]=1;
if (used[x1][i])break;
}

for (int i=x2-1;i>=1;--i)
{
beat[i][y2]=1;
if (used[i][y2])break;
}
for (int i=x2+1;i<=8;++i)
{
beat[i][y2]=1;
if (used[i][y2])break;
}
for (int i=y2-1;i>=1;--i)
{
beat[x2][i]=1;
if (used[x2][i])break;
}
for (int i=y2+1;i<=8;++i)
{
beat[x2][i]=1;
if (used[x2][i])break;
}

for (int i=1;i<=8;i++)
 for (int j=1;j<=8;j++)
  if (abs(i-x3)<=1&&abs(j-y3)<=1&&abs(i-x3)+abs(j-y3)>0)
   beat[i][j]=1;

cin>>st1;
x1=st1[0]-'a'+1;
y1=st1[1]-'0';

er=0;
/*
for (int i=1;i<=8;i++)
{
    for (int j=1;j<=8;j++)
  cout<<beat[i][j];
  cout<<endl;
}*/

for (int i=1;i<=8;i++)
 for (int j=1;j<=8;j++)
  if (abs(i-x1)<=1&&abs(j-y1)<=1)
   if (beat[i][j]==0)er=1;

if (er)cout<<"OTHER"<<endl;
else cout<<"CHECKMATE"<<endl;

cin.get();cin.get();
return 0;}