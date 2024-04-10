/*
Mortuaries, dead of night
My body starts to rise
In my mind the horror lives
To feel death deep inside

Relentless lust of rotting flesh
To thrash the tomb she lies
Heathen whore of Satan's wrath
I spit at your demise

Virgin child now drained of life
Your soul cannot be free
Not given the chance to rot in Hell

Satan's cross points to Hell
The earth I must uncover
A passion grows to feast upon
The frozen blood inside her

I feel the urge the growing need
To fuck this sinful corpse
My tasks complete the bitch's soul
Lies raped in demonic lust

Her stomach bursts the casket breaks
The seed has taken form
A writhing shape of twisted flesh
The Devil's child is thrown

Hungry for the smell of Death
He rules forbidden evil
Vengeance with a frenzied hatred
The bastard now must die

Lost souls of the dead
Form legions that burst through Hell's Gates
Death of one sacrifice
To avenge the raped corpse from the grave
Blood of one mortal man
The fire grows stronger within
Fate of a frenzied lust
Lucifer takes my dark soul

Down to the fiery pits of Hell
(Down to the fiery pits of Hell)
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

string st[200000];
long par[200000],clr[200000];
map<string, long> mapp;
long tuniq;
vector<string> vn;
long q,a,b,c,n,m;
vector<long> g[200000];
long quer1[200000],quer2[200000];
vector<long> qus[200000];
long ans[200000];

long ps[200000];
vector<set<long> > vec[200000];

set<long>::iterator it;

void merg(set<long> &b,set<long>&a)
{
    // cout<<a.size()<<" "<<b.size()<<endl;
     if (a.size()<b.size())swap(a,b);
     set<long>:: iterator it;
     for (it=b.begin();it!=b.end();++it)
     {
        // cout<<a.size()<<endl;
    // cin.get();
     //cout<<*it;
     a.insert(*it);}
}

void mergge(long a,long b)
{
 if (vec[ps[a]].size()<vec[ps[b]].size())
 swap(ps[a],ps[b]);
 long spn=vec[ps[a]].size()-vec[ps[b]].size();
 
 for (int i=vec[ps[b]].size()-1;i+1;--i)
  merg(vec[ps[b]][i],vec[ps[a]][i+spn]);    
}

void dfs(long v)
{
     
     ps[v]=v;
            set<long> emp;//emp.insert(100500);
            
            for (int i=0;i<g[v].size();i++)
            {
                long q=g[v][i];
                dfs(q);
                mergge(v,q);
            }
            
            vec[ps[v]].push_back(emp);
            vec[ps[v]][vec[ps[v]].size()-1].insert(clr[v]);
            
            for (int i=0;i<qus[v].size();i++)
            {
                long q=qus[v][i];
                if (quer2[q]>=vec[ps[v]].size())ans[q]=0;
                else ans[q]=vec[ps[v]][vec[ps[v]].size()-quer2[q]-1].size();
            }
            
}

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>st[i]>>par[i];
    vn.push_back(st[i]);
}
sort(vn.begin(),vn.end());
tuniq=0;

for (int i=0;i<vn.size();i++)
{
 if (i==0||vn[i]!=vn[i-1])
 {
  mapp[vn[i]]=tuniq+1;
  ++tuniq;
 }   
}

for (int i=1;i<=n;i++)
{
 clr[i]=mapp[st[i]];
 if (par[i]>0)g[par[i]].push_back(i);   
}
/*
for (int i=1;i<=n;i++)
{
    cout<<clr[i]<<" ";
}
cout<<endl;
*/
cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>quer1[i]>>quer2[i];
 qus[quer1[i]].push_back(i);
}

vector<set<long> > res;

for (int i=1;i<=n;i++)
if (par[i]==0)
{
 dfs(i);
 /*for (int j=0;j<res.size();j++)
 {
     for (it=res[j].begin();it!=res[j].end();++it)
     {
         cout<<(*it)<<" ";
     }
     cout<<endl;
 }*/
 
}

for (int i=1;i<=m;i++)
{
    cout<<ans[i]<<endl;
}
cin.get();cin.get();
return 0;}