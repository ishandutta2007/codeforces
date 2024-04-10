/*
I'm bleeding, I'm bleeding in ways of the fire burned.
I'm crying, I'm crying in ways of the nightbird.
No more is there one to lay by my side.
I'm straying, I'm straying in nightmares all the time.

A little something I know,
A little somewhere I go,
Reminds me of you.

To blossom blue is to blossom without you.
To blossom blue...

I'm breaking, I'm breaking but I cannot bear to.
I'm staring, I'm staring but I cannot see you.
For no more are you to lay by my side...
I'm weeping, I'm weeping no more then this second time.

A little something I know,
A little somewhere I go,
Where the sweet waters flow,
Reminds me of you...

A little something I know,
A little somewhere I go,
Where the sweet waters flow,
Where the mistletoes grow,
Reminds me of you.

To blossom blue is to blossom without you.
To blossom blue is to blossom without you.
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

int n,m,k;
vector<int> towers;
vector<int> g[1<<20];
int alive[1<<20];
int bad_nei[1<<20];
int upr[1<<20];
vector<int> ans;
vector<int> todel;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;

for (int i=1;i<=k;i++)
{
    int id;
    cin>>id;
    towers.push_back(id);
}

for (int i=1;i<=m;i++)
{
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);  
}

long double l,r;

l=0;
r=1;
for (int iter=0;iter<=83;iter++)
{
    for (int i=1;i<=n;i++)
        alive[i]=1;
    for (int i=1;i<=n;i++)
        bad_nei[i]=0;
    
    long double mid=l+r;
    mid/=2;
    
    for (int i=1;i<=n;i++)
    {
        upr[i]=mid*g[i].size()+1e-13;
    }
    
    for (int i=0;i<towers.size();i++)
    {
        int id=towers[i];
        alive[id]=0;
        todel.push_back(id);
    }
    
    while (todel.size())
    {
        int id=todel.back();
        todel.pop_back();
        alive[id]=0;
        for (int i=0;i<g[id].size();i++)
        {
            int to=g[id][i];
            if (alive[to]==0)continue;
            if (bad_nei[to]==upr[to])
            {
                todel.push_back(to);
            }
            bad_nei[to]++;
        }
    }
    
    int nice=0;
    for (int i=1;i<=n;i++)
        if (alive[i])
            nice=1;
    
//  cout<<mid<<"%"<<nice<<endl;
    
    if (nice)
        r=mid;
    else
        l=mid;
}

// --- c- p

    l+=1e-12;
    r=l;
    for (int i=1;i<=n;i++)
        alive[i]=1;
    for (int i=1;i<=n;i++)
        bad_nei[i]=0;
    
    long double mid=l+r;
    mid/=2;
    
    for (int i=1;i<=n;i++)
    {
        upr[i]=mid*g[i].size()+1e-13;
    }
    
    for (int i=0;i<towers.size();i++)
    {
        int id=towers[i];
        todel.push_back(id);
        alive[id]=0;
    }
    
    while (todel.size())
    {
        int id=todel.back();
        todel.pop_back();
        alive[id]=0;
        for (int i=0;i<g[id].size();i++)
        {
            int to=g[id][i];
            if (alive[to]==0)continue;
            if (bad_nei[to]==upr[to])
            {
                todel.push_back(to);
            }
            bad_nei[to]++;
        }
    }
    
    vector<int> ans;
    for (int i=1;i<=n;i++)
        if (alive[i])
            ans.push_back(i);
    
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++)
    {
        if (i)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
    


//cin.get();cin.get();
return 0;}