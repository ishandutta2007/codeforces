/*
Tombstone shadow, stretchin' across my path.
Tombstone shadow, stretchin' across my path.
Ev'ry time I get some good news, Ooh,
There's a shadow on my back.
Saw the gypsy man, 'way down in San Berdoo.
Said, I saw the gypsy man, 'way down in San Berdoo.
Five dollars on the table, Ooh,
Keep me 'way from my tomb.
Oh! Oh!

Said I got thirteen months of bad luck,
Bound to be some pain.
Don't you do no trav'lin',
Fly in no machines.
Tombstone shadow, stretchin' across my path.
Ev'ry time I get some good news, Ooh,
There's a shadow on my back.

The man gave me a luck charm, Cost five dollars more,
Said, "Put some on your pillow, and put some on your door."
He said, "Take a long vacation, Ooh,
For thirteen months or more."
Oh, Lord!

Tombstone shadow, stretchin' across my path.
Tombstone shadow, stretchin' across my path.
Ev'ry time I get some good news, Ooh,
There's a shadow on my back.

Oh, oh, Lord!
Oh, Lord!
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n;
int x[1<<20];
map<int, int> mapp,rmap;

int get_first(int X)
{
    int l,r;
    l=0;
    r=n-1;
    while (l<r)
    {
        int mid=l+r;
        mid/=2;
        if (x[mid]>=X)
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

int get_last(int X)
{
    int l,r;
    l=0;
    r=n-1;
    while (l<r)
    {
        int mid=l+r+1;
        mid/=2;
        if (x[mid]<=X)
            l=mid;
        else
            r=mid-1;
    }
    return l;
}
int solve(int id,int len,int dir,int dep)
{
    int mov=0;
    if (id+1<n&&x[id+1]<=x[id]+len) mov=1;
    if (id>0&&x[id-1]>=x[id]-len)mov=1;
    if (mov==0) // easy
        return id;
    
    if (dir==1)
    {
        int tid=get_last(x[id]+len);
        if (tid==id)
            return solve(id,len,-1,dep+1);
        // todo
        if ((x[tid]-x[id])*2>=len||dep<4)// nice
            return solve(tid,len-(x[tid]-x[id]),1,dep+1);
        int full=len/(x[tid]-x[id]);
        if (full%2==0)
            return solve(id,len-full*(x[tid]-x[id]),-1,dir+1);
        else
            return solve(tid,len-full*(x[tid]-x[id]),1,dir+1);
    }
    else
    {
        int tid=get_first(x[id]-len);
        if (tid==id)
            return solve(id,len,1,dep+1);
        if ((x[id]-x[tid])*2>=len||dep<4)
            return solve(tid,len-(x[id]-x[tid]),-1,dep+1);
        int full=len/(x[id]-x[tid]);
        if (full%2==0)
            return solve(id,len-full*(x[id]-x[tid]),1,dir+1);
        else
            return solve(tid,len-full*(x[id]-x[tid]),-1,dir+1);
    }
}

int tests;
vector<pair<int, int> > v;
int id,len;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>tests;
for (int i=1;i<=n;i++)
{
    cin>>x[i];
    v.push_back(make_pair(x[i],i));
}

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
    mapp[v[i].second]=i;
    rmap[i]=v[i].second;
    x[i]=v[i].first;
}

for (;tests;--tests)
{
    cin>>id>>len;
    id=mapp[id];
    int res=solve(id,len,1,0);
    res=rmap[res];
    cout<<res<<endl;
}

//cin.get();cin.get();
return 0;}