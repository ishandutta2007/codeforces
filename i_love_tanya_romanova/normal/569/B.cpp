/*
A veiled horizon
A land held back
Of worlds undone
Immortal in black
An endless tomorrow
Engulfed in eclipse
Black morning's sorrow
The absurdity we live
The absurdity, with nothing left to give

And we are... cast to live undone
Until the heart is gone
And bred to fail
Cast to live undone
And setting like the sun
Where shadows burn
And we become

Into a dead sun's delight
With tears to tear
All faces alike
Of that earth that we wear
Inspired indeed
What lacks the time
As horizons decree
Such reflections lead us blind
Such reflections lead us,
And we remain behind

And we are... cast to live undone
Until the heart is gone
And bred to fail
Cast to live undone
And setting like the sun
Where shadows burn
And we become

Tearing deep into the earth
Lost and searching
The sacrifice of rebirth,
A new dawning
Circle complete in the dirt
Beyond the pain that has been endured
Where heavens litter the sky
Removed from reason
Banished from all that was mine
No solace given
Destined desire untold
The advent of existence calling me

Cast to live undone
Until the heart is gone
And bred in vain
Cast to live undone
In exile and among
Where shadows burn
And we become
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

using namespace std;

int n,ar[1<<20];
vector<int> ent[1<<20];
vector<int> F;
int used[1<<20];

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    ent[ar[i]].push_back(i);
}

for (int i=1;i<=n;i++)
    if (ent[i].size())
    {
        int id=ent[i][0];
        used[id]=1;
    }

for (int i=1;i<=n;i++)
    if (used[i]==0)
        F.push_back(i);
    
for (int i=1;i<=n;i++)
{
    if (ent[i].size())
        continue;
    int v=F.back();
    F.pop_back();
    ar[v]=i;
}

for (int i=1;i<=n;i++)
{
    if (i>1)
        cout<<" ";
    cout<<ar[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}