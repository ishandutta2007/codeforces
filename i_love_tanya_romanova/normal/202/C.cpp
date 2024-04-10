/*
The roman army is marching again the empire is growing
An' all destroying war machine that's rolling out on the land
Children out of victory across the river Rhine
Once these marching warriors are running into death
The people across the land they suppress
Were born with the free and wild spirit
Slavery they cannot bear Rome's legions are charged to death
The whole German tribes are standing together
Hatred is ruling their brains
Marching out to fight for their freedom
Marching out to destroy Rome's pride
United by hatred there's only freedom or death
United by hatred killing all invaders til the ground's gettin' red
The whole roman army was killed in one day
None of the soldiers survived
The battlefields looked like a slaughterhouse
Rome now your fall has begun
United by hatred there's only freedom or death
United by hatred killing all invaders til the ground's gettin' red
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

long x,ans;
long upr;

bool has(long l,long val)
{
 upr=l*l/2+1;
 if (upr>=val)return true;
 return false;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x;
for (int i=1;i<=100;i+=2)
 if (has(i,x))
  {ans=i;break;}

if (x==3)ans=5;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}