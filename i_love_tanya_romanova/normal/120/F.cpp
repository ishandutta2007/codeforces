/*
Tell me which side I'm on
Approaching constant failure
Tell me which side I'm on
(Who's friend or foe?)
Approaching constant failure

Between love and hate
Which path to follow?
How can I keep balance in this race?
Come faith, I'm dying (slowly)

In many ways I'm the burden that devides us from the light
In many ways you're the halo that keeps my spirit alive

Temptation
Play the good or evil part
With me, you evoke the dark
Erase the free will and watch me heal

Tell me which side I'm on
Approaching constant failure

Between love and hate
Which path to follow?
How can I keep balance in this race?
Come faith, I'm dying...

Amused by the trials and tribulations
If I survive I fly from here
But as the chosen pessimist

I carve my name in stone
I carve my name in stone

Amused by the trials and tribulations
If I survive I fly from here

How can I keep balance in this race?
Come faith I'm dying...
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long tests,n,a,b;
vector<long> g[20000];
long ans,mx;
long arp[1000];

void dfs(long v)
{
 for (int i=0;i<g[v].size();i++)
 {
     long q=g[v][i];
     if (arp[q])continue;
     arp[q]=arp[v]+1;
     dfs(q);
 }
}

int main(){
//freopen("line3.in","r",stdin);
//freopen("line3.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    g[i].clear();
    
    for (int i=1;i<n;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    mx=0;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        arp[j]=0;
        arp[i]=1;
        dfs(i);
        for (int j=1;j<=n;j++)
        mx=max(mx,arp[j]-1);
    }
    ans+=mx;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}