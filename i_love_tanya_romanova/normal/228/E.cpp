/*
Valley of dry Bones
Bless the Land
Arise come together Bone to Bone
Fusion of Flesh to Bone
Sand becomes the Blood of Man
Do it because I say you will
Repent to thee or turn to Dust
Just like the Sand
There'll be no rest
Valley of Dry Bones
Valley of Dry Bones
Bless the Land
Arise come together Bone to Bone
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

int n,m,a,b,val;
int er;

vector<int> ans;
vector<pair<int, int> > g[1<<20];
vector<int> v[10];
int used[1<<20];

void dfs(int V,int cl)
{
    used[V]=cl;
//  cout<<V<<" "<<cl<<endl;
    v[cl].push_back(V);
    for (int i=0;i<g[V].size();i++)
    {
        int to=g[V][i].first;
        int d=g[V][i].second;
        if (d==0)
            d=cl;
        else d=3-cl;
        if (used[to])
        {
            if (d!=used[to])
                er=1;
            continue;
        }
        dfs(to,d);
    }
}

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b>>val;
    val^=1;
    g[a].push_back(make_pair(b,val));
    g[b].push_back(make_pair(a,val));
}

for (int i=1;i<=n;i++)
{
    if (used[i])continue;
    v[1].clear();
    v[2].clear();
    dfs(i,1);
    if (v[1].size()>v[2].size())
    swap(v[1],v[2]);
    for (int j=0;j<v[1].size();j++)
        ans.push_back(v[1][j]);
}

if (er)cout<<"Impossible"<<endl;
else
{
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++)
    {
        if (i)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}

//cin.get();cin.get();
return 0;}