/*
Distant powers, outer space
Evil forces, the human race
Comets landing in your town
Heed the warning, get underground

We fight them on the sea and land
Death-ray turns your face to sand
To wipe the earth of humans clean
They are evil, short, green

Visitors came and promised peace
On human cattle now they will feast
Don't ask for mercy, they won't comply
So bolt your doors and watch the sky
To Serve Man, they landed here
Burning through the upper atmosphere
Sucking out guts with a lizard's eyes
So bolt your doors and watch the sky
Watch the sky

Push the button, set the charge
Sending our rockets to wipe out Mars
Cities burned, armies fell
Planet Earth becomes a living hell
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
//#include <memory.h>

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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long ans,n,a[20000],b[2000],res1,res2;
vector<long> g[20000];
long arp[20000];

void cl()
{
 for (int i=1;i<=n;i++)
 g[i].clear();
}

void dfs(long v)
{
 for (int i=0;i<g[v].size();i++)
 {long q=g[v][i];
 if (arp[q]==0){arp[q]=arp[v]+1;dfs(q);}}
 
}

void construct(long v,long be)
{
 for (int i=1;i<=n;i++)
 arp[i]=0;
 
 for (int i=1;i<n;i++)
 if (i!=be)
 g[a[i]].push_back(b[i]),g[b[i]].push_back(a[i]);
 
 arp[v]=1;
 dfs(v);
 for (int i=1;i<=n;i++)
 if (arp[i]==0)g[i].clear();
}

long solve(long x)
{
 for (int i=1;i<=n;i++)
 arp[i]=0;
 arp[x]=1;
 dfs(x);    
 long r=0;
 for (int i=1;i<=n;i++)
 r=max(r,arp[i]-1);
 return r;
}

int main(){
//freopen("elect.in","r",stdin);
//freopen("elect.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<n;i++)
{
    cin>>a[i]>>b[i];
}

ans=0;
for (int cp=1;cp<n;cp++)
{
    cl();
    construct(a[cp],cp);
    /*
    for (int i=1;i<=n;i++)
    for (int j=0;j<g[i].size();j++)
    cout<<i<<"%"<<g[i][j]<<" ";
    cout<<endl;
    */
    res1=res2=0;
    for (int i=1;i<=n;i++)
     res1=max(res1,solve(i));
    cl();
    construct(b[cp],cp);
    for (int i=1;i<=n;i++)
    res2=max(res2,solve(i));
//    cout<<res1<<" "<<res2<<endl;
    ans=max(ans,res1*res2);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}