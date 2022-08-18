/*
Watch your tongue or have it cut from your head
Save your life by keeping whispers unsaid
Children roam the streets now orphans of war
Bodies hanging in the streets to adore

Royal flames will carve the path in chaos
Bringing daylight to the night
Death is riding in the town with armor
Because thail take all your rights

Hail to the king, hail to the one
Kneel to the crown, stand in the sun
Hail to the king (hail, hail, hail, the king)

Blood is spilled while holding keys to the throne
Born again, but it's too late to atone
No mercy from the edge of the blade
Thail'll escape and learn the price to be paid

Let the water throw it's shades of red now
Arrows black out all the light
Death is rotting in the town with armor
Thail've come to grant you your rights

Hail to the king, hail to the one
Kneel to the crown, stand in the sun
Hail to the king (hail, hail, hail, the king)

There's a taste of fear (hail, hail, hail)
When the henchmen call (hail, hail, hail)
Iron fist to tame them (hail, hail, hail)
Iron fist to claim it all (hail, hail, hail)

Hail to the king, hail to the one
Kneel to the crown, stand in the sun

Hail to the king, hail to the one
Kneel to the crown, stand in the sun
Hail to the king (hail, hail, hail)
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

long s,t;
vector<long> ans;
long p;
long gett(long x)
{
 long r=1;
 while ((x&r)==0)r*=2;
 return r;
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>s>>t;
for (int i=t;i;--i)
{
 p=gett(i);
 if (s>=p){ans.push_back(i);s-=p;}
}

if (s)cout<<-1<<endl;
else
{
 cout<<ans.size()<<endl;
 for (int i=0;i<ans.size();i++)
 {
  if (i)cout<<" ";
  cout<<ans[i];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}