/*
I stand before thee, gods of all prestine
Come forth to see, all things to be seen
Now know the presence, and choose thy wrath
For flock of tyrants, who know not thy path

Come now in sweeping vengeance
Come now in needed time
I demand as I stand before you
Cleanse this worlds decay

I demand to know the light of a promised land
I demand to see this corrosion wiped away

And the slithering begins
as the shell of men crawl weeping
and as the light of dawn is growing
the realization sets in
And with the winds that are blowing
the final truth has come
That the ways of the shallow empty
have brought it down
The winds that are blowing
shall bring it down

And while your clinging
to the ways of your worthless life
Your words is falling
you are left with nothing
and with the winds that are blowing
the final truth has come
your ways so shallow and empty
have brought it down
your ignorant haze
has brought it down

Return these days to the righteous
heal these wounds of time
I have waited so long
for the winds of change to come
through eyes still clear
through eyes not dulled by fear
through eyes behind the soul
I see what must be...

I demand to know the light of a promised land
I demand to see this corruption wiped away
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

long n,m,a,b,iters,fl,ans;
vector<long> v;
set<pair<long, long> > bad;

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
cin>>a>>b;
if (a>b)swap(a,b);
bad.insert(make_pair(a,b));
}

for (int i=0;i<n;i++)
v.push_back(i+1);

iters=4000000/n;

for (;iters;--iters)
{
 random_shuffle(v.begin(),v.end());
 fl=0;
 for (int i=0;i<m&&i<v.size()-1;i++)
 {a=v[i];b=v[i+1];if (a>b)swap(a,b);
 if (bad.find(make_pair(a,b))!=bad.end())fl=1;}
 if (m==n)
 {
  a=v[0];
  b=v[v.size()-1];
  if (a>b)swap(a,b);
  if (bad.find(make_pair(a,b))!=bad.end())fl=1;
 }
 if (fl==0){ans=1;
 break;}
}
v.push_back(v[0]);

if (ans==0)
{
 cout<<-1<<endl;
}
else for (int i=0;i<m;i++)
cout<<v[i]<<" "<<v[i+1]<<endl;
cin.get();cin.get();
return 0;}