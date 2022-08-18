/*
Got on chance, infiltrate them
Get it right, terminate them
The Panzers will, permeate them
Break their pride, denigrate them
And their people, retrograde them
Typhus, deteriate them
Epidemic, devastate them
Take no prisoners, cremate them

Going to war, give 'em hell
D-Day, next stop Normandie
Beginning of the end
WE know how to and sure as shit we'll win
War is peace sure man
A retreat for the damned
A playground for the demented
A haven for those who walk this world
Bereft of heart and soul
Love and war they say all is fair
Take his life
But won't take his hair
Your body has parts your
Country can spare
By the way son here's
Your wheelchair

He once had to be all he could be
Now he's nothing for no one nowhere to see
Funny thing, he's like you & me
It's a funny thing, a funny thing
Tears streak his solemn stare
Abandoned for wreckage nobody cares
No one knew what would happen there
No one spoke no one even dared
Don't ask what you can do for you country
Ask what your country can do for you
Take no prisoners, take no shit
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,m,c,q,w;
double x[400000],cost[400000],p[400000];

struct data {
    double sum, pref, suff, ans;
};
 data t[1500000];
 
data combine (data l, data r) {
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max (l.pref, l.sum + r.pref);
    res.suff = max (r.suff, r.sum + l.suff);
    res.ans = max (max (l.ans, r.ans), l.suff + r.pref);
    return res;
}
data make_data (double val) {
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max (double(0), val);
    return res;
}
 
void build (double a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = make_data (a[tl]);
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = combine (t[v*2], t[v*2+1]);
    }
}
data query (int v, int tl, int tr, int l, int r) {
    if (l == tl && tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm)
        return query (v*2, tl, tm, l, r);
    if (l > tm)
        return query (v*2+1, tm+1, tr, l, r);
    return combine (
        query (v*2, tl, tm, l, tm),
        query (v*2+1, tm+1, tr, tm+1, r)
    );
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m>>c;
long tt;
for (int i=1;i<=n;i++)
{scanf("%d",&tt);x[i]=tt;}
for (int i=1;i<n;i++)
{scanf("%d",&tt);p[i]=tt;}

for (int i=1;i<n;i++)
{cost[i-1]=0.01*p[i]*(-c)+(x[i+1]-x[i])*0.005*100;}

build(cost,1,0,n-2);
data p;
double answ=0;
for (int i=1;i<=m;i++)
{
 scanf("%d",&q);
 scanf("%d",&w);
p=query(1,0,n-2,q-1,w-2);
answ+=max(0.0,p.ans);}
cout.precision(10);
cout<<fixed<<answ<<endl;
//for (int i=0;i<n-1;i++)
//cout<<cost[i]<<" ";
//cout<<endl;
cin.get();cin.get();
return 0;}