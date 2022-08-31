/*
Secluded by generalities
No eyes saw them before
Exiled and damned from birth till death
Rejected by their parents
Locked up as beasts
No clergy brought their souls to bless

Never ending pain
In the hour of their death
Driven to their tomb
By never healing wounds

Nobody perceived the cries
No famine got appeased
In hospitals of infanticide
Killers camouflaged
As harmless pediatrist
Children found no place to hide

Never ending pain
In the hour of their death
Driven to their tomb
By never healing wounds

Never ending pain
In the hour of their death
Driven to their tomb
By never healing wounds

With excrements soiled bodies
Starved by malnutrition
Whooping cough and AIDS disease
Now the regime is overthrown
Memorials are raised
But hopes to survive will freeze

Never ending pain
In the hour of their death
Driven to their tomb
By never healing wounds
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

#define eps 1e-10
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n,m,k,ar[1<<20],temp,ans;

long gb(long x)
{
 long s=0;
 for (int i=0;i<=28;i++)
  if (x&(1<<i))++s;
 return s;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=m+1;i++)
 cin>>ar[i];

for (int i=1;i<=m;i++)
{
 temp=ar[i];
 temp^=ar[m+1];
 if (gb(temp)<=k)++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}