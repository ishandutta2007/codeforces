/*
Body that rests before me,
With every dying breath,
Spellbound and gagged,
I commence your flesh to dirt.

Body that lay before me,
In everlasting death.
Entombed in abscess,
To rot and lie stinking in the earth.

Empty altar awaits its victim
Stained glass windows black.
Candles burn the midnight oil,
Incense fills the night.

Observing trance awaking state
Lying still unknowing.
Reciting the passages of time
Prepare for the impaling.

Death's an art, flesh and earth never part,
A power of the mind.
Death shines on the air of silence,
A ritual of endless time.

Purged of your dead body,
Sacrificed of your life.
Unearthly ritual sealed in fire
Enter the kingdom of desire.
*/

#pragma comment(linker, "/STACK:16777216")
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
#define eps 1e-9
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

long n,deg[6000],l[6000],r[6000];
vector<long> ans;
vector<pair<long, long> > bad;

bool inter(long a,long b)
{
 if (l[a]>=r[b])return false;
 if (r[a]<=l[b])return false;
 return true;
}

int main(){
//freopen("cooling.in","r",stdin);
//freopen("cooling.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i<=n;i++)
{
    cin>>l[i]>>r[i];
}

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
    if (i==j)continue;
    if (inter(i,j))bad.push_back(make_pair(i,j));
}

for (int i=0;i<bad.size();i++)
{
 deg[bad[i].first]++;
 deg[bad[i].second]++; 
}

for (int i=1;i<=n;i++)
if (deg[i]==bad.size())ans.push_back(i);

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}