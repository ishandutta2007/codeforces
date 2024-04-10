/*
Fix the mental, as if that changes anything
Your heart is cured now, you're normal once again
One confession, you thought that's all it took
But redemption, doesn't let you off the hook

One of us
Can't erase the past to change who he would be
One of us
On a whim would act, then look for sympathy
Not from me

Hear me say...

One more
Chance to believe in
That you can even the score
One more
Place at the table
Always room for one more
Room for one more

Thing evil, is that just your normal gig
Fueled by hatred, happy as a stuffed pig
You're so lonely, everyone around you reeks
Of indifference, thriving in their apathy

Your schism, my distress
Your failure is my success
Squeezed out, kept me down
What goes around comes around
I can wait you out
Patience is my virtue
Call it payback, call it proper grounds
What goes around always comes around, always comes around
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
#define eps 1e-9
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
#define ttl 4888888
#define clone agsdahfaassdg

using namespace std;

long n,m,d,q;
long bd[200000];
long arp[200000];
vector<long> g[200000];
long up[200000],down[200000];
vector<pair<long,long> > dns[200000];
long a,b;

void dfs(long v)
{
 arp[v]=1;
 if (bd[v])down[v]=0;
 
 for (int j=0;j<g[v].size();j++)
 {
  long q=g[v][j];
  if (arp[q])continue;
  dfs(q);
  //if (down[q]!=-1)
  down[v]=max(down[v],down[q]+1);
  dns[v].push_back(make_pair(down[q],q));   
 }
 
 sort(dns[v].begin(),dns[v].end());
 reverse(dns[v].begin(),dns[v].end());
 
}


void dfs1(long v)
{
     //cout<<v<<endl;
     
 arp[v]=1;
 if (bd[v])up[v]=max(up[v],up[v]-up[v]);
 
 for (int j=0;j<g[v].size();j++)
 {
  long q=g[v][j];
  if (arp[q])continue;
  if (bd[q])up[q]=0;
  
  up[q]=max(up[q],up[v]+1);
  if (dns[v].size()!=1){
  if (dns[v][0].second==q)up[q]=max(up[q],dns[v][1].first+2);
  else up[q]=max(up[q],dns[v][0].first+2);  
  }
  dfs1(q);
 }     
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>d;

for (int i=1;i<=n;i++)down[i]=up[i]=-10000000;

for (int i=1;i<=m;i++)
{cin>>q;bd[q]=1;}

for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs(1);

for (int i=1;i<=n;i++)
arp[i]=0;

dfs1(1);

//cout<<endl;
/*for (int i=1;i<=n;i++)
cout<<up[i]<<" "<<down[i]<<endl;
*/

long ans=0;
for (int i=1;i<=n;i++)
if (max(up[i],down[i])<=d)++ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}