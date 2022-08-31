/*
(Shh, Quiet, might piss somebody off)
Like me motherfucker you've been at it for too long
While you feed off all those insecurities
You stand in front of me and bite the hand that feeds

Self-righteousness is wearing thin
(Lies inside your head, your best friend)
I'll bleed but not for fellow man
(Broken glass, your fake reflection)

Telling them it's all for something real
Don't respect the words youre speaking
Gone too far, acclaim

So, how does it feel to know that
Someones kid in the heart of America has blood on their hands
Fighting to defend your rights so you can maintain the lifestyle
That insults his familys existence?

Well, where I'm from we have a special salute
We wave high in the air towards all those pompous asses
Who spend their days pointing fingers
(Fuck you)

(Quiet, might piss somebody off)
Like the heartbeat of this country when antagonized too long
I'll be damned if you count me in as part of your
Generous hypocrisy, collected in a maze

Tabloid gossip we want less real
(Theres no need for us to bury you)
Selfish agenda once again
(Right this way, you dug your own grave)

Telling them it's all for something real
Don't respect the words youre speaking
Gone too far, acclaim

All the way from the east to the west
We got this high society looking down on their very foundation
Constantly reminding us that our actions
Are the cause of all their problems

Pointing their fingers in every direction
Blaming their own nation for who wins elections
They never contributed a fucking thing
To the country they love to criticize

Excuse the obscene, ignore the untrue
Depictions we see, try and get through
And many mistakes can hurt
Im not the last but I sure aint the first
(Quiet, might piss somebody off)

Self righteousness is wearing thin
(Lies inside your head, your best friend)
I'll bleed but not for fellow man
(Broken glass, your fake reflection)

Telling them it's all for something real
Don't respect the words you're speaking
Gone too far, acclaim
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

long n,m,c[200000],a,b;
long long ans;
vector<pair<long, long> > v;
vector<long> g[200000];
long used[20000];

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)cin>>c[i];

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

for (int i=1;i<=n;i++)
{
 v.push_back(make_pair(c[i],i));
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 long q=v[i].second;
 for (int j=0;j<g[q].size();j++)
 {
  long t=g[q][j];
  if (used[t])continue;
  ans+=c[t];
 }
 used[q]=1;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}