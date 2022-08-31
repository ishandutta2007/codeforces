/*
A horrid task, the ship has left, the insane must survive
A one way path, that leads to death,
at one within their minds
There's no one here, to guide the weak,
From creeping, pending doom
A prayer is said, to take them from this island,
the unknown
This island, this wretched place, an awful piece of earth
As prisoners, they've been released, to wander into night
Fearful, alert eyes, gaze out and distort
Expecting, detecting, the awful thigns to come
Maniacal screams, a suicide pact, a lasting tone it rings
The so-called crazed dead, the final heartbeat ends
Dying, this coven's gone, at peace now, for all time
This twisted experiment, crumbles before life's eyes
Their world was torture for the living
Then fate led them onward into night
In life, they were different human victims
But in death, they are silent corpses, equal in mind
The horror, the terror, of what lies beyond
On the island of the unknown, this island of the unknown
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

string st;
long calc[1<<25];
long ans,n;
long mask,temp;

void solve(long mask,long ps)
{
 if (ps>0)
 solve(mask,ps-1),solve(mask+(1<<ps),ps-1);
 for (int j=0;j<(1<<ps);j++)
 calc[j+mask+(1<<ps)]+=calc[j+mask];
}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>st;
 mask=0;
 for (int j=0;j<st.size();j++)
 mask|=(1<<(st[j]-'a'));
 ++calc[mask];
}

solve(0,23);

ans=0;
for (int mask=0;mask<(1<<24);mask++)
{
 temp=n-calc[mask];
 ans^=(temp*temp);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}