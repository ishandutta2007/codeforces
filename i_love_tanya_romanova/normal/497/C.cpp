/*
Land of enchantment and fake reality
Where they put in vitro breeding machines
On the cover of a magazine
Trailer trash and human freaks
They grab their minute of fame
And still the puppets watch
And everybody knows the names
That's why I say

Burn, hollywood, burn
When it's dead and gone we'll never miss a thing
Burn, hollywood, burn
No more rotten to the core little sweet sixteens
Burn. hollywood, burn
Time's running out on their minute of fame
Let's douse the fire by pissing on the flames

So young, bitch and famous
Hotel heiress, glamour queen
The only reason we know your name
Is bad night vision pornography
From the "real" housewives of botox hills
To the cunts of Bel-Aire
You can't look away from the cathode ray
Why does anybody fucking care

Burn, hollywood, burn
When it's dead and gone we'll never miss a thing
Burn, hollywood, burn
No more rotten to the core little sweet sixteens
Burn. hollywood, burn
Time's running out on their minute of fame
Let's douse the fire by pissing on the flames
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs1 1000000007ll
#define bs2 1000000009ll
#define P1 173
#define P2 187
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,a[1<<20],b[1<<20],m,c[1<<19],d[1<<19],k[1<<19];
vector<pair<pair<long, long> ,pair<long, long> > > v;
pair<pair<long, long> ,pair<long, long> > tp;
long id,er,id1;
set<pair<long, long> > sett;
set<pair<long, long> > ::iterator it;
pair<long, long> th;
long ans[1<<19];

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a[i]>>b[i];
}

cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>c[i]>>d[i]>>k[i];
}

for (int i=1;i<=n;i++)
{
 v.push_back(make_pair(make_pair(a[i],-b[i]),make_pair(2,i)));   
}

for (int i=1;i<=m;i++)
{
 v.push_back(make_pair(make_pair(c[i],-d[i]),make_pair(1,i)));
}

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 tp=v[i];
 if (tp.second.first==1) // sngr
 {
  id=tp.second.second;
  sett.insert(make_pair(d[id],id));
  continue;
 }
 id=tp.second.second;
 th=make_pair(b[id],-1);
 it=sett.lower_bound(th);
 if (it==sett.end())
 {
  er=1;break;
 }
 id1=(*it).second;
 ans[id]=id1;
 --k[id1];
 if (k[id1]==0)
  sett.erase(make_pair(d[id1],id1));
}

if (er)
cout<<"NO"<<endl;
else
{
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++)
    {
        if (i-1)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}
cin.get();cin.get();
return 0;}