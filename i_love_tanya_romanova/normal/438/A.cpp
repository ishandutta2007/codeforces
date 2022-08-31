/*
By the last breath of the fourth winds blow
Better raise your ears
The sound of hooves knock at your door

Lock up your wife and children now
It's time to wield the blade
For now you've got some company

Horsemen are drawing nearer
On leather steeds they ride
They've come to take your life

On through the dead of night
With the four horsemen ride
Or choose your fate and die

Oh yeah yeah

You've been dying since the day you were born
You know it's all been planned
The quartet of deliverance ride

A sinner once, a sinner twice
No need for confession now
'Cause now you've got the fight of your life

Horsemen are drawing nearer
On leather steeds they ride
They've come to take your life

On through the dead of night
With the four horsemen ride
Or choose your fate and die

Oh yeah yeah

Time has taken its toll on you
The lines that crack your face
Famine, your body it has torn through
Withered in every place

Pestilence, for what you have to endure
And what you have put others through
Death, deliverance for you for sure
Now there's nothin' you can do

So gather around, young warriors, now
And saddle up your steeds
Killing scores with demon swords

Now is the death of doers of wrong
Swing the judgment hammer down
Safely inside armor, blood, guts and sweat

Horsemen are drawing nearer
On leather steeds they ride
They've come to take your life

On through the dead of night
With the four horsemen ride
Or choose your fate and die

Oh yeah yeah
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