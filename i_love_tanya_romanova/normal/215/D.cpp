/*
"I'll try," she said as he walked away.
"Try not to lose you."
Two vibrant hearts could change.
Nothing tears the being more than deception,
unmasked fear.
"I'll be here waiting" tested but secure.

Nothing hurts my world,
just affects the ones around me
When sin's deep in my blood,
you'll be the one to fall.

"I wish I could be the one,
the one who won't care at all
But being the one on the stand,
I know the way to go, no one's guiding me.
When time soaked with blood turns its back,
I know it's hard to fall.
Confined in me was your heart
I know it's hurting you, but it's killing me."

Nothing will last in this life,
our time is spent constructing,
now you're perfecting a world... meant to sin.
Constrict your hands around me,
squeeze till I cannot breathe,
this air tastes dead inside me,
contribute to our plague.
Break all your promises,
tear down this steadfast wall,
restraints are useless here,
tasting salvation's near.
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long n,m,t[1000000],T[1000000],x[1000000],cost[1000000],
onebus,abus,inbus,buses,ans;

int main(){
//freopen("line3.in","r",stdin);
//freopen("line3.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>t[i]>>T[i]>>x[i]>>cost[i];
 onebus=m+t[i];
 if (T[i]<onebus)onebus=m*x[i];
 else onebus=0;
 onebus+=cost[i];
 
 if (T[i]<=t[i])abus=1e16;
 else 
 {
  inbus=T[i]-t[i];
  buses=m/inbus+(m%inbus>0);
  abus=buses*cost[i];
 }
// cout<<" "<<onebus<<" "<<abus<<endl;
 
 ans=ans+min(abus,onebus);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}