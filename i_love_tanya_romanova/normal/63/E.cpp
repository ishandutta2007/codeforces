/*
Brass hat, CEO
Only appears for a cameo
The camp is so clean
And it keeps raining green
The scent is strong
But yet something's wrong
Everything is too much right

Tension, need tension
God forsaken
Godawful place
The falling house of cards
That I love to embrace
I'm saving face

Four star everything's comped
We steer the peddlers clear
Lessons in decorum given out
First class, top notch, no fear
Announcing every heroic feat
Large praise and make it quick
Good as it is it's never great
This health is making me sick

Wrapped up the report is done
The addle brained just can't get enough
The scent is strong but yet something is wrong
Everything just ain't right
This house of cards is erasing my face
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
#define eps 1e-7
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

long pos[20][20];
vector<long> moves;
long tmask;
long q,w;
string st;
long temp;
long start;
long win[1000000];
long l[10],r[10];

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=6;i++)
for (int j=1;j<=6;j++)
pos[i][j]=-1;

pos[1][1]=0;pos[1][2]=1;pos[1][3]=2;
pos[2][1]=3;pos[2][2]=4;pos[2][3]=5;pos[2][4]=6;
pos[3][1]=7;pos[3][2]=8;pos[3][3]=9;pos[3][4]=10;pos[3][5]=11;
pos[4][2]=12;pos[4][3]=13;pos[4][4]=14;pos[4][5]=15;
pos[5][3]=16;pos[5][4]=17;pos[5][5]=18;

l[1]=1;r[1]=3;
l[2]=1;r[2]=4;
l[3]=1;r[3]=5;
l[4]=2;r[4]=5;
l[5]=3;r[5]=5;

for (int i=1;i<=5;i++)
for (int j=1;j<=5;j++)
if (pos[i][j]+1)
{
 tmask=(1<<pos[i][j]);
 moves.push_back(tmask);
 q=i;w=j;      
 while (pos[q+1][w+1]+1)
 {
  ++q;++w;
  tmask|=(1<<pos[q][w]);
  moves.push_back(tmask);
 }
 
 tmask=(1<<pos[i][j]);
 q=i;
 w=j;
 while (pos[q+1][w]+1)
 {
  ++q;
  tmask|=(1<<pos[q][w]);
  moves.push_back(tmask);
 }
 
 tmask=(1<<pos[i][j]);
 q=i;
 w=j;
 while (pos[q][w+1]+1)
 {
  ++w;
  tmask|=(1<<pos[q][w]);
  moves.push_back(tmask);
 }
}

for (int i=1;i<=5;i++)
for (int j=l[i];j<=r[i];j++)
{
    cin>>st;
    if (st[0]=='O')start|=(1<<pos[i][j]);
}

win[0]=0;
for (int mask=1;mask<(1<<19);mask++)
{
 win[mask]=0;
 for (int j=0;j<moves.size();j++)
 {
     temp=moves[j];
     if ((mask&temp)==temp)
     if (win[mask-temp]==0)
     win[mask]=1;
 }
}

//cout<<win[start]<<endl;
if (win[start])cout<<"Karlsson"<<endl;
else cout<<"Lillebror"<<endl;

cin.get();cin.get();
return 0;}