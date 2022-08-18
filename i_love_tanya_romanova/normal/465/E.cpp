/*
I still recall the taste of your tears
Echoing your voice just like the ringing in my ear
My favorite dreams of you still wash ashore
Scraping through my head 'til I don't want to sleep anymore

You'll make this all go away
You'll make this all go away
I'm down to just one thing
And I'm starting to scare myself

You'll make this all go away
You'll make it all go away
I just want something
I just want something I can never have

You always were the one to show me how
Back then I couldn't do the things that I can do now
This thing is slowly taking me apart
Grey would be the color if I had a heart

Come on, tell me
You'll make this all go away
You'll make this all go away
I'm down to just one thing
And I'm starting to scare myself

You'll make this all go away
You'll make it all go away
I just want something
I just want something I can never have

In this place it seems like such a shame
Though it all looks different now
I know it's still the same and everywhere I look you're all I see
Just a fading fucking reminder of who I use to be

Come on, tell me
You'll make this all go away
You'll make this all go away
I'm down to just one thing
And I'm starting to scare myself

You'll make this all go away
You'll make this all go away
I just want something
I just want something I can never have
I just want something I can never have
I can never have
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
#define bsize 512

using namespace std;

string st;
pair<long long, long long> rule[1000];
long rules;
string st1;
vector<pair<long,string> > v;
long long bas,res,val;

pair<long, string> parse(string st)
{
 pair<long, string> r;
 r.first=st[0]-'0';
 for (int i=3;i<st.size();i++)
  r.second+=st[i];
 return r;
}

void update(pair<long, string> p)
{
 long long res,bas;
 res=bas=0;
 bas=1;
 string st=p.second;
 if (st.size())
 { 
  for (int i=st.size()-1;i+1;--i)
  {
  res+=1ll*rule[st[i]-'0'].first*bas;
  bas*=rule[st[i]-'0'].second;
  res%=bs;
  bas%=bs;
  }
 }
 rule[p.first]=make_pair(res,bas);
 return;
}

int main(){
//freopen("highway.in","r",stdin);
//freopen("highway.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<10;i++)
 rule[i]=make_pair(i,10);

cin>>rules;
for (;rules;--rules)
{
 cin>>st1;
 v.push_back(parse(st1));
}

reverse(v.begin(),v.end());
for (int i=0;i<v.size();i++)
 update(v[i]);

// --- degb t
/*
for (int i=0;i<v.size();i++)
 cout<<v[i].first<<"  "<<v[i].second<<endl;
 

for (int i=0;i<10;i++)
 cout<<rule[i].first<<"  % "<<rule[i].second<<endl;
*/
 //---
res=0;
bas=1;
for (int i=st.size()-1;i+1;--i)
{
 res+=1ll*rule[st[i]-'0'].first*bas;
 bas*=rule[st[i]-'0'].second;
 res%=bs;
 bas%=bs;
}

cout<<res<<endl;

cin.get();cin.get();
return 0;}