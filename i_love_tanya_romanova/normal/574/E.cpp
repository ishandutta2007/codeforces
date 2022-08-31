/*
I wasn't there when you needed me
You never let me in your life
I didn't say what bothered me
You sure said more than that
The silence that followed didn't do us any good
And it seems like you settled for me
Cause I was the best that you could get
But there wasn't enough
I know what you want and you're not the one for me

I've been leaving you since the day we met
And it feels like you have too
I remember when I met you
The day I saw your smile
And now it's time to let go
Oh, it's time to feel alive

The problems I had with you
Are the ones you have with me
Even though we're holding love
We both know we've drifted apart
I guess this is it, why bother when there's nothing left
When neither you or me are in
Growing bitter and uncomfortably numb
Losing what we had
At least we tried, but it wasn't meant to be

I've been leaving you since the day we met
And it feels like you have too
The reasons that I loved you are the ones that made me go
The reasons that I loved you, oh, I gotta let you know

I should have seen it coming
Should have known what to expect
I should have seen the signs
Should have known that it was wrong

I've been leaving you since the day that we met
And it feels like you have too
The reasons that I loved you are the ones that made me go
The reasons that I loved you, oh, I gotta let you know

I am sorry
That we got here
But I'm glad
Glad that we are done
I don't want to go back there
Cause the love I felt is gone
Cause the love I felt is gone, alright
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