/*
A green plastic watering can
For a fake Chinese rubber plant
In the fake plastic earth

That she bought from a rubber man
In a town full of rubber plans
To get rid of itself

It wears her out, it wears her out
It wears her out, it wears her out

She lives with a broken man
A cracked polystyrene man
Who just crumbles and burns

He used to do surgery
On the girls in the eighties
But gravity always wins

And it wears him out, it wears him out
It wears him out, it wears

She looks like the real thing
She tastes like the real thing
My fake plastic love

But I can't help the feeling
I could blow through the ceiling
If I just turn and run

And it wears me out, it wears me out
It wears me out, it wears me out

And if I could be who you wanted
If I could be who you wanted
All the time, all the time
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

long ans;
char pr[100000000];
long l,r;

bool gett(long x)
{
 return ((pr[x/8]&(1<<(x%8)))==0);
}

void sett(long x)
{
     pr[x/8]|=(1<<(x%8));
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>l>>r;

sett(1);

for (int i=3;i<=18000;i+=2)
 if (gett(i))
  {
   for (int j=i*i;j<=r;j+=i*2)
   sett(j);
  }

for (int i=l;i<=r;i++)
 if (i%4==1&&i>1)
  if (gett(i))
 { ans+=1;
//  cout<<i<<endl;
}
if (l<=2&&r>=2)++ans;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}