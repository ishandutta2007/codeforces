/*
My soul is bleeding, I feel so small
Afraid that this will never end
Can't understand the pain in my bones
I sleep through another trance

Climb over the rainbow
From here you can see so much
I need someone to take me down
But ohh, who can you trust?

Got so many things to say but it's something I don't wanna be
Gotta get away 'cause it's time to shine, to shine, to shine
Like a fallen angel I run, I won't ever see the sun
See the circle is now complete, yet the harvest remains undone

Where hemlock grows and vermin crawl
All dreams descend with fear
Crushed by the darkness that wells inside
The beast that I hold so dear

Climb over the rainbow
From here you can see so much
I need someone to take me down
But, ohh, who can you trust?

Got so many things to say but it's something I don't wanna be
Gotta get away 'cause it's time to shine, to shine, to shine
Like a fallen angel I run, I won't ever see the sun
See the circle is now complete, yet the harvest remains undone
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000000
#define bsize 512

using namespace std;

int tests;
int n;
vector<int> g[1<<20];
int timer,tin[1<<20],tout[1<<20];
int Q,bp;
int up[1<<19][19];
int start;
int finish;
int dep[1<<20];
int root;
vector<int> shit;

void dfs(int v,int p)
{
    tin[v]=timer;
    timer++;
    up[v][0]=p;
    for (int i=1;i<19;i++)
        up[v][i]=up[up[v][i-1]][i-1];
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (to==p)
            continue;
        dep[to]=dep[v]+1;
        dfs(to,v);
    }
    tout[v]=timer;
    ++timer;
}
 
bool upper(int a,int b)
{
    return (tin[a]<=tin[b]&&tout[a]>=tout[b]);
}
 
int lca(int a,int b)
{
    if (upper(a,b))
        return a;
    if (upper(b,a))
        return b;
    for (int i=18;i>=0;--i)
        if (!upper(up[a][i],b))
            a=up[a][i];
    return up[a][0];
}
 
int get_dist(int a,int b)
{
    int q=lca(a,b);
    return dep[a]+dep[b]-dep[q]*2;
}
 
 int broken[1<<20],leaves[1<<20];
 
void solve(int v,int par)
{
    int totake=0;
    
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (to==par)
            continue;
        solve(to,v);
        if (broken[to]==0)
            leaves[v]+=leaves[to];
        if (broken[to]==0&&leaves[to]>1)
            totake=1;
    }
    if (g[v].size()==1)
        leaves[v]++;
    if (leaves[v]>2||totake==1)
    {
        shit.push_back(v);
        broken[v]=1;
    }
}

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

if (n<3)
{
    cout<<"Yes"<<endl;
    return 0;
}
root=1;
while (g[root].size()==1)
    ++root;

dfs(root,root);

solve(root,root);

// copy paste

vector<int> v=shit;
/*
for (int i=0;i<v.size();i++)
    cout<<"#"<<v[i];
cout<<endl;
*/
        int bst=1e9;
        bp=0;
        for (int i=0;i<v.size();i++)
            if (tout[v[i]]<bst)
                bst=tout[v[i]],
                bp=v[i];
        
        start=bp;

        bst=-1e9;
        bp=0;
        for (int i=0;i<v.size();i++)
            if (upper(v[i],start)==0)
            {
                if (tin[v[i]]>bst)
                {
                    bst=tin[v[i]];
                    bp=v[i];
                }   
            }
            
        if (bst<0)
        {
            bst=1e9;
            bp=0;
            for (int i=0;i<v.size();i++)
                if (tin[v[i]]<bst)
                    bst=tin[v[i]],
                    bp=v[i];
        }
        finish=bp;
        
        int er=0;
        int N=get_dist(start,finish);
        
        for (int i=0;i<v.size();i++)
        {
            int id=v[i];
            if (get_dist(start,id)+get_dist(id,finish)!=N)
                er=1;           
        }

if (er)
    cout<<"No"<<endl;
else
    cout<<"Yes"<<endl;
    
//cin.get();cin.get();
return 0;}