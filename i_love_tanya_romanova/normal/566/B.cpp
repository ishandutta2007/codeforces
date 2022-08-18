/*
Scream in pain as you gasp for breath
Now it's time to face your final death
Melted faces blood is on the ground
Earth and darkness utters not a sound

Flash of light fills the midnight air
Scraps of metal flying here and there
Satan laughs as he watches them bleed
World of sin to the Devils feed

No escape the end is near
Too late, die in fear
Scared now of judgment day
Final death is on its way

Minds decaying in the acid rain
Savage torment as they go insane
Mutilation of forgotten souls
Satan drags them down into his hole

Dogs of war, for your blood they lust
Radiation turns your body to dust
Watching fallout as it fills the sky
Now it's time for this planet to die
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
#define maxlen (1<<20)
#define alphabet 256

using namespace std;

int n;
int a[1<<20],b[1<<20],c[1<<20];
int sz[1<<20];
set<pair<int, int> > S;
set<pair<int, int> >::iterator it;
vector<int> ans;
vector<int> g[1<<20];
int used[1<<20];
set<int> todo;
set<int>::iterator it1;

void rev(int id)
{
    used[id]=1;
//  cout<<"@"<<id<<" "<<a[id]<<" "<<b[id]<<" "<<c[id]<<endl;
    S.erase(make_pair(sz[b[id]],b[id]));
    sz[b[id]]--;
    S.insert(make_pair(sz[b[id]],b[id]));
    S.erase(make_pair(sz[c[id]],c[id]));
    sz[c[id]]--;
    S.insert(make_pair(sz[c[id]],c[id]));
    S.erase(make_pair(sz[a[id]],a[id]));
    sz[a[id]]++;
    S.insert(make_pair(sz[a[id]],a[id]));
    todo.erase(id);
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n*4;i++)
{
    cin>>a[i]>>b[i]>>c[i];
    g[b[i]].push_back(i);
    g[c[i]].push_back(i);
    sz[b[i]]++;
    sz[c[i]]++;
    todo.insert(i);
}

for (int i=1;i<=n;i++)
    S.insert(make_pair(sz[i],i));

for (int iter=n*4;iter;--iter)
{
    it=S.end();
    --it;
    int qv=(*it).second;
    /*
    for (it=S.begin();it!=S.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<"% ";
    }
    cout<<endl;
    */
    if (sz[qv]==9)
    {
        for (int j=0;j<g[qv].size();j++)
        {
            int id=g[qv][j];
            if (used[id])
                continue;
            ans.push_back(id);
            rev(id);
            break;
        }
    }
    else
    {
        it1=todo.begin();
        int id=(*it1);
        ans.push_back(id);
        rev(id);
    }
}

cout<<"YES"<<endl;

reverse(ans.begin(),ans.end());

for (int i=0;i<ans.size();i++)
{
    if (i)  
        cout<<" ";
    cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}