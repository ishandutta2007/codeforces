/*
Crown all the thieves and you worship the liars
And bow down before every whore in a tie
Lost to the end though the sun also rises
And those who would dare bring the turn of the tide

Arrogant serenity
Falter on the scale when I weigh you

This doubt may breed desires
For truth
For truth

Glare just long enough to convey your displeasure
As drops, one by one, start to fall in the pool
Blurring the sight of a misplaced alliance
Where deaf lead the blind, and the blind lead the fools

Ignorant security
Falter on the scale when I weigh you

This doubt may breed desires
To look deeper than the surface
And to dare to understand
All the mysteries residing beneath

These reflections of a purpose, false impressions of a past
That exist only to serve the elite

Fuck all these complacent sheep
Chasing after every prize
Begging at the masters' feet
Happy to ostracize
Fuck all those who will not see
Further than the mirror's lies
Fuck you and your vanity
It's too late, we're out of time
To stand idly by and wait
So why don't you take this chance
And find a place to
Feast on the wealth of your self-indulgence
While the meek and the worthy change
This world again
Gnawing away at your precious elegance
I hope that you like the taste
For there you shall stay
Lost
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