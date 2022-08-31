/*
Immortal subjugator, usurper, dominator
Blood ruler of the dark
Lord of the shadow world, flag of black unfurled
Foul, unholy patriarch
Enslaver of mankind, king of all unkind
Light ender in black domain
I fear only the dawn, at war with the rising sun
Eternal dusk ordained

I lurk beside you, never to abide you
I live inside you, always to divide you
I stand between you, certain to unclean you
The night is my savior
The sun is my destroyer

Despotic tyrants liar, judgement always dire
Unrepentant fear machine
Dream world paralyzer, re of man, none the wiser
Beneath the surface, site unseen
My only enemy, the day, behest color, shades of grey
Rejoice in the coming of the night
Nightmares come all too real, dest horror soon revealed
Rising with the dying of the light

I lurk beside you, never to abide you
I live inside you, always to divide you
I stand between you, certain to unclean you
The night is my savior
The sun is my destroyer

In my dominion, day meets its demise
Ultraviolet adversary, like an open wound to cauterize
The night's assailant is the coming of the morning sun
Illuminescent antagonist, smashed to oblivion
I am god here, in the bowels of the human mind
Creature of imagination, born of the impure and unrefined
I prey on your fear, take all you hold dear and then I use it against you
So unwise for you to close your eyes
That's when I come to dispense you

Malignant dream accuser
Pleasant thought reverser
Loathsome bringer of dread
Slumber now vitiated
Sweet dreams abominated
Terrors better left unsaid
Villainous machination
Sub conscious tribulation
Tremble at the coming of the twilight
Rising with the setting sun
Returning when the day's undone
Ensuring an end to all goodnights

I lurk beside you, never to abide you
I live inside you, always to divide you
I stand between you, certain to unclean you
The night is my savior
The sun is my destroyer
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

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long k,n,dd[1200000],start;
vector<pair<long, long> > d,v,g;
set<pair<long, long> > sett[1200000];
set<pair<long, long> > ::iterator it;
long t,dep;
pair<long, long> tp;
void add_edge(long a,long b)
{
 g.push_back(make_pair(a,b));
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
--k;
for (int i=1;i<=n;i++)
{
    cin>>dd[i];
    if (dd[i]==0)
    {
     if (start){cout<<-1<<endl;return 0;}
     start=i;
    }
}
if (start==0){cout<<-1<<endl;return 0;}

for (int i=1;i<=n;i++)
{
 v.push_back(make_pair(dd[i],i));
}
sort(v.begin(),v.end());
sett[0].insert(make_pair(-1,start));

for (int i=1;i<v.size();i++)
{
 t=v[i].second;
 dep=v[i].first;
 --dep;
 if (sett[dep].size()==0){cout<<-1<<endl;return 0;}
 it=sett[dep].begin();
 tp=(*it);
 if (tp.first==k){cout<<-1<<endl;return 0;}
 sett[dep].erase(it);
 tp.first++;
 sett[dep].insert(tp);
 add_edge(tp.second,t);
 sett[dep+1].insert(make_pair(0,t));
}

cout<<n-1<<endl;
for (int i=0;i<g.size();i++)
cout<<g[i].first<<" "<<g[i].second<<endl;

cin.get();cin.get();
return 0;}