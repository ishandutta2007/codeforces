/*
Here or there, above or below
it's always the same force which prevails
One must be unreal and surreal
to rise above the fear of isolation
one must accept exclusion
becoming stronger to face fate
Day after day
stone after stone
from disillusion to disillusion
defeat to defeat
escaping death for another death
I've built a temple within myself
where on my knees I wait the day
Born under Saturn
dchirer les cieux
Born under Saturn
sur terre rappeler Dieu
There is but a little time and the road is still long
become who you are, deny who you know...
Day after day
stone after stone
from disillusion to disillusion
defeat to defeat
escaping death for another death
I've built a temple within myself
where on my knees I wait the day
Born under Saturn
dchirer les cieux
Born under Saturn
sur terre rappeler Dieu
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