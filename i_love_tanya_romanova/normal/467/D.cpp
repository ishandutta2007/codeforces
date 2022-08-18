/*
Terrorize, frozen eyes
Stare deep in me
Paralyzed, inside
Death breeds on your pain

Pretty lace lie in hate
You wear my scars
Terrified, you find
That you push me too far

Your repulsiveness reminds me
Of dead flesh
Rotting corpse
The smell of your putrid fucking soul

Petrified that I decide
The moment of your death
Belongs to me, the taste is sweet
It's so unreal

Your God weeps, it bleeds
It begs for me
God is letting you recover

Welcome to my black serenade
The entrance to my hell, your pain
Scream your song, the black serenade
Live in fear, a mind insane

Voice inside my head
Your face still shows itself to me
Telling me you're dead
Staring at your lifeless body

I saw you fucking die
My mind's tearing itself apart
Screaming from the inside
Release this pain from my fucking heart

Destroy the empty shell
Smash away the haunting fear
I hate your endless stare
Watching as I fuck your corpse

Welcome to my black serenade
The entrance to my hell, your pain
Walk on through a tortured mind
You'll scream your song in time

Welcome to my black serenade
The entrance to my hell, your pain
Flesh is burnt, the black serenade
Live in fear, no coming back

Welcome to my black serenade
The entrance to my hell, your pain
Walk on through a tortured mind
You'll scream your song in time

Welcome to my black serenade
The entrance to my hell, your pain
Flesh is burnt, the black serenade
Live in fear, death is back
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

#define eps 1e-10
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n;
string st;
map<string, long> mapp;
set<string> has;
long inp[1<<20];
long tests;
string st1,st2;
long a,b;
vector<long> g[1<<20];
pair<long, long> ans[1<<20];
long words;
vector<pair<pair<long, long> ,long> > v;
pair<long, long> cur;
long used[1<<20];
long long ans1,ans2;

pair<long, long> solve(string st)
{
 pair<long, long> res;
 res.second=st.size();
 res.first=0;
 for (int i=0;i<st.size();i++)
  if (st[i]=='r')++res.first;
 return res;
}

string norm(string st)
{
 for (int i=0;i<st.size();i++)
  if (st[i]>='A'&&st[i]<='Z')
   st[i]=st[i]-'A'+'a';
 return st;
}

void add(string st)
{
 if (has.find(st)!=has.end())return;
 mapp[st]=has.size();
 words=has.size()+1;
 has.insert(st);
 ans[mapp[st]]=solve(st);
}

void dfs(long v)
{
 ans[v]=cur;
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
  dfs(q);
 }
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>st;
 st=norm(st);
 add(st);
 inp[i]=mapp[st];
}

cin>>tests;
for (;tests;--tests)
{
 cin>>st1>>st2;
 st1=norm(st1);
 st2=norm(st2);
 add(st1);
 add(st2);
 a=mapp[st1];
 b=mapp[st2];
 g[b].push_back(a);
}

for (int i=0;i<words;i++)
v.push_back(make_pair(ans[i],i));

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 long id=v[i].second;
 cur=v[i].first;
 if (used[id]==0)
  dfs(id);
}

for(int i=0;i<n;i++)
{
 ans1+=ans[inp[i]].first;
 ans2+=ans[inp[i]].second;
}

cout<<ans1<<" "<<ans2<<endl;

cin.get();cin.get();
return 0;}