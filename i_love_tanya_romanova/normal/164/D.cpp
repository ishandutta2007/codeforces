/*
Start marchin' 
'Cause you think you shot to #1
Counting days and 
skipping your stones into the sun
Over age and under thumb
Does it weigh a ton
I'll be yours tonight,
Living the dream of a meteorite

Start jumping 'cause 
We've got something to say
Young lovers keep it pumping 
In the streets of LA

Short stroking doesn't fly
Better to go for broke
Whatchu smoking Mary Jane
And does it make you choke
Jumping the fence, riding the rails
Can you take a joke
I'll be yours today
Living the dream with a capital K

Start jumping 'cause 
We've got something to say
Young lovers keep it pumping 
In the streets of LA

Tell me now, I'll tell you how
Just show me where to send

Make time for love and your happiness
The mothers of invention are the best
We all know and struggle with some loneliness
A tender mess for everyone, I guess

Half blinded
I'm reminded how to find the stairs
Nickel and dimin' 
Think it's time 
To play some musical chairs
Dirty laundry
What a quandary
Ask her if she cares
I'll be yours and more
better than ever like never before

Start jumping 'cause 
We've got something to say
Young lovers keep it pumping 
In the streets of LA

Make time for love and your happiness
The mothers of invention are the best
We all know and struggle with some loneliness
A tender mess for everyone, I guess

Sweet talkin'
As I'm walkin' thru your part of town
Never again
Will Johnny C a Love Supreme be found
Is it ever meant to be
And is it so profound
Is it you and me 
A billion to one make history

Said yeah
Oh yeah
Said yeah
Oh yeah
Said yeah
Oh yeah
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

int atake[1<<20],used[1<<20];
int n,k;
double dist[1050][1050];
int x[1<<20],y[1<<20];
vector<int> g[1<<20];
int found;

bool dfs(int v,int k)
{
//  cout<<v<<"  ^"<<k<<endl;
    if (v==n)
    {
        if (found==0)
        for (int i=0;i<n;i++)
            atake[i]=used[i];
        found=1;
        return true;
    }
    
    // g f
    if (used[v])return dfs(v+1,k);
    int nei=0;
    
    // V1
    for (int i=0;i<g[v].size();i++)// take nei, leave this; coveres isolated Vs also
    {
        int to=g[v][i];
        used[to]++;
        if (used[to]!=1)continue;
        nei++;
        --k;
    }
    
    if (k>=0&&dfs(v+1,k))return true;
    
    // V2
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (used[to]==1)
            ++k;
        --used[to];
    }
    
    used[v]++;// take this, only if 2+ nei
    if (k>0&&nei>1&&dfs(v+1,k-1))return true;
    used[v]--;
    return 0;
}

bool check(double bound)
{
    found=0;
    for (int i=0;i<n;i++)
    {
        used[i]=0;
        g[i].clear();
    }
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (dist[i][j]>bound+1e-9)
                g[i].push_back(j),
                g[j].push_back(i);
    
    return dfs(0,k);
    
}

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;

for (int i=0;i<n;i++)
{
    cin>>x[i]>>y[i];
}

for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
        dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));

double l,r;

l=0;
r=1.2e9;
for (int iter=1;iter<=77;iter++)
{
    double mid=l+r;
    mid/=2;
    if (check(mid))
        r=mid;
    else
        l=mid;
}

//cout<<check(3)<<endl;
/*
cout<<check(l+1e-7)<<" * "<<l<<endl;

for (int i=0;i<n;i++)
    for (int j=0;j<g[i].size();j++)
        cout<<i<<"*"<<g[i][j]<<endl;
*/
check(l+1e-8);
vector<int> ans;
for (int i=0;i<n;i++)
{
    if (atake[i])ans.push_back(i+1);
}

for (int i=0;i<n;i++)
 if (ans.size()<k&&used[i]==0)
    ans.push_back(i+1);
    
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}

//cin.get();cin.get();
return 0;}