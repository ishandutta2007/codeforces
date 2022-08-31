/*
Walk me out in the morning dew
Walk me out in the morning dew today
I can't walk you out in no morning dew
Can't walk you out in no morning dew at all, come on

Thought I heard a young boy cryin' mama
Thought I heard a young boy cry today
You didn't hear no young boy cryin'
You didn't hear no young boy cry at all

Thought I heard a young girl cryin' mama
Thought I heard a young girl cry today
You didn't heard no young girl cryin'
You didn't heard no young girl cry at all

Thought I heard a young man cryin' mama
I thought I heard a young man cry today
You didn't heard no young man cry at all
You didn't heard no young man cry at all

Now there is no more morning dew
Now there is no more morning dew
What they've been sayin' all these years is true
Now there is no more morning dew
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
#define N 120000

using namespace std;

string st;
string temp;
long k,n,m,q;
string bas[2000];
map<string, long> mapp;
string comp[2000];
long am,need[1000][1000];
long num;
long has[200][200];
long t,can,er,hc[1000][1000];
vector<pair<string, long> > vec;

long solve(string st)
{
 long r=0;
 for (int i=0;i<st.size();i++)
 r=r*10+st[i]-48;
 return r;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>k>>n>>m>>q;
for (int i=1;i<=n;i++)
{
 cin>>bas[i];
 mapp[bas[i]]=i;
}

getline(cin,st);

for (int i=1;i<=m;i++)
{
 getline(cin,st);
 stringstream ss(st);
 ss>>temp;
 temp.erase(temp.end()-1);
 comp[i]=temp;
 while (ss>>temp)
 {
  string tst;
  ss>>tst;
  if (tst[tst.size()-1]==',')tst.erase(tst.end()-1);
  am=solve(tst);
  need[i][mapp[temp]]=am;
 }
}

for (int i=1;i<=q;i++)
{
 cin>>num;
 cin>>temp;
 t=mapp[temp];
 has[num][t]++;
 can=-1;
 for (int j=1;j<=m;j++)
 {
  er=0;
  for (int t=1;t<=n;t++)
  {
   if (need[j][t]>has[num][t])er=1;
  }
  if (er==0)can=j;
 }
 if (can==-1)continue;
 hc[num][can]++;
 for (int t=1;t<=n;t++)
 {
  has[num][t]-=need[can][t];
 }
}

for (int i=1;i<=k;i++)
{
 vec.clear();
 for (int j=1;j<=n;j++)
  if (has[i][j])
   vec.push_back(make_pair(bas[j],has[i][j]));
 for (int j=1;j<=m;j++)
 {
  if (hc[i][j])
   vec.push_back(make_pair(comp[j],hc[i][j]));
 }
 sort(vec.begin(),vec.end());
 cout<<vec.size()<<endl;
 for (int j=0;j<vec.size();j++)
 {
  cout<<vec[j].first<<" "<<vec[j].second<<endl;
 }
}

cin.get();cin.get();
return 0;}