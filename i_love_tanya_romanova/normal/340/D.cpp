/*
At home
Drawing pictures
Of mountain tops
With him on top
Lemon yellow sun
Arms raised in a V
Dead lay in pools of maroon below

Daddy didn't give attention
To the fact that mommy didn't care
King Jeremy the wicked
Ruled his world

Jeremy spoke in class today
Jeremy spoke in class today

Clearly I remember
Pickin' on the boy
Seemed a harmless little fuck
But we unleashed a lion
Gnashed his teeth
And bit the recess lady's breast

How could I forget
He hit me with a surprise left
My jaw left hurting
Dropped wide open
Just like the day
Like the day I heard

Daddy didn't give affection
And the boy was something that mommy wouldn't wear
King Jeremy the wicked
Ruled his world

Jeremy spoke in class today
Jeremy spoke in class today
Try to forget this...
Try to erase this...
From the blackboard.
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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

/*
long n,ar[200000],comps,arp[1000];
vector<long> g[1000];

void dfs(long v)
{
     arp[v]=1;
     for (int i=0;i<g[v].size();i++)
     {
         long q=g[v][i];
         if (arp[q])continue;
         dfs(q);
     }
}
*/

long n,d[500000],l,r,m,answ,ar[500000];

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
/*
cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

for (int iter=1;iter<=n;iter++)
for (int i=1;i<n;i++)
if (ar[i]>ar[i+1])
{
                  g[ar[i]].push_back(ar[i+1]);
                  g[ar[i+1]].push_back(ar[i]);
                  cout<<ar[i]<<" "<<ar[i+1]<<endl;
                  swap(ar[i],ar[i+1]);
}

for (int i=1;i<=n;i++)
if (arp[i]==0)
{
 ++comps;
 dfs(i);
}

cout<<comps<<endl;
*/

cin>>n;
for (int i=0;i<n;i++)
cin>>ar[i];

for (int i=0;i<=n;i++)
d[i]=1000000000;

d[0]=-100000000;

for (int i=0;i<n;i++)
{
 l=0;
 r=n;
 while (l<r)
 {
       long m=l+r+1;m/=2;
       if (d[m]<ar[i])l=m;else r=m-1;
 }
 if (d[l]<ar[i]&&ar[i]<d[l+1])
 d[l+1]=ar[i];   
}

for (int i=1;i<=n;i++)
if (d[i]<100000000)
answ=i;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}