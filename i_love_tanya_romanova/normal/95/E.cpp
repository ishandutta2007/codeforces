/*
I felt the hate rise up in me
Kneel down and clear the stone and leaves
I wander out where you can't see
Inside my shell, I wait and bleed

I felt the hate rise up in me
Kneel down and clear the stone and leaves
I wander out where you can't see
Inside my shell, I wait and bleed

Goodbye

I wipe it off on a tile, the light is brighter this time
Everything is turning blasphemy
My eyes are red and gold, the hair is standing straight up
This is not the way I picture me

I can't control my shakes, how the hell did I get here?
Something about this, so very wrong
I have to laugh out loud, I wish I didn't like this
Is it a dream or a memory?

I felt the hate rise up in me
Kneel down and clear the stone and leaves
I wander out where you can't see
Inside my shell, I wait and bleed

Get outta my head 'cause I don't need this
Why didn't I see this?
Well, I'm a victim Manchurian candidate
I have sinned by just makin' my mind up
And taking your breath away

I felt the hate rise up in me
Kneel down and clear the stone and leaves
I wander out where you can't see
Inside my shell, I wait and bleed

I felt the hate rise up in me
Kneel down and clear the stone and leaves
I wander out where you can't see
Inside my shell, I wait and bleed

Goodbye

You haven't learned a thing
I haven't changed a thing
The flesh was in my bones
The pain was always free

You haven't learned a thing
I haven't changed a thing
The flesh was in my bones
The pain was always free

I felt the hate rise up in me
Kneel down and clear the stone and leaves
I wander out where you can't see
Inside my shell I wait and bleed

I felt the hate rise up in me
Kneel down and clear the stone and leaves
I wander out where you can't see
Inside my shell, I wait and bleed

And it waits for you

And it waits for you
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

using namespace std;

long n,m,w[201000],sz[201000];
long a,b;
long calc[200100];
long t;
vector<pair<long, long> > v;
long ts,tc;
long ans;

long gett(long x)
{
 if (w[x]==x)return x;
 return w[x]=gett(w[x]);
}

bool nice(long x)
{
 while (x)
 {
  if (x%10!=4&&x%10!=7)return false;
  x/=10;
 }
 return true;
}

void merg(long a,long b)
{
 if (rand()%2)swap(a,b);
 sz[a]+=sz[b];
 w[b]=a;
}

long bst[200000];

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
{
 w[i]=i;
 sz[i]=1;
}

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 if (gett(a)==gett(b))
 continue;
 merg(gett(a),gett(b));
}
 
for (int i=1;i<=n;i++)
{
 if (w[i]==i){
             // cout<<")) "<<i<<" "<<sz[i]<<endl;
  calc[sz[i]]++;}
}
/*
for (int i=1;i<=10;i++)
 cout<<"^^ "<<i<<" "<<calc[i]<<endl;
 */
bst[0]=0;
for (int i=1;i<=n;i++)
 bst[i]=1e9;

for (int i=1;i<=100000;i++)
{
 if (calc[i]==0)continue;
 t=1;
 while (calc[i]>=t)
 {
  v.push_back(make_pair(t*i,t));
  calc[i]-=t;
  t*=2;
 }
 if (calc[i])
  v.push_back(make_pair(calc[i]*i,calc[i]));
}

for (int i=0;i<v.size();i++)
 for (int j=100000;j+1;--j)
 {
  ts=v[i].first+j;
  tc=bst[j]+v[i].second;
  bst[ts]=min(bst[ts],tc);
 }

ans=1e9;
/*
for (int i=0;i<v.size();i++)
 cout<<v[i].first<<" * "<<v[i].second<<endl;
 
for (int i=1;i<=n;i++)
 cout<<bst[i]<<"   "<<i<<endl;
 */
 
for (int i=1;i<=n;i++)
if (nice(i))
 ans=min(ans,bst[i]);
if (ans>1e8)ans=0;

cout<<ans-1<<endl;


cin.get();cin.get();
return 0;}