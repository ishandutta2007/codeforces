/*
Beams of fire sweep through my head
Thrusts of pain increasingly engaged
Sensory receptors succumb
I'm no one now, only agony

My crimson liquid so frantically spilled
The ruby fluid of life unleashed

Ripples ascend to the surface of my eyes
Their red pens drawing at random, at will
A myriad pains begotten in their wake
The bastard spawn of a mutinous self

The regurgitation of my micro nemesis
Salivating red at the prospect of my ruin, my doom

Malfunction the means for its ascent
Bloodletting the stringent voice to beckon my soul
So futile, any resisting tension
As death-induced mechanics propel its growth

The implement, the device of my extinction
The terminating clockwork of my gleeful bane
The definitive scourge of its mockery
The end-art instruments, lethality attained

Heed, it commands, heed my will
Bleed, it says, bleed you will

Falling into the clarity of undoing
Scornful gods haggle for my soul
Minds eye flickers and vellicates as I let go
Taunting whispers accompany my deletion

A sneering grin, the voice of my reaper
Chanting softly the song of depletion
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

long n,d;
string st1[20000],st2[20000]; long tm[200000];
set<pair<string, string> > was;
map<pair<string, string>,long > lst;
set<pair<string, string> > ::iterator it;
set<pair<string, string> > ans;
pair<string, string> tp;

void add(string st1,string st2)
{
 if (st1>st2)swap(st1,st2);
 ans.insert(make_pair(st1,st2));
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

long iter=0;

cin>>n>>d;
for (;n;--n)
{
    ++iter;
 cin>>st1[iter]>>st2[iter]>>tm[iter];
}

for (int i=1;i<=iter;i++)
 for (int j=i+1;j<=iter;j++)
  if (st1[i]==st2[j]&&st2[i]==st1[j]&&tm[i]<tm[j]&&tm[i]>=tm[j]-d)
   add(st1[i],st2[i]);
   
cout<<ans.size()<<endl;
for (it=ans.begin();it!=ans.end();it++)
{
 tp=(*it);
 cout<<tp.first<<" "<<tp.second<<endl;
}


cin.get();cin.get();
return 0;}