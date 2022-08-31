/*
I'm home again, I won the war, and now I am behind your door.
I tried so hard to obey the law, and see the meaning of this all.
Remember me? Before the war.
I'm the man who lived next door.
Long ago...

As you can see, when you look at me, I'm pieces of what I used to be.
It's easier if you don't see standing on my own two feet.
I'm taller when I sit here still, you ask are all my dreams fulfilled.
They made me heart of steal, the kind them bullets cannot see, yeah.

Nothing's what it seems to be
I'm a replica, I'm a replica
Empty shell inside of me
I'm not myself, I'm a replica of me...

The light is green, my slate is clean, new life to fill the hole in me.
I had no name, last December, Christmas Eve I can't remember.
I was in a constant pain, I saw your shadow in the rain.
I painted all your pigeons red, I wish I had stayed home instead.

Nothing's what it seems to be
I'm a replica, I'm a replica
Empty shell inside of me
I'm not myself, I'm a replica of me...

Are you gonna leave me now, when it is all over
Are you gonna leave me, is my world now over...

Raising from the place I've been, and trying to keep my home base clean.
Now I'm here and won't go back believe.

I fall asleep and dream a dream, I'm floating in the silent dream.
No-one place blame on me.
But nothing's what it seems to be, yeah.

Nothing's what it seems to be
I'm a replica, I'm a replica
Empty shell inside of me
I'm not myself, I'm a replica

Nothing's what it seems to be
I'm a replica
Empty shell inside of me
I'm replica of...

Nothing's what it seems to be
I'm a replica
Empty shell inside of me
I'm a replica

Nothing's what it seems to be
I'm a replica
Empty shell inside of me
I'm replica of me...

I'm home again, I won the war, and now I am behind your door.
I tried so hard to obey the law, and see the meaning of this all.
Remember me? Before the war.
I'm the man who lived...
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
//#include <memory.h>

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

long n,m,ar[1100][1100];
long long si[12000],sj[120000];
multiset<long long> sett;
multiset<long long>::iterator it;
long long k,p;
vector<long long> v1,v2;
long long s1[1200000],s2[1200000];
long long val,ans;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k>>p;
for (int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
{  cin>>ar[i][j];
si[i]+=ar[i][j];
 sj[j]+=ar[i][j];}

for (int i=1;i<=n;i++)
{
 sett.insert(si[i]);
}

for (int i=1;i<=1000000;i++)
{
 it=sett.end();
 --it;
 val=(*it);
 v1.push_back(val);
 sett.erase(it);
 val-=m*p;
 sett.insert(val);
}

sett.clear();
for (int i=1;i<=m;i++)
{
 sett.insert(sj[i]);
}

for (int i=1;i<=1000000;i++)
{
 it=sett.end();
 --it;
 val=(*it);
 v2.push_back(val);
 sett.erase(it);
 val-=n*p;
 sett.insert(val);
}

ans=-1e18;

for (int i=1;i<=1000000;i++)
s1[i]=s1[i-1]+v1[i-1],
s2[i]=s2[i-1]+v2[i-1];

for (int i=0;i<=k;i++)
 ans=max(ans,s1[i]+s2[k-i]-1ll*p*i*(k-i));

cout<<ans<<endl;

cin.get();cin.get();
return 0;}