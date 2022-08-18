/*
The Order's end is near
Templars flee filled with fear
Heretics, homosexuals and magicians
To be exterminated by the inquisition
The order of Pope and King
Lets them leave behind everything

The fleet is ready, ready to sail
No one knows its destination
Gathering all the victims
Victims of persecution
In quest of a better world without hate without deadly peril

Over the sea
And far, far away
Over the sea
Into the night they flee

Many Templars succeeded to escape from the Christian hate
They found their peace in Scotland
Since Robert the Bruce was banned
When he stabbed Comyn in a church
Giving the Order shelter in the Highlands
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

string st;
long z[200][200];
bool can[10][10][100];
long ans;

bool cm(long a,long b,long tt)
{
    if (a<1||a>8||b<1||b>8)return 0;
    if (a-tt<0)return true;
    if (z[a-tt][b])return false;
    if (z[a-tt+1][b])return false;
    return true; 
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=8;i++)
{
 cin>>st;
 for (int j=1;j<=8;j++)
  if (st[j-1]=='S')
   z[i][j]=1;
}

can[8][1][0]=1;

for (int t=0;t<=50;t++)
 for (int i=1;i<=8;i++)
  for (int j=1;j<=8;j++)
  {
   if (can[i][j][t]==0)continue;
   if (i==1&&j==8)ans=1;
   if (cm(i+1,j,t+1))can[i+1][j][t+1]=1;
   if (cm(i-1,j,t+1))can[i-1][j][t+1]=1;
   if (cm(i,j-1,t+1))can[i][j-1][t+1]=1;
   if (cm(i,j+1,t+1))can[i][j+1][t+1]=1;
   
   if (cm(i-1,j+1,t+1))can[i-1][j+1][t+1]=1;
   if (cm(i+1,j+1,t+1))can[i+1][j+1][t+1]=1;
   if (cm(i-1,j-1,t+1))can[i-1][j-1][t+1]=1;
   if (cm(i+1,j-1,t+1))can[i+1][j-1][t+1]=1;
   if (cm(i,j,t+1))can[i][j][t+1]=1;
  }

if (ans)cout<<"WIN"<<endl;
else cout<<"LOSE"<<endl;

cin.get();cin.get();
return 0;}