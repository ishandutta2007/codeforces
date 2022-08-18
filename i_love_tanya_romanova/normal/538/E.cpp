/*
An eagle breaks the silence
And overflies the field
My eyes will try to follow
Till it vanishes away

Like candles in the darkness
We fight against the wind
Devotion to your idols
Soon will overthrow the king

Out of order
Taming borders
Tearing down the fences
On and on and after all
The century has gone
Racism jumble
Turbulence
My eyes believe we have gone to the end

Ordinary Earth
Sailing through the space

Population alienation
Losing all affection
Calling on to heaven's hope
To watch for my protection
Out of luck
Potential stuck
Remote controlled
By the T.V. again

Carries human souls
Lead us the journey of our fate
So come millennium sun
Won't you show us the way
Future's begun
So words from my mouth come
Whispering for your return

Pictures a sunset on the lake
Mirrors of crystal your portrait
Walking on this field while I wait

So come millennium sun
Won't you show us the way
Future's begun
So words come from my mouth
Whispering for your return
Show us the future's began
Burning millennium sun
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
#define move asdfasdf

using namespace std;

long n,a,b;
vector<int> g[300000];
int leaves[300000];
int dp[300000];

void trace_leaves(int v)
{
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        trace_leaves(to);
        leaves[v]+=leaves[to];
    }
    if (g[v].size()==0)
        leaves[v]++;
}

void solve1(int v,int cur)
{
    if (g[v].size()==0)
    {
        dp[v]=1;
        return;
    }
    
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        solve1(to,3-cur);
    }
    if (cur==1)
    {
        for (int i=0;i<g[v].size();i++)
        {
            int to=g[v][i];
            dp[v]=max(dp[v],dp[to]+(leaves[v]-leaves[to]));
        }
    }
    if (cur==2)
    {
        int l,r;
        l=1;
        r=leaves[v];
        while (l<r)
        {
            int mid=l+r+1;
            mid/=2;
            long long cnt=0;
            for (int i=0;i<g[v].size();i++)
            {
                int to=g[v][i];
                cnt+=dp[to]-1;
            }
            if (cnt>=mid-1)
                l=mid;
            else r=mid-1;
        }
        dp[v]=l;
    }
}

void solve2(int v,int cur)
{
    if (g[v].size()==0)
    {
        dp[v]=1;
        return;
    }
    
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        solve2(to,3-cur);
    }
    if (cur==2)
    {
        dp[v]=1e9;
        for (int i=0;i<g[v].size();i++)
        {
            int to=g[v][i];
            dp[v]=min(dp[v],dp[to]);
        }
    }
//  cout<<"^"<<v<<" "<<cur<<" "<<leaves[v]<<endl;
    
    if (cur==1)
    {
        int l,r;
        l=1;
        r=leaves[v];
        while (l<r)
        {
            int mid=l+r;
            mid/=2;
            long long cnt=0;
            for (int i=0;i<g[v].size();i++)
            {
                int to=g[v][i];
                cnt+=leaves[to]-dp[to];
            }
            if (cnt>=leaves[v]-mid)
                r=mid;
            else l=mid+1;
//          cout<<v<<"  "<<l<<" "<<r<<" "<<cnt<<" "<<mid<<endl;
        }
        dp[v]=l;
    }
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
}

trace_leaves(1);

solve1(1,1);
cout<<dp[1]<<" ";

for (int i=1;i<=n;i++)
 dp[i]=0;
 
 solve2(1,1);
cout<<dp[1]<<endl;
/*
for (int i=1;i<=n;i++)
 cout<<dp[i]<<"  ";
cout<<endl;
*/
cin.get();cin.get();
return 0;}