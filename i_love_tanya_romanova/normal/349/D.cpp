/*
Come into my home
Black master rules the night
See the power start to surge
Upon a hellish sight
It's time to raise them up
Up from below the grave
White bones glow savagery
Provide the light we crave

Turn to look at baphomet
From below and not above
Welcome to my sacrifice
Tonight there'll be no love

The darkness is my lover
She makes he feel strong
Take what I want, when I want
At night I do no wrong
When I walk the streets:
Got Loki on my side
Slit your throat, drink your blood
Who cares when others die

Turn to look at baphomet
From below and not above
Welcome to my sacrifice
Tonight there'll be no love

You thought you'd live for oh 50 long
Now it's your turn to die
Live with Satan down in hell
Born to forever cry
Took your life I don't feel bad
Born to live in hell
Died for nothing. slow decay
Your body starts to smell
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