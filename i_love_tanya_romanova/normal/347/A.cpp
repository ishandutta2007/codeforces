/*
All of this comes crashing down.
Cornerstone's gone
Sleepless.
Hopeless.
No end in sight.
Ink well has run dry, fill it with blood of the scribe.
Rest comes easy to the guiltless
The vampire laments as he prays for the sun.
Doom, despair, tragedy are the tools of the trade.
Cut to the bone, rob the grave
Unearth the stone, lay to waste
Defile the tome, rip the page
Strip mine the vein, lay to waste.
Frayed at the edge, flat lined.
The anvil cracks.
The hammer relentlessly comes down.
A new pariah is born.
Chastisement lays you down to sleep, tucks you in with bloody kisses
Gifts of nightmares bitter sweet.
Type A negative shuts me down.
Catch phrase will be the death of me.
This is, not what you came to see?
What, are you not entertained?
Climb the walls 'til nails bleed.
Rip the hair, tear the seams, break the glass.
Head in hands, bell tolls endlessly
No end in sight.
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

long n,q;
vector<long> v;

int main(){
//freopen("police.in","r",stdin);
//freopen("police.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;v.push_back(q);
}
sort(v.begin(),v.end());
swap(v[0],v[v.size()-1]);

for (int i=0;i<v.size();i++)
{
    if (i)cout<<" ";
    cout<<v[i];
}
cout<<endl;
cin.get();cin.get();
return 0;}