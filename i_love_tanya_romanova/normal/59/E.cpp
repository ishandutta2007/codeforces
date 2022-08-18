/*
There are many faces of death
But none as horrific as the irrational slaying of innocent infants
The committing of infanticide

New born innocent victim
Killed by Mother's infliction
Psychotropic sickness
There will be no forgiveness

Severe mental psychosis
A state of non compos mentis

Blood that's frozen frigid
A heart of hardened ice
A breath of death to warm her
As she makes the sacrifice

Infanticide
Infanticide

Post Partum depression
The dying child's convulsion
Vicious act of madness
Emotional breakdown and sadness

Cold and callous
Mean and malice
Sad but true
Nothing you can do

Death desire that can't be tamed
Overflow her brain
For this death she's not to blame
You know that she's insane
Psychoactive chemicals affecting all perception
Termination elimination the removal of all conception

From the womb to the grave
How can we conceive
Trauma stricken mother
Sits crying in disbelief

Hormonal dysfunction
The innocent child's destruction
Born to die
Weeping mothers cry
Nothing but waste
Consequences faced

Cold and callous
Mean and malice
Sad but true
Nothing you can do

Demonic possession
Said to leave this message
Overpowering emotion
The mother and child's devotion

Blood that's frozen frigid
A heart of hardened ice
A breath of death to warm her
As she makes the sacrifice
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000009
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long dist[3050][3050];
set<long long> bad;

long n,m,k,a,b,c;
pair<long, long> temp;
queue<pair<long, long> >qu;
vector<long> g[3050];
long par[3050][3050];
long bst,bp;
vector<long> ans;

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

for (int i=1;i<=k;i++)
{
 cin>>a>>b>>c;
 bad.insert(1ll*a*10000000+b*3001+c);
}

qu.push(make_pair(1,1));

dist[1][1]=1;

while (qu.size())
{
 temp=qu.front();
 qu.pop();
 a=temp.first;
 b=temp.second;
 for (int i=0;i<g[b].size();i++)
 {
     long tv=g[b][i];
     if (bad.find(1ll*a*10000000+b*3001+tv)!=bad.end())continue;///[a][b].find(tv)!=bad[a][b].end())continue;
     if (dist[b][tv]!=0)continue;
     dist[b][tv]=dist[a][b]+1;
     par[b][tv]=a;
     qu.push(make_pair(b,tv));
 }
}

bst=1e9;
bp=1;
for (int i=1;i<=n;i++)
 if (dist[i][n]>0&&dist[i][n]<bst)
 {
  bst=dist[i][n];
  bp=i;
 }

if (bst>1e7)
{
 cout<<-1<<endl;
}
else
{
cout<<bst-1<<endl;
a=bp;
b=n;
ans.push_back(b);
while (a>1||b>1)
{
 long temp=a;
 a=par[a][b];
 b=temp;
 ans.push_back(temp);
}
reverse(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;
}

cin.get();cin.get();
return 0;}