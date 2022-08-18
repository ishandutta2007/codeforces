/*
And I wipe the night from my eyes
And block out that sunny day and I hide
And everything's falling down around us
I'm just missing the rain, yeah

And I'm happier now, today
And don't let me down
And don't let me go
Change of seasons, inside her mind
In time I'll decide
In time I'll decide to move on

Change directions, watch the tides
And we borrow too much
We form restrictions, we form lines
And we separate you from me

But sometimes
Sometimes we carry more weight than we own
Oh, sometimes
And sometimes goes on

And night takes the light by the hand
And tunes out that boring day and cries out loud
And everyone's hangin' on, hangin' on my words
Kills the thrill in being divine

She's happier now, today
And don't let her down
Don't let her go
Found no reasons to find no lies
We just bleed together
That's how we realize that we

Change directions, watch the tides
And we borrow too much
We form restrictions, we form lines
And we separate you from me

But sometimes
And sometimes we carry more weight than we own
Oh, but sometimes
And sometimes goes on and on and on and on and on
Oh, but sometimes

And somehow we'll find a way
We'll paste it back together
These ripped out pages of old coloring books were young
Gold is silver, my blue is gray
It's all held together by cellophane tape, but we

Change directions, we'd watch the tides
And we borrow too much
We form restrictions, we form lines
And we separate you from me

But sometimes
And sometimes we carry more weight than we own
Oh, but sometimes
And sometimes goes on and on and on and on, oh

In my head, I've got everything I want
And in my head I've got everything I want
And in my head I've got everything I want
And in my head I've got everything I want
And yeah
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long long n,d,h[1<<20];
vector<long long> v;
long long calc;
map<long long, long long> mapp,rmap;
set<long long> values;
set<long long>::iterator it;
long long tans[1<<20],par[1<<20];
pair<long long, long long> t[1<<20];
long long temp;
long long cur,id;

pair<long long, long long> tp;

bool better(pair<long long, long long> p1,pair<long long, long long> p2)
{
 return p1.first>p2.first;
}

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  t[v]=make_pair(tans[tl],tl);
  return;
 }
 long tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2,tm+1,tr);
 if (better(t[v*2],t[v*2+1]))
 t[v]=t[v*2];
 else t[v]=t[v*2+1];
}

void update(long v,long tl,long tr,long ps,long val)
{
     if(tl==tr)
     {
      t[v]=make_pair(val,ps);
      return;
     } 
     long tm=tl+tr;
     tm/=2;
     if (tm>=ps)update(v*2,tl,tm,ps,val);
     else update(v*2+1,tm+1,tr,ps,val);
     if (better(t[v*2],t[v*2+1]))
     t[v]=t[v*2];
     else
     t[v]=t[v*2+1];
}

pair<long long, long long> get(long v,long tl,long tr,long l,long r)
{
 if (l>r)return make_pair(-100000000,-100000000);
 if (tl==l&&tr==r)return t[v];
 long tm=tl+tr;
 tm/=2;
 pair<long long, long long> p1=get(v*2,tl,tm,l,min(r,tm));
 pair<long long,long long> p2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 if (better(p1,p2))return p1;
 return p2;
}

long long lent[1<<20];
long long bst,dp[1<<20];
vector<long long> ans;
long bp;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>d;
for (int i=1;i<=n;i++)
cin>>h[i];

for (int i=1;i<=n;i++)
{
 v.push_back(h[i]);
}

v.push_back(-1e17);
v.push_back(1e17);

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 if (i==0||v[i]!=v[i-1])
 {
  ++calc;
  mapp[v[i]]=calc;
  rmap[calc]=v[i];
  values.insert(v[i]);
 } 
}

for (int i=0;i<=calc;i++)
 tans[i]=-1e9;
 
it=values.end();
--it;
temp=(*it);

long toupd;

temp=mapp[temp];
tans[temp]=0;

update(1,1,calc,temp,0);

for (int i=1;i<=n;i++)
{
 toupd=0;
 cur=mapp[h[i]];
 // upr
 it=values.lower_bound(h[i]+d);
 if (it!=values.end())
 {
  temp=(*it);
  id=mapp[temp];
//  cout<<cur<<"  "<<temp<<" "<<h[i]<<" "<<h[i]+d<<" "<<id<<endl;
  tp=get(1,1,calc,id,calc);
   dp[i]=tp.first+1;
   par[i]=lent[tp.second];
   
  // cout<<tp.first<<"  "<<tp.second<<"  "<<id<<"  ^ "<<rmap[id]<<" "<<cur<<" "<<tans[cur]<<endl;
  if (tp.first>=tans[cur])
  {
   toupd=1;
//   cout<<"UPD"<<endl;
//   update(1,1,n,cur,tp.first+1);
   dp[i]=tp.first+1;
   par[i]=lent[tp.second];
   tans[cur]=tp.first+1;
  }
  //cout<<toupd<<"("<<endl;
 }   
// cout<<toupd<<"&&"<<endl;
 it=values.lower_bound(h[i]-d+1);
 if (it!=values.begin())
 {
  --it;
  temp=(*it);
  id=mapp[temp];
  tp=get(1,1,calc,1,id);
 // cout<<tp.first<<" "<<tp.second<<" "<<id<<" "<<rmap[id]<<endl;
  
//  cout<<tp.first<<"   "<<tp.second<<endl;
  if (tp.first>=tans[cur])
  {
   dp[i]=tp.first+1;
   par[i]=lent[tp.second];
   toupd=1;
   tans[cur]=tp.first+1;
  }
 }
 //cout<<tans[cur]<<endl;
 
//2 cout<<toupd<<"^"<<endl;
 if (toupd){
   update(1,1,calc,cur,tans[cur]);
 lent[cur]=i;}
}

bst=-1;
for (int i=1;i<=n;i++) if (dp[i]>bst)
 {bst=dp[i];
 bp=i;}

for (int i=1;i<=bst;i++)
{
 ans.push_back(bp);
 bp=par[bp];
}
reverse(ans.begin(),ans.end());
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}