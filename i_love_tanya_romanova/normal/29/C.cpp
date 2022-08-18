/*
I breach your life
Indoctrinate
Police your thoughts
Ask why I hate
I lose control
When I see your face
Abusing power
I infiltrate
Continue lies
Then masturbate
I walk the line
I'll do no time
I hate your church
I'll burn your state
A bleeding heart
A seal of fate
There is no crime
Within my mind
I'll sell your life and preach your death
A wicked plan born of contempt
Bleeding my ideology through pain

Audacious plans
I calculate
A new world view
I'll re-instate
Don't cross my path
Or I'll see you burn
You'll meet your end
Find death alone
No grave to mark
The seds you've sown
You've pushed too far
My secrets I defend
I'll sell your life and preach your death
A wicked plan born of contempt
Bleeding my ideology through pain

Demonize what is feared profane architect
Skull and bones through the mind
Barbaric thoughts of old
Celebrate all unknown
At last the dead await
The die is cast for the meek
Inherit endless dead time
Smell the victims are near
consume the catalyst
Hunting masses for game
implanting septic thoughts
Reaping terror through words while
armed behind your back
Pseudo leaders betray
enslaving all of mankind
Cast out the Demi God
Dethrone the demagogue
Cast out the church God
I command your life
And I don't care
Let bullets rain
From everywhere
No suicide
Will save you from yourself
*/

#pragma comment(linker, "/STACK:16777216")
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long a,b,n,ans;
vector<long> dif;
map<long, vector<long> >g;
map<long, long> deg;
vector<long> av;
map<long, vector<long> > ::iterator it;

void dfs(long v,long par)
{
 vector<long> vec=g[v];
 
 for (int i=0;i<vec.size();i++)
 {
  
     long q=vec[i];
 if (q!=par){dfs(q,v);}
 }
 av.push_back(v);    
}

int main(){
//freopen("cooling.in","r",stdin);
//freopen("cooling.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
 dif.push_back(a);dif.push_back(b);
 deg[a]++;
 deg[b]++;   
}

ans=0;
for (int i=0;i<dif.size();i++)
if (deg[dif[i]]==1)ans=dif[i];

//cout<<ans<<endl;
dfs(ans,-1);

for(int i=0;i<av.size();i++)
{
if (i)cout<<" ";
cout<<av[i];        
}
cout<<endl;

cin.get();cin.get();
return 0;}