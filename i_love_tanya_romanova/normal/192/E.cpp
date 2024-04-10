/*
Hello me ... Meet the real me
And my misfits way of life
A dark black past is my
Most valued possessions
Hindsight is always 20-20
But looking back it's still a bit fuzzy
Speak of mutually assured destruction?
Nice story ... Tell it to Reader's Digest!!!

Feeling paranoid
True enemy or false friend?
Anxiety's attacking me, and
My air is getting thin
I'm in trouble for the things
I haven't got to yet
I'm chomping at the bit and my
Palms are getting wet, sweating bullets

Hello me ... It's me again
You can subdue, but never tame me
It gives me a migraine headache
Thinking down to your level
Yea, just keep on thinking it's my fault
And stay an inch or two outta kicking distance
Mankind has got to know
His limitations

Feeling claustrophobic
Like the walls are closing in
Blood stains on my hands and
I don't know where I've been
I'm in trouble for the things
I haven't got to yet
I'm sharpening the axe, and my
Palms are getting wet, sweating bullets

Well, me ... It's nice talking to myself
A credit to dementia
Some day you too will know my pain
And smile its blacktooth grin
If the war inside my head
Won't take a day off I'll be dead
My icy fingers claw your back
Here I come again

Feeling paranoid
True enemy or false friend?
Anxiety's attacking me, and
And my air is getting thin
Feeling claustrophobic
Like the walls are closing in
Blood stains on my hands and
I don't know where I've been
Once you committed me
Now you've acquitted me
Claiming validity
For your stupidity
I'm chomping at the bit
I'm sharpening the axe
Here I come again, whoa!
Sweating bullets
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

 vector<long> g[300000];
vector<long> tin, tout;
long timer;
 vector<long> up[300000];
 long n,l,k,a,b,ans[600000],ts[600000],arp[600000],d[500000],ind;

pair <long, long> p;
map <pair <long, long> ,long> m;


void dfs (long v, long p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

bool upper (long a, long b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

long lca (long a, long b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}


void dfs1(long a)
{
 arp[a]=1;
 long q;
 

 
 for (int i=0;i<g[a].size();++i)
 {
  q=g[a][i];
  if (arp[q]==0){
                 dfs1(q);
                 p=make_pair(a,q);
                 ind=m[p];
                // cout<<ind<<endl;
                 ans[ind]=ts[q];
                  ts[a]+=ts[q];    
                 }     
 }
 ts[a]+=d[a];
}

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;

for (int i=0;i<n-1;i++)
{
    cin>>a>>b;
    --a;--b;
    p=make_pair(a,b);
    m[p]=i;
    p=make_pair(b,a);
    m[p]=i;
    g[a].push_back(b);
    g[b].push_back(a);
}

cin>>k;

tin.resize (n);tout.resize (n);
l = 1;
while ((1<<l) <= n)  ++l;
for (int i=0; i<n; ++i)  up[i].resize (l+1);
dfs (0);


for (int i=0;i<k;i++) 
        {
        cin>>a>>b;
        --a;--b;
        d[a]++;
        d[b]++;
        d[lca(a,b)]-=2;
        }


dfs1(0);
/*
for (int i=0;i<n;i++)
cout<<d[i]<<" ";cout<<endl;
for (int i=0;i<n;i++)
cout<<ts[i]<<" ";cout<<endl;
*/

for (int i=0;i<n-1;i++)
{
if (i)cout<<" ";    cout<<ans[i];
}

cout<<endl;


cin.get();cin.get();
return 0;}