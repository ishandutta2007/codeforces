/*
They drag me underground
The lights are slowly fading
The world I thought I knew
I never knew at all

The dead don't make a sound
Unless you're chasing rainbows
And then they scream your name
Clawing at the gates

So pull me out
And hold me down
Let's find a way
To lose ourselves

Take me to the sun
I feel I'm chasing rainbows
And now I'm lost and all alone
Waiting for a chance to

Sink my teeth into
Another desperation
Now into your room in
Paradise!

Are we just dreaming
In the city that never sleeps?
'Cause I can't be seeing
What my eyes tell me

Am I just dreaming?
This can't be in my veins
Everything I ever knew
Will never be the same

So chew me up, and spit me out
Let's find a way to save ourselves

So pull me out
And hold me down
Let's find a way
To lose ourselves

Take me to the sun
I feel I'm chasing rainbows
And now I'm lost and all alone
Waiting for a chance to

Sink my teeth into
Another desperation
Now into your room in
Paradise!

And now I feel it.
Yeah, I feel it in my blood!

I can't fight this anymore
I've given up!
I've given up!

Take me to the sun
I feel I'm chasing rainbows
And now I'm lost and all alone
Waiting for a chance to

Sink my teeth into
Another desperation
Now into your room in

Paradise!

Take me to the sun
I feel I'm chasing rainbows
And now I'm lost and all alone
Waiting for a chance to

Sink my teeth into
Another desperation
Now into your room in
Paradise!

Yeah!
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,x[1<<20],y[1<<20],unpX[1<<20],unpY[1<<20];
int used[1<<20];
vector<int> g[1<<20];

void dfs(int v,int clr)
{
    used[v]=clr;
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (used[to])continue;
        dfs(to,3-clr);
    }
}

void add_edge(int a,int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>x[i]>>y[i];
    if (unpX[x[i]])
    {
        add_edge(unpX[x[i]],i);
        unpX[x[i]]=0;
    }
    else unpX[x[i]]=i;
    if (unpY[y[i]])
    {
        add_edge(unpY[y[i]],i);
        unpY[y[i]]=0;
    }
    else unpY[y[i]]=i;
}

for (int i=1;i<=n;i++)
{
    if (used[i]==0)
    {
        dfs(i,1);
    }
}

for (int i=1;i<=n;i++)
{
    if (used[i]==1)
     cout<<"b";
     else cout<<"r";    
}

cout<<endl;

//cin.get();cin.get();
return 0;}