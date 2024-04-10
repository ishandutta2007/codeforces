/*
(one, two)
Ooh
Wow
Ooh
I feel bad, and I've felt worse
I'm a creep, yeah, I'm a jerk

Come on
Touch me, I'm sick

Wow
I won't live long, and I'm full of rot
Gonna give you - girl - everything I got

Touch me, I'm sick, yeah
Touch me, I'm sick

Come on baby, now come with me
If you don't come
If you don't come
If you don't come
You'll die alone

Wow
Ooh

I'm diseased, I don't mind
I'll make you love me 'till the day you die

Come on
Touch me, I'm sick
Ahhh
Fuck me, I'm sick

Come on baby, now come with me
If you don't come
If you don't come
If you don't come
You'll die alone
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

long long tests,num;
string st;
string temp;
string name;
long long a,b;
string typ;
map<string, long> mapp;
long vert;
map<long, string> rmapp;
long long w[2000],h[20000],tp[2000];
long long brd[2000],sp[2000];
long long g[500][500];
long bst,calc;
long used[20000];
vector<long> srt;
long long ttl,qh,qw;

string norm(string st)
{
 for (int i=0;i<st.size();i++)
 {
  if (st[i]=='.'||st[i]=='('||st[i]==')'||st[i]==',')st[i]=' ';
 }
 return st;
}

void add_widget(string name,long long a,long long b,long long t)
{
 mapp[name]=vert;
 rmapp[vert]=name;
 w[vert]=a;
 h[vert]=b;
 tp[vert]=t;
 ++vert;
}

void set_border(string st,long num)
{
 long id=mapp[st];
 brd[id]=num;
}

void set_spacing(string st,long num)
{
 long id=mapp[st];
 sp[id]=num;
}

void pack(string st1,string st2)
{
 long id1=mapp[st1];
 long id2=mapp[st2];
 g[id1][id2]++;
}

vector<pair<string, pair<long long, long long> > > ans;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
getline(cin,st);
for (;tests;--tests)
{
 getline(cin,st);
 st=norm(st);
 stringstream s(st);
 s>>temp;
 if (temp=="Widget")
 {
  s>>name>>a>>b;
  add_widget(name,a,b,0);
 }
 else if (temp=="VBox")
 {
  s>>name;
  add_widget(name,0,0,1);
 }
 else if (temp=="HBox")
 {
  s>>name;
  add_widget(name,0,0,2);
 }
 else
 {
  s>>typ;
  if (typ=="pack")
  {
   s>>st;
   pack(temp,st);
  }
  if (typ=="set_border")
  {
   s>>num;
   set_border(temp,num);
  }
  if (typ=="set_spacing")
  {
   s>>num;
   set_spacing(temp,num);
  }
 }
}

for (int iter=1;iter<=vert;iter++)
{
 bst=-1;
 for (int i=0;i<vert;i++)
 {
  calc=0;
  if (used[i])continue;
  for (int j=0;j<vert;j++)
   if (g[i][j]>0&&used[j]==0)++calc;
  if (calc==0)bst=i;
 }
 srt.push_back(bst);
 used[bst]=1;
// cout<<bst<<endl;
}

for (int i=0;i<srt.size();i++)
{
 long id=srt[i];
 if (tp[id]==0)
 {
 // ans.pus_back(make_pair(rmap[id],make_pair(w[id],h[id])));
  continue;
 }
 ttl=0;
 qh=qw=0;
 
 for (int j=0;j<vert;j++)
 {
  if (g[id][j]==0)continue;
  ttl+=g[id][j];
  if (tp[id]!=1)
  {
   qh=max(qh,h[j]);
   qw+=g[id][j]*w[j];
  }
  else
  {
   qw=max(qw,w[j]);
   qh+=g[id][j]*h[j];
  }
 }
 
 if (ttl>0)
 {
  if (tp[id]!=1)
  {
   qh+=2*brd[id];
   qw+=(ttl-1)*sp[id]+2*brd[id];
  }  
  else
  {
   qh+=(ttl-1)*sp[id]+2*brd[id];
   qw+=2*brd[id];
  }
 }
// cout<<ttl<<" "<<rmapp[id]<<" "<<qh<<"  "<<qw<<endl;
 
 h[id]=qh;
 w[id]=qw;
}

for (int i=0;i<vert;i++)
 ans.push_back(make_pair(rmapp[i],make_pair(w[i],h[i])));

sort(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
}
/*
for (int i=0;i<vert;i++)
{
 cout<<rmapp[i]<<" "<<w[i]<<" "<<h[i]<<endl;
}
*/

cin.get();cin.get();
return 0;}