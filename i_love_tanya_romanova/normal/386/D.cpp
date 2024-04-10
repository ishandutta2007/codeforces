/*
The blaze of northern light
Reflect the dawn of gods
Of ancient pantheons
Who rest no more in peace.
Faith of the old,
The strong one from above:
The invincible.
The invincible.
All the gods of the sky and the earth
Proclaim this day, this day.
See the signs in the day and the night,
Foretell the one, the one.
Open up the runa of belief of the strong and the brave
Open up let the gods of your heart and your soul show the way.
The eye of the high one
Have seen the dawn of gods
In the well of mimera
(and) through the flight of ravens
Faith of the old,
The strong one from above:
The invincible.
The invincible.
All the gods of the sky and the earth
Proclaim this day, this day.
See the signs in the day and the night,
Foretell the one, the one.
Open up the runa of belief of the strong and the brave
Open up let the gods of your heart and your soul show the way.
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,a,b,c;
string st;
char ar[200][200];
queue<pair<long, pair<long, long> > > qu;
pair<long, pair<long ,long> > temp,ans;
map<pair<long, pair<long, long> >, long > dist;
set<pair<long, pair<long, long> > > was;
map<pair<long, pair<long, long> >, pair<long, pair<long, long> > > par;
long usd[200];
pair<long, long> tp;
vector<pair<long, long> > tv;

pair<long, long> solve(
pair<long, pair<long ,long> > a,
pair<long, pair<long ,long> > b)
{
           pair<long, long> p;
 vector<long> v1,v2;
 v1.push_back(a.first);v1.push_back(a.second.first);v1.push_back(a.second.second);
 v2.push_back(b.first);v2.push_back(b.second.first);v2.push_back(b.second.second);
 
 for (int i=0;i<v1.size();i++)
 {
 long fl=0;
  for (int j=0;j<v2.size();j++)
  if (v2[j]==v1[i])fl=1;
  if (fl==0)p.first=v1[i];
 }
 
 for (int i=0;i<v2.size();i++)
 {
 long fl=0;
  for (int j=0;j<v1.size();j++)
  if (v1[j]==v2[i])fl=1;
  if (fl==0)p.second=v2[i];
 }
 return p;
}

vector<long> v;
pair<long, pair<long, long> > t;

void tryy(long a,long b,long c)
{
 v[0]=a;v[1]=b;v[2]=c;
 sort(v.begin(),v.end());
 t.first=v[0];t.second=make_pair(v[1],v[2]);
 if (was.find(t)!=was.end())return;
 was.insert(t);
 par[t]=temp;
 dist[t]=dist[temp]+1;
 qu.push(t);
}

bool nice(pair<long, pair<long, long> > temp)
{
 vector<long> v;
 v.push_back(temp.first);
 v.push_back(temp.second.first);
 v.push_back(temp.second.second);
 sort(v.begin(),v.end());
 for (int i=0;i<v.size();i++)
 if (v[i]!=i+1)return false;
 return true;
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

v.push_back(0);v.push_back(0);v.push_back(0);

cin>>n;
cin>>a>>b>>c;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=n;j++)
 ar[i][j]=st[j-1];   
}

if (a>b)swap(a,b);
if (a>c)swap(a,c);
if (b>c)swap(b,c);

qu.push(make_pair(a,make_pair(b,c)));
was.insert(qu.front());

while (qu.size())
{
 temp=qu.front();
 qu.pop();
 if (nice(temp)){ans=temp;break;}
 for (int i=1;i<=n;i++)
 usd[i]=0;
 usd[temp.first]=1;
 usd[temp.second.first]=1;
 usd[temp.second.second]=1;
 
 for (int i=1;i<=n;i++)
 {
  if (usd[i])continue;
  
  if (ar[i][temp.first]==ar[temp.second.first][temp.second.second])
  tryy(i,temp.second.first,temp.second.second);
  
  if (ar[i][temp.second.first]==ar[temp.first][temp.second.second])
  tryy(i,temp.first,temp.second.second);
  
  if (ar[i][temp.second.second]==ar[temp.first][temp.second.first])
  tryy(i,temp.first,temp.second.first);
 }
 
}

if (ans.first==0)
cout<<-1<<endl;
else
{
cout<<dist[ans]<<endl;
while (dist[ans]!=0)
{
 temp=par[ans];
 tp=solve(temp,ans);
 tv.push_back(tp);
 ans=temp;
}
reverse(tv.begin(),tv.end());
for (int i=0;i<tv.size();i++)
cout<<tv[i].first<<" "<<tv[i].second<<endl;
}
cin.get();cin.get();
return 0;}