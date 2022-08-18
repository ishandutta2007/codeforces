/*
On a long and lonesome highway, east of Omaha
You can listen to the engine moanin' out it's one note song
You can think about the woman, or the girl you knew the night before
But your thoughts will soon be wandering, the way they always do
When you're riding sixteen hours and there's nothing there to do
And you don't feel much like riding, you just wish the trip was through

Here I am, on the road again
There I am, on the stage
Here I go, playing star again
There I go, turn the page

Well you walk into a restaurant all strung out from the road
And you feel the eyes upon you as you're shaking off the cold
You pretend it doesn't bother you, but you just want to explode

Most times you can't hear 'em talk, other times you can
All the same old cliche's, is it woman is it man?
You always seem outnumbered, so you don't dare make a stand

Here I am, on the road again
There I am, on the stage
Here I go, playing star again
There I go, turn the page

Out there in the spotlight you're a million miles away
Every ounce of energy, you try to give away
As the sweat pours out your body like the music that you play

Later in the evening as you lie awake in bed
With the echoes from the amplifiers ringin' in your head
You smoke the days last cigarette, remembering what she said

Here I am, on the road again
There I am, up on the stage
Here I go, playing star again
There I go, turn the page

Here I am, on the road again
There I am, on the stage yeah
Here I go, playing star again
There I go, there I go
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
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
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std; 

long usd[300000],d[300000];
double ans;
vector<long> g[300000];
long a,b,n;

void dfs(long v)
{
     usd[v]=1;
 
     for (int i=0;i<g[v].size();i++)
     {
      long q=g[v][i];
      if (usd[q])continue;
      d[q]=d[v]+1;
      dfs(q);   
     }
}

int main(){
//freopen("knight.in","r",stdin);
//freopen("knight.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs(1);

for (int i=1;i<=n;i++)
ans+=1.0/(d[i]+1);

cout.precision(8);

cout<<fixed<<ans<<endl;
cin.get();cin.get();
return 0;}