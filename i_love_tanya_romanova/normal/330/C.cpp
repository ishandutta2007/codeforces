/*
Your plastic souls melt within cauldron's burning black
Chanting to the Ancient Ones, chants of broken lines
Kneel before the alter, sacrifice is made
It is pleasing to the ones most ancient of the days

They call the prince of disease, messenger of the Absu
Carry through the icy winds our curse upon their church

Hanging helpless above the pentagram
Sacrifice swings within leather noose
Sing the ancient hymn that makes the Abso roll
Raise the rusty knife, let loose the blood of Kingu

Sudden death throws off the balance that's within the sky
Priest calls forth infernal names to the ones beyond the gate

Angel of disease one who shuns the light
Shub Niggurath goat with one thousand young

Praise the beast, the chanting grew
Praise the beast with virgin blood
Praise the beast with soul and mind
Praise the beast and show the sign

Bind their kings in iron chains
Execute the judgement for them
Come and taste the fleshy pleasures
Orgies of endless time

Beneath the rolling for hate ignites their eyes
>From their graves the dead rise to answer Nammtar's call
On a twisted cross the virgin corpse hangs
They blacken out the sun and burn the elder gods

Morbid priest calling forth
Abominations of the sky
Kutulu meets in the void
Ancient Ones rule once more
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long fl;
char ar[200][200];
long v[200],g[200],n;
vector<pair<long, long> > ans;
long ci,cj;

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
v[i]=g[i]=-1;

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
    cin>>ar[i][j];
    if (ar[i][j]=='.'){v[i]=j;g[j]=i;}
}

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
 if (v[i]==-1&&g[j]==-1)
  fl=1;
}
for (int i=1;i<=n;i++){
if (v[i]>0)ci++;
 if (g[i]>0)cj++;
}
if (fl){cout<<-1<<endl;}
else
if (ci==n)
{
// cout<<n<<endl;
 for (int i=1;i<=n;i++)
 cout<<i<<" "<<v[i]<<endl;
}
else if (cj==n)
{
// cout<<n<<endl;
 for (int i=1;i<=n;i++)
 cout<<g[i]<<" "<<i<<endl;
}
else
{
    for (int i=1;i<=n;i++)
    if (v[i]>0)ans.push_back(make_pair(i,v[i]));
    for (int i=1;i<=n;i++)
    if (g[i]>0)ans.push_back(make_pair(g[i],i));
   // cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
    
}
cin.get();cin.get();
return 0;}