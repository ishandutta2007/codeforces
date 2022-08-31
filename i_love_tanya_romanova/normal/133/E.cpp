/*
Wake up! They try to steal the man in your head
make you kneel in front of icons
They took the place which wasn't theirs
enslave you with a power they don't have
don't need to be guided
their lambs become rams
tell them the universe hides inside us all
Ein Volk, ein Reich, ein Fhrer...
is it what you got
or is it what they made
holy war for holy fools
blessed are those who break the rules
Men drink the scum of rage
at the lips of warrior priests
what happened, happened again
as no one gets; you cannot win
if someone lost
Streams of blood drown soldiers' hate
but mothers' tears call sons' revenge
Stay away from the sectarian and gregarious
if you want to keep the precious gift we share
be right to yourself, be your own judge
and know, non-resolved things
generate themselves over and over...
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

bool can[105][105][220][2];
long mv[10];
string st;
long li;
long n;
long ans;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

can[0][0][100][0]=1;
cin>>st;
cin>>li;
n=st.size();

mv[0]=1;
mv[1]=-1;

for (int i=0;i<n;i++)
 for (int ch=0;ch<=i;ch++)
  for (int ps=0;ps<=199;ps++)
   for (int dir=0;dir<=1;dir++)
   {
    if (can[i][ch][ps][dir]==0)continue;
    if (st[i]=='F')
    {
     can[i+1][ch][ps+mv[dir]][dir]=1;
     can[i+1][ch+1][ps][1-dir]=1;
    }
    else
    {
     can[i+1][ch+1][ps+mv[dir]][dir]=1;
     can[i+1][ch][ps][1-dir]=1; 
    }
   }

ans=0;

long d=100;

for (int i=0;i<=200;i++)
 for (int j=li;j>=0;j-=2)
  for (int dir=0;dir<=1;dir++)
   if (can[n][j][i][dir])
   {
//    cout<<i<<" "<<j<<" "<<dir<<endl;
    ans=max(ans,abs(d-i));
   }
  
cout<<ans<<endl;

cin.get();cin.get();
return 0;}