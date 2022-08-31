/*
Anybody out there
Anyone at all
Can you finally hear this deep in
Scratching through the wall
Came far to find me
Down the rabbit hole
Watch me smiling back while chewing on my skull

I know, won't forget
Limped away from the wreck

Is the monkey breathing
Looking kinda sick
Got a witty comment for me
Have yourself a kick
Does it make you feel good
Are you full and strong
Gonna end up in this cage and I hope your stay is long

I know, won't forget
Limped away from the wreck

We'll never know what this is
'til we take a look inside
I'm sure we'll find what came before it dies

We'll never know what this is
'til we take a look inside
I'm sure we'll find what came before

Had enough, I don't need you to stick my hide
Had enough, no more tears for me left to cry
Had enough, I don't need you to blind my eyes
Had enough, no more tears for me left to cry

I know, won't forget
Limped away from the wreck

We'll never know what this is
'til we take a look inside
I'm sure we'll find what came before it dies

We'll never know what this is
'til we take a look inside
I'm sure we'll find what came before it dies

Had enough, I don't need you to stick my hide
Had enough, no more tears for me left to cry
Had enough, I don't need you to blind my eyes
Had enough, no more tears for me left to cry
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
#define bsize 256

using namespace std;

int n,m,a,b,d1,d2,v1,v2,t1,t2,s1,s2;
int d[3050][3050];
vector<int> g[3050];
int dist[3050];
queue<int> qu;
int l1,l2;
int ans;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

ans=-1;

for (int i=1;i<=n;i++)
{
    for (int j=1;j<=n;j++)
        dist[j]=1e9;
    qu.push(i);
    dist[i]=0;
    while (qu.size())
    {
        int temp=qu.front();
        qu.pop();
        for (int j=0;j<g[temp].size();j++)
        {
            int to=g[temp][j];
            if (dist[to]>dist[temp]+1)
            {
                dist[to]=dist[temp]+1;
                qu.push(to);
            }
        }
    }
    for (int j=1;j<=n;j++)
        d[i][j]=dist[j];
}

cin>>s1>>t1>>l1;
cin>>s2>>t2>>l2;
if (d[s1][t1]<=l1&&d[s2][t2]<=l2)
    ans=max(ans,m-d[s1][t1]-d[s2][t2]);

for (int v1=1;v1<=n;v1++)
    for (int v2=1;v2<=n;v2++)
    {
        int d1=d[s1][v1]+d[v1][v2]+d[v2][t1];
        int d2=d[s2][v1]+d[v1][v2]+d[v2][t2];
        d2=min(d2,d[s2][v2]+d[v1][v2]+d[v1][t2]);
        if (d1<=l1&&d2<=l2)
        {
        //  cout<<v1<<" "<<v2<<" "<<d1<<" "<<d2<<endl;
            ans=max(ans,m-d1-d2+d[v1][v2]);
        }
    }

//if (ans<0)ans=0;

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}