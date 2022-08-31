/*
In their lofty chambers dwell 
The sacred and divine 
Resting in seraphic bliss 
The timeless and sublime 

Far above the mortal sphere 
Dreaming without a care 
Far above the weeping world 
Sleeping amidst the light of stars 

Too far away to hear our calls 
Too far away to care at all 

On the burnished thrones they sit 
Might in their blazing eyes 
Vault of heaven at their feet 
Undying flames inside 

Never shall decay or death 
Touch on the blithe souls 
Sorrowless the days of gods 
Amidst the everblooming groves 

But where do we lay our heads to rest? 
Where do we shelter when the night falls? 

For the part of man 
Is to take the sombre path 
Stumble in the dark 
Stray amidst the dust and ash 

Like forgotten ghosts 
Drifting in the driving wind 
Dashing towards the void 
Whirling blindly through the night 

Like water flung from the highest cliff 
We fall, 
lunge, 
swirl, 
dissolve, 
and fade away 
Down into the unknown
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define bsize 256

using namespace std;

long n,ar[20000],ans,v1,v2,cost,h,aspan,ah;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>ar[i];
}
sort(ar,ar+n);

ans=1e9;

for (int span=0;span<=25000;span++)
{
 v1=v2=ar[0];
 for (int i=1;i<n;i++)
 {
  v1=min(v1,ar[i]-i*span);
  v2=max(v2,ar[i]-i*span);
 } 
 h=(v1+v2)/2;
 cost=max(h-v1,v2-h);
 if (cost<ans)
 {
  ans=cost;
  aspan=span;
  ah=h;
 }
}

cout<<ans<<endl<<ah<<" "<<aspan<<endl;

cin.get();cin.get();
return 0;}