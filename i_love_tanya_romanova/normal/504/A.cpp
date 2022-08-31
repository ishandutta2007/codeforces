/*
When the thunder rolls, lightening in the sky
Do you carry on regardless even though you all may die?
And when the sun burns down, draining you of life
Do you crumble in the desert; do you fight to stay alive?

So we ride over the mountains
Over the mountains that stand in our way
We will fly, higher and higher
Searching for destiny.

Where will I find my heaven?
Can it really be here on earth?
How can I know what's waiting?
How will I know what's meant for me?

When the devil calls, devil calls your name
Do you run like little children, running from the game?
And when the evil lies buried near your heart
Do you turn against your people, tearing them apart?

So we ride over the mountains
Over the mountains that stand in our way
We will fly, higher and higher
Searching for destiny.

Where will I find my heaven?
Can it really be here on earth?
How can I know what's waiting?
How will I know what's meant for me?

See the shadowland, hidden from the light
Feel the terror rising on this cold deserted night
Broken promises, not to be fulfilled
Never trust a demon, never fall under his will.

So we ride over the mountains
Over the mountains that stand in our way
We will fly, higher and higher
Searching for destiny.

Where will I find my heaven?
Can it really be here on earth?
How can I know what's waiting?
How will I know what's meant for me?

Where will I find my heaven?
Can it really be here on earth?
How can I know what's waiting?
How will I know what's meant for me?
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,deg[1<<20],s[1<<20],v,id;
vector<long> leaves;
vector<pair<long, long> > edges;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>deg[i]>>s[i];
}

for (int i=0;i<n;i++)
{
 if (deg[i]==1)
  leaves.push_back(i);
}

while (leaves.size())
{
 v=leaves.back();
 leaves.pop_back();
 id=s[v];
 if (deg[v]==0)continue;
 deg[id]--;
 s[id]^=v;
 if (deg[id]==1)
  leaves.push_back(id);
 edges.push_back(make_pair(v,id));
}

cout<<edges.size()<<endl;
for (int i=0;i<edges.size();i++)
{
 cout<<edges[i].first<<" "<<edges[i].second<<endl;
}
cin.get();cin.get();
return 0;}