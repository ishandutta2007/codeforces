/*
Kill. Kill them all. Pigs written in blood on the walls.
Your not entitle to accuse and judge one single man
if you allow all shit that's happening in this damned
rotten land. The pressure your damned system,
religion and school puts on our minds creates an all
collective pain that no damn walls can keep inside.

Do you really think that all evil and madness rests in me.
Do you think you're safe locking me up
and then throwing away the key.

Can't you see I'm out, man. Can't you see I'm free.
Can't you see I'm out, man. Can't you see I'm just
a product of a broken nation's shattered dream.

Death. Death to all. Pigs screaming, The blood runs
down the walls. You'll never be successful trying to
keep the madness behind these walls because the pain
comes from inside and creates chaos within all.
You can put me in the chair and watch me f*cking fry.
But I am aware my death's a nation's alibi.

Can't you see I'm out, man. Can't you see I'm free.
Can't you see I'm out, man. Can't you see I'm just
a product of a broken nation's shattered dream.

Kill. Kill them all. Pigs written in blood on the walls.
Your not entitle to accuse and judge one single man
if you allow all shit that's happening in this damned
rotten land. The pressure your damned system,
religion and school puts on our minds creates an all
collective pain that no damn walls can keep inside.

Do you really think that all evil and madness rests in me.
Do you think you're safe locking me up
and then throwing away the key.

Can't you see I'm out, man. Can't you see I'm free.
Can't you see I'm out, man. Can't you see I'm just
a product of a broken nation's shattered dream.
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
//#include <memory.h>

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
#define bsize 256

using namespace std;

long n,m,k,a,b;
vector<long> g[200000];
vector<long> ans;
long arp[200000];
long p;
long good[200000];

void dfs(long v)
{
 arp[v]=ans.size()+1;
 ans.push_back(v);
 long fl=0;
 for (int i=0;i<g[v].size();i++)
 {
     long q=g[v][i];
     if (arp[q])continue;
     else{fl=1;dfs(q);break;}
 }
 if (fl==0)
 {
           for (int j=0;j<g[v].size();j++)
            good[g[v][j]]=1;
            p=0;
            while (good[ans[p]]==0)++p;
 }
 
}

int main(){
//freopen("scanner.in","r",stdin);
//freopen("scanner.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs(1);

//cout<<p<<endl;
cout<<ans.size()-p<<endl;
for (int i=p;i<ans.size();i++){if (i-p)cout<<" ";
cout<<ans[i];}
cout<<endl;

cin.get();cin.get();
return 0;}