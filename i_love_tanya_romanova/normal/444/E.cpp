/*
So tonight the time has come
To breathe in deep and sadly ride this one

To make a space in between
In the line of all my broken dreams

Does it have to be me?
Have I lost my mind?

I'm so tired but i cannot sleep
Night after night the room is empty and bleak
Down the hole growin' up in my soul

In the house of the setting sun
Another night has only just begun

Can I have another one?

I'm so tired but i cannot sleep
Night after the night the room is empty and bleak
Down the hole growin in my soul

There's a hole growing in my soul
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

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long w[200000],sz[200000],ttl[200000],ans,n;
vector<pair<long, pair<long, long> > > v;
long s,er,a,b;
long c,cur;

long gett(long x)
{
 while (x!=w[x])x=w[x];
 return x;
}

void merg(long a,long b)
{
 a=gett(a),b=gett(b);
 w[b]=a;
 sz[a]+=sz[b];
 ttl[a]+=ttl[b];
 if (sz[a]>s-ttl[a])er=1;// cn't match out
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
 cin>>a>>b>>c;
 v.push_back(make_pair(c,make_pair(a,b)));
}
sort(v.begin(),v.end());

for (int i=1;i<=n;i++)
{
 cin>>ttl[i];
 sz[i]=1;
 s+=ttl[i];
 w[i]=i;
}

if (n==1){cout<<0<<endl;return 0;}

ans=v[0].first;
for (int i=0;i<v.size();)
{
 cur=i;
 while (cur<v.size()&&v[cur].first==v[i].first)
 {
  merg(v[cur].second.first,v[cur].second.second);
  ++cur;
 }
 i=cur;
 if (i<v.size()&&er==0)ans=v[i].first; // still can slv 0..i-1 vout usn ==[i-1]
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}