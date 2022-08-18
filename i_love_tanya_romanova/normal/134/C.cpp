/*
When the night closes in
And the dark shadows fall
That's where it starts again
Evil making its call

To someone who sits unaware
Could it be you, I'd beware
There's footsteps behind you
You're at the scene of its lair

Imagination burns
All hell let loose, all hell let loose
Try to shake the image from your mind
All hell let loose, all hell let loose
Imagination burns
All hell let loose, all hell let loose

A flash of light begins a thunder in the sky
Thoughts of terror that will come to you and I
But don't give in with, try with all your might
Won't give up without a fight

When you wake in the morning
You should be alright
But evil awaits you
To take you back into the night

Imagination burns
All hell let loose, all hell let loose
Try to shake the image from your mind
All hell let loose, all hell let loose

All hell let loose, all hell let loose
All hell let loose, all hell let loose
All hell let loose, hell let loose
Hell let loose

I'm coming to get you
Ha, ha, ha, ha, ha
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

int n,k,deg[1<<20];
set<pair<int, int> > S,S1;
set<pair<int,int> > ::iterator it;
vector<pair<int, int> > ans;
int er;

void add_edge(int a,int b)
{
    ans.push_back(make_pair(a,b));
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>deg[i];
    S.insert(make_pair(deg[i],i));
}

for (int iter=1;iter<=n;iter++)
{
    if (er)
        break;
    
    it=S.end();
    --it;
    int qv=(*it).second;
    S.erase(it);
    S1.clear();
    for (int i=1;i<=deg[qv];i++)
    {
        if (S.size()==0)
        {
            er=1;
            break;
        }
        
        it=S.end();
        --it;
        int tv=(*it).second;
        if (deg[tv]==0)
        {
            er=1;
            break;
        }
        add_edge(qv,tv);
        S.erase(it);
        deg[tv]--;
        S1.insert(make_pair(deg[tv],tv));
    }
    for (it=S1.begin();it!=S1.end();it++)
    {
        S.insert(*it);
    }
}

if (er)
{
    cout<<"No"<<endl;
}
else
{
    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
//cin.get();cin.get();
return 0;}