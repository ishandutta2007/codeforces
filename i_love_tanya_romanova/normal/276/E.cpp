/*
A lifetime ago, with frozen eyes they closed the door.
Suddenly I realized what locks are for. No trusting them anymore, lights -
are - out.

Empty the stare, innocent and unaware, dragged out from my home ,my lair.
Earmarked me, hurt me, burned me.

The walls around me, eyes surround me, feed my fear again.
I must be freed or I will die before the harvest moon, my friend.
I do not have another year in me, you've gotta set me free.

The dream is alive, I can run up the hills every night,
go around and see another side of the tree.
Freedom has a meaning for me, howl with me.

Fear in the dark, I advice you. You can not see the eyes, they grow behind
you....
It's my song they now sing to you.
You stand no chance....

They'll kill for me, steal back my freedom, set me free, it's my minions vs.
thee.
Fiery the vengeance, hate will drain me.

The walls around me, eyes surround me, feed my fear again.
I must be freed or I will die before the harvest moon, my friend.
I do not have another year in me, you've gotta set me free.

The dream is alive, I can run up the hills every night,
go around and see another side of the tree.
All I want is to be untamed and free, howl and (dream).

The dream is alive, with the moon on the hills every night,
run around and see another side of the dream.
Freedom has a meaning for me, you can't tame me...

You will remember the day you crossed my path.
leave me without a guard and you feel my wrath.
What you have done to me has made me bitter and cruel.
I'll see that all the hate you spread returns to you, you, to you...

The walls around me, eyes surround me, feed my fear again.
I must be freed or I will die before the harvest moon, my friend.
I do not have another year in me, you've gotta set me free.

The dream is alive, I can run up the hills every night,
go around and see another side of the tree.
All I want is to be untamed and free, howl and (dream).

The dream is alive, with the moon on the hills every night,
run around and see another side of the dream.
Freedom has a meaning for me, you can't tame me...

The dream is alive, I can run up the hills every night,
go around and see another side of the tree.
All I want is to be untamed and free, howl and (dream).

The dream is alive, with the moon on the hills every night,
run around and see another side of the dream.
Freedom has a meaning for me..
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long arp[300000],qdepth;
vector<long> g[300000];
pair<long, long> pos[300000];
long n,q,a,lines,b;
vector<long long> vd[260000],vu[260000];
long v,tp;

void dfs(long v)
{
 ++qdepth;
 arp[v]=1;
 pos[v]=make_pair(lines,qdepth);
 for (int j=0;j<g[v].size();j++)
 {
     long q=g[v][j];
     if (arp[q])continue;
     dfs(q);
 }
}

void update(long nline, long psize, long val)
{
 for (int i=0;i<psize/bsize;i++)
  vu[nline][i]+=val;
 for (int i=psize/bsize*bsize;i<=psize;i++)
 vd[nline][i]+=val;
}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>q;

for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

arp[1]=1;

vd[0].resize(250100);
vu[0].resize(250100);

for (int i=0;i<250000;i++)
vd[0][i]=vu[0][i]=0;

for (int i=0;i<g[1].size();i++)
{
    long q=g[1][i];
    ++lines;
    qdepth=0;
    dfs(q);
    vd[lines].resize(qdepth+10);
    for (int j=0;j<vd[lines].size();j++)
    vd[lines][j]=0;
    vu[lines].resize(qdepth/bsize+10);
    for (int j=0;j<vu[lines].size();j++)
    vu[lines][j]=0;
}

/*for (int i=1;i<=n;i++)
{
    cout<<pos[i].first<<" "<<pos[i].second<<endl;
}*/

for (int i=1;i<=q;i++)
{
 cin>>tp;
 
 if (tp==1)
 {
     cin>>v;
     long d,nl;
     nl=pos[v].first;
     d=pos[v].second;
     if (v==1)
     { 
      cout<<vu[0][0]+vd[0][0]<<endl;
     }      
     else
     {
      long long res=0ll+vd[nl][d]+vu[nl][d/bsize]+vd[0][d]+vu[0][d/bsize];
      cout<<res<<endl;
     }
 }
 else
 {
     long v,x,dd;
     
     cin>>v>>x>>dd;
     long upd,dl;
     long nl,d,ul;
     if (v==1){update(0,dd,x);continue;}
     nl=pos[v].first;
     d=pos[v].second;
     dl=min(vd[nl].size()+0ll-2,d+dd+0ll);
     ul=max(1+d-d,d-dd);
//     cout<<dl<<" "<<ul<<endl;
     
     update(nl,ul-1,-x);
     update(nl,dl,x);
     if (d<=dd)
     {
      dd-=d;
      update(0,dd,x);
      dd=min(dd+0ll,0ll+vd[nl].size()-3);
      update(nl,dd,-x);
      
      }
 }
// cout<<vu[0][0]<<" "<<vd[0][0]<<" "<<vd[0][1]<<"  "<<vu[1][0]<<"  "<<vd[1][1]<<"    "<<vu[2][0]<<"  "<<vd[2][1]<<endl;
}

cin.get();cin.get();
return 0;}