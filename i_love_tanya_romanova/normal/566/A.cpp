/*
Demons haunt my every waking hour
Making life into a living hell
Need to keep it down, I need to end it
Searching for the one thing that can help
Demoneater's there within my reaches
To calm the storm that rages in my head

Demoneater
Demoneater
Demoneater
Demoneater
Demoneater
Demoneater
Demoneater
Demoneater
Demoneater

Walk the streets and all I see are victims
And soon I must give in to all the rage
To kill, destroy and fuckin' rip to pieces
My anger grows and soon it is too late
Flashing pain is tearing at my inside
My soul is sick and all I feel is hate

Demoneater
Demoneater
Demoneater
Demoneater
Demoneater
Demoneater
Demoneater
Demoneater
Demoneater

Demons haunt my every waking hour
Making life into a living hell
Need to keep it down, I need to end it
Searching for the one thing that can help
To calm the storm that rages in my head
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
#define bs 1000000007
#define bsize 512
#define maxlen (1<<20)
#define alphabet 256

using namespace std;

string st;
int n;
int vert;
vector<int> g1[1<<20],g2[1<<20];
long long ans;
int match[1<<19];
int ptr[1<<20];
int V;
int dep[1<<20];
int have[1<<20][27];

int add_vertex()
{
    ++V;
    return V;
}

int get_move(int v,int c)
{
    if (have[v][c-'a']==0)
    {
        have[v][c-'a']=add_vertex();
        dep[have[v][c-'a']]=dep[v]+1;
    }
    return have[v][c-'a'];
}

void solve(int v)
{
    for (int i=0;i<26;i++)
    {
        if (have[v][i]==0)
            continue;
        solve(have[v][i]);
        int to=have[v][i];
        for (int j=ptr[to];j<g1[to].size();j++)
        {
            g1[v].push_back(g1[to][j]);
        }
        for (int j=ptr[to];j<g2[to].size();j++)
        {
            g2[v].push_back(g2[to][j]);
        }
    }
    for (;ptr[v]<g1[v].size()&&ptr[v]<g2[v].size();ptr[v]++)
    {
        match[g1[v][ptr[v]]]=g2[v][ptr[v]];
        ans+=dep[v];
    }
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

V=1;

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>st;
    vert=1;
    for (int j=0;j<st.size();j++)
    {
        int to=get_move(vert,st[j]);
        vert=to;
    }
    g1[vert].push_back(i);
}

for (int i=1;i<=n;i++)
{
    cin>>st;
    vert=1;
    for (int j=0;j<st.size();j++)
    {
        int to=get_move(vert,st[j]);
        vert=to;
    }
    g2[vert].push_back(i);
}

solve(1);

cout<<ans<<endl;
for (int i=1;i<=n;i++)
{
    cout<<i<<" "<<match[i]<<endl;
}

//cin.get();cin.get();
return 0;}