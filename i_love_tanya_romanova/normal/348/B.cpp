/*
I'm home again, I won the war, and now I am behind
your door. I tried so hard to obey the law, and see the
meaning of this all. Remember me? Before the war.
I'm the man who lived next door. Long ago...

As you can see, when you look at me, I'm pieces of
what I used to be. It's easier when you don't see me
standing on my own two feet. I'm taller when I sit
here still, you ask are all my dreams fulfilled.
They made me a heart of steal, the kind them bullets
cannot see, yeah.

Nothing's what it seems to be,
I'm a replica, I'm a replica
Empty shell inside of me
I'm not myself, I'm a replica of me...

The light is green, my slate is clean, new life to fill
the hole in me. I had no name, last December, Christmas
Eve I can't remember. I was in a constant pain, I saw
your shadow in the rain. I painted all your pigeons red,
I wish I had stayed home instead, yeah.

Nothing's what it seems to be,
I'm a replica, I'm a replica
Empty shell inside of me
I'm not myself, I'm a replica of me...

Are you gonna leave me now, when it is all over
Are you gonna leave me, is my world now over...

Raising from the place I've been, and trying to keep
my home base clean. Now I'm here and won't go back believe.

I fall asleep and dream a dream, I'm floating in a
silent scream. No-one placing blame on me
But nothing's what it seems to be, yeah.

Nothing's what it seems to be,
I'm a replica, I'm a replica
Empty shell inside of me
I'm not myself, I'm a replica of me...
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
#define bsize 256
#define clone agsdahfaassdg

using namespace std;

long long n,sz[200000],a,b;
vector<long long> g[200000];
long long arp[200000];
vector<long long> sons[200000];
long isleaf[200000];
long long lcm[200000];
long long tsz[200000];

long long gcd(long long a,long long b)
{while (a&&b)a>b?a%=b:b%=a;
return a+b;
}

long long lccm(long long a,long long b)
{
 if (b==0)return a;
 if (a==0)return b;
 a/=gcd(a,b);
 if (1e18/a<=b)return 1e18;
 //cout<<a<<" "<<b<<endl;
 return a*b;
}


long long lccm1(long long a,long long b)
{
 if (b==0)return a;
 if (a==0)return b;
 //a/=gcd(a,b);
 if (1e18/a<=b)return 1e18;
 //cout<<a<<" "<<b<<endl;
 return a*b;
}
long long update(long long v,long long q)
{
     return lccm(v,q);
} 


long long update1(long long v,long long q)
{
     return lccm1(v,q);
} 

void dfs(long v)
{
 arp[v]=1;
 for (int i=0;i<g[v].size();i++)
 {long long q=g[v][i];
  if (arp[q])continue;
  sons[v].push_back(q);
  dfs(q);
 }
 
 if (sons[v].size()==0)isleaf[v]=1;
 
 lcm[v]=1;
 
 for (int i=0;i<sons[v].size();i++)
 {
     lcm[v]=update(lcm[v],lcm[sons[v][i]]);
 } 
 
 long long mval=1000000000000000000ll;
 for (int i=0;i<sons[v].size();i++)
 mval=min(mval,tsz[sons[v][i]]);
 
 mval-=mval%lcm[v];
 
 for (int i=0;i<sons[v].size();i++)
 {
     tsz[sons[v][i]]=mval;
     tsz[v]+=tsz[sons[v][i]];
 }
 tsz[v]+=sz[v];
 
 long long q=sons[v].size();
 lcm[v]=update1(lcm[v],q);
 
 //cout<<"%"<<v<<" "<<tsz[v]<<" "<<mval<<endl;
}

long long ttemp;

int main(){
//freopen("virtualfriends.in","r",stdin);
//freopen("virtualfriends.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i<=n;i++)
{
 cin>>sz[i];   
}

for (int i=1;i<=n;i++)
ttemp+=sz[i];


for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs(1);
cout<<ttemp-tsz[1]<<endl;
/*
for (int i=1;i<=n;i++)
{
    for (int j=0;j<sons[i].size();j++)
    cout<<sons[i][j]<<" ";
    cout<<endl;
}
*/

//for (int i=1;i<=n;i++)
//cout<<i<<"   "<<tsz[i]<<" "<<lcm[i]<<endl;


cin.get();cin.get();
return 0;}