/*
Claustrophobic
Crawl out of this skin
Hard explosive
Reaching for that pin

Feel thy name extermination
Desacrating, Hail of Fire

So we cross that line
Into the grips
Total eclipse
Suffer unto my apocalypse!

Deadly vision
Prophecy revealed
Death magnetic
Pulling closer still

Feel thy name annihilation
Desolating, Hail of Fire

So we cross that line
Into the grips
Total eclipse
Suffer unto my apocalypse!

My apocalypse... Go!

Crushing metal, Ripping Skin
Tossing body mannequin
Spilling Blood, Bleeding Gas

Mangle flesh, Snapping spine
Dripping bloody valentine
Shattered face, spitting glass

Split apart
Split apart
Split apart
Split
Spit it out!

What makes me drift a litter bit closer
Dead man takes the steering wheel
What makes me know it's time to cross over
Words you repeat until I feel

See through the skin the bones they all rattle
Future and past they disagree
Flesh falls away the bones they all shatter
I start to see the end in me

See the end in me...

Claustrophobic
Climb out of this skin
Hard explosive
Waiting for that pin

Violate, annihilate
Wounds unto my eyes
Obliterate, exterminate
Life itself denied

Feel thy name as hell awakens
Destiny, Inhale the Fire

But we cross that line
Into the grips
Total eclipse
Suffer unto my apocalypse!

Tyrants awaken my apocalypse!
Demon awaken my apocalypse!
Heaven awaken my apocalypse!
Suffer forever my apocalypse!
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,q,sz;
vector<long>ans[1000];

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
cin>>n;
q=n-1;

while (q){sz++;q/=2;}

cout<<sz<<endl;
for (int i=0;i<n;i++)
{for (int j=0;j<sz;j++)
if (i&(1<<j))ans[j].push_back(i+1);
}
for (int i=0;i<sz;i++)
{cout<<ans[i].size();
for (int j=0;j<ans[i].size();j++)
cout<<" "<<ans[i][j];
cout<<endl;}


cin.get();cin.get();
return 0;}