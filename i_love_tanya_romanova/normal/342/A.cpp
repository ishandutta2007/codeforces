/*
Born to push you around
Better just stay down
You pull away,
He hits the flesh,
You hit the ground

Mouth's so full of lies
Tend to black your eyes
Just keep them closed,
Keep praying,
Just keep waiting

[Chorus:]
Waiting for the one
The day that never comes
When you stand up and feel the warmth
But the sunshine never comes
No, the sunshine never comes

Push you cross that line
Just stay down this time
Hide in yourself,
Crawl in yourself,
You'll have your time

God, I'll make them pay
Take it back one day
I'll end this day,
I'll splatter color on this grey

[Chorus]

Love is a four letter word
And never spoken here
Love is a four letter word
Here in this prison
I suffer this no longer
I put an end to...
This I swear!
This I swear!
The sun will shine
This I swear!
This I swear!
This I swear!
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
#include <memory.h>

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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,deg[100],q,p,fl;
vector<long> vec;
vector<vector<long> > ans;

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>q;deg[q]++;}

for (int i=1;i<=n/3;i++)
{
    p=1;
    vec.clear();
    while (deg[p]==0)++p;
    vec.push_back(p);
    --deg[p];
    ++p;
    while ((deg[p]<=0&&p<=7)||p%vec[0]){++p;}
    vec.push_back(p);--deg[p];
    ++p;
    while ((deg[p]<=0&&p<=7)||p%vec[1])++p;
    vec.push_back(p);--deg[p];
    if (vec[2]>7)
    fl=1;
    ans.push_back(vec);
}
if (fl)cout<<-1<<endl;
else for (int i=0;i<n/3;i++)
{
     cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
 }
cin.get();cin.get();
return 0;}