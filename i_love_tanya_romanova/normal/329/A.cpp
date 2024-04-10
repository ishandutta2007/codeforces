/*
Shadows may hide you but also may be your grave
You're running today maybe tomorrow you'll be saved
You pray for daylight to save you for a while
You wonder if your children will face the killer's smile

Dead men - tell no tales
In Gangland - murders up for sale
Dead men - tell no tales
In Gangland - where jail birds die

Face at the window leers into your own
But it's only your reflection still you tremble in your bones
How long can you hide? How long 'till they come?
A rat in a trap but you've got to survive

Once you were glad to be free for a while
The air tasted good and the world was your friend
Then came the day when the hard times began
Now you're alone but alive for how long?

Dead men - tell no tales
In Gangland - murders up for sale
Dead men - tell no tales
In Gangland - where jail birds die

A knife at your throat another body on the pile
A contract to keep and it's service with a smile
Murder for vengeance or murder for gain
Death on the streets or a blacked out jail

Dead men - tell no tales
In Gangland - murders up for sale
Dead men - tell no tales
In Gangland - where jail birds die

In Gangland you tell no tales
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
#define lr asgasgash

#define  INF 100000000
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long fl;
char ar[200][200];
long v[200],g[200],n;
vector<pair<long, long> > ans;
long ci,cj;

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
v[i]=g[i]=-1;

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
    cin>>ar[i][j];
    if (ar[i][j]=='.'){v[i]=j;g[j]=i;}
}

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
 if (v[i]==-1&&g[j]==-1)
  fl=1;
}
for (int i=1;i<=n;i++){
if (v[i]>0)ci++;
 if (g[i]>0)cj++;
}
if (fl){cout<<-1<<endl;}
else
if (ci==n)
{
// cout<<n<<endl;
 for (int i=1;i<=n;i++)
 cout<<i<<" "<<v[i]<<endl;
}
else if (cj==n)
{
// cout<<n<<endl;
 for (int i=1;i<=n;i++)
 cout<<g[i]<<" "<<i<<endl;
}
else
{
    for (int i=1;i<=n;i++)
    if (v[i]>0)ans.push_back(make_pair(i,v[i]));
    for (int i=1;i<=n;i++)
    if (g[i]>0)ans.push_back(make_pair(g[i],i));
   // cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
    
}
cin.get();cin.get();
return 0;}