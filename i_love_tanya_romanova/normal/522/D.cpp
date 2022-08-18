/*
Fly away; Enola Gay
Carrying the bomb of judgement day
In their minds they knew it too well
Angels sent from hell
The empire strikes; pacific suprise
Harbour's on fire, a fatal advice
Victory; the world is at stake
A bound that no one could break

Land of the rising sun
Everyone; waiting for the rain
Atomic clouds
Black Rain
Black Rain
Hiroshima; drowning in Black Rain

A burning child; still alive
Seek the river; for the final dive
Bodies floating out to the sea
Into eternity
All lost in flames, panic and pain
The day turned to night, but here comes the rain
They all drank to borrow some time
Radiated cries

Home of the Samurai
They're warriors; waiting for the rain
Atomic clouds
Black Rain
Black Rain
Hiroshima; drowning in Black Rain
Hiroshima
Black Rain
Hiroshima

Land of the rising sun
Everyone; waiting for the rain
Atomic clouds
Black Rain
Nuclear dust
Black Rain: they saw it coming down
Black Rain: over Hiroshima
Black Rain, coming from heaven
Drinking in the Black Rain.
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

using namespace std;

int n,m,ar[1<<20];
int l[1<<20],r[1<<20];
int ans[1<<20];
int t[1<<20];
vector<pair<int, int> > events;
map<int, int> lent;
set<int> was;

void build(int v,int tl,int tr)
{
    t[v]=1e9;
    if (tl==tr)return;
    int tm=tl+tr;
    tm/=2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
}

void update(int v,int tl,int tr,int ps,int val)
{
    if (tl==tr)
    {
        t[v]=val;
        return;
    }
    int tm=tl+tr;
    tm/=2;
    if (ps<=tm)
     update(v*2,tl,tm,ps,val);
    else
     update(v*2+1,tm+1,tr,ps,val);
    t[v]=min(t[v*2],t[v*2+1]);
}

int get(int v,int tl,int tr,int l,int r)
{
    if (l>r)return 1e9;
    if (tl==l&&tr==r)
     return t[v];
    int tm=tl+tr;
    tm/=2;
    return min(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
{
    cin>>ar[i];
}

for (int i=1;i<=m;i++)
 cin>>l[i]>>r[i];

for (int i=1;i<=n;i++)
{
    events.push_back(make_pair(i,-1));
} 

for (int i=1;i<=m;i++)
{
    events.push_back(make_pair(r[i],i));
}

sort(events.begin(),events.end());

build(1,1,n);

for (int i=0;i<events.size();i++)
{
    if (events[i].second==-1) // nmb
    {
        int val=ar[events[i].first];
        if (was.find(val)!=was.end())
        {
            int ps=lent[val];
            update(1,1,n,ps,events[i].first-ps);
        }
        was.insert(val);
        lent[val]=events[i].first;
    }
    else
    {
        int id=events[i].second;
        int res=get(1,1,n,l[id],r[id]);
        if (res>1e6)res=-1;
        ans[id]=res;
    }
}

for (int i=1;i<=m;i++)
{
    cout<<ans[i]<<endl;
}

//cin.get();cin.get();
return 0;}