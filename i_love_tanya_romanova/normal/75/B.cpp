/*
Darling, baby
Don't say maybe
Disobey me, I'll be
Like a bad penny
I twist the truth
I love your youth
You're losing grip
Take a trip, you,
You're going down
Going down
You're going down
Like fallen angels
I will mesmerise
You will paralyse
Framed in your game
Slowly fading
No one knowing
We are through
Count your blessings
Count to eighteen
Souls to perish
For a few stolen dreams only
As we've walked down the alley
On the misty afternoon
No one looked back nor forward
The city walls felt distant
Never at our reach
We're sentenced to your world
You're going down
You're going down
With me
You're going down with me
I will mesmerise
You will paralyse
Like fallen angels
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st;
long tests;
long score[1<<20];
map<string,long> mapp;
map<long, string> rmap;
vector<string> v;
set<string> names;

void add(string st)
{
 if (names.find(st)!=names.end())return;
 int t=names.size();
 names.insert(st);
// cout<<st<<"   "<<t<<endl;
 mapp[st]=t+1;
 rmap[t+1]=st;
}

long id1,id2;

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
add(st);
cin>>tests;
getline(cin,st);
for (;tests;--tests)
{
 getline(cin,st);
 stringstream s(st);
 string temp;
 v.clear();
 while (s>>temp)
 {
  v.push_back(temp);
 }
 add(v[0]);
//cout<<v[0]<<endl;
 if (v[1]=="posted")
 {
  v[3].erase(v[3].end()-1);
  v[3].erase(v[3].end()-1);
//  cout<<v[3]<<endl;
  add(v[3]);
  id1=mapp[v[0]];
  id2=mapp[v[3]];
  if (id1==1||id2==1)
   score[id1]+=15,
   score[id2]+=15;
 }
 
 if (v[1]=="commented")
 {
  v[3].erase(v[3].end()-1);
  v[3].erase(v[3].end()-1);
  add(v[3]);
  id1=mapp[v[0]];
  id2=mapp[v[3]];
  if (id1==1||id2==1)
   score[id1]+=10,
   score[id2]+=10;
 }
 
 if (v[1]=="likes")
 {
  v[2].erase(v[2].end()-1);
  v[2].erase(v[2].end()-1);
  add(v[2]);
///  cout<<v[2]<<endl;
  id1=mapp[v[0]];
  id2=mapp[v[2]];
  if (id1==1||id2==1)
   score[id1]+=5,
   score[id2]+=5;
 }
}
/*
for (int i=2;i<=names.size();i++)
{
 cout<<rmap[i]<<" "<<score[i]<<endl;
}*/
vector<pair<long, string> > ans;
for (int i=2;i<=names.size();i++)
{
 ans.push_back(make_pair(-score[i],rmap[i]));
}

sort(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
 cout<<ans[i].second<<endl;
 
cin.get();cin.get();
return 0;}