/*
Here's my mission
To seek you out
You're up for grabs, honey
Breathe in, don't make a sound

Get up
Get high off the ground
Give it up
Not fooling around
Breaking it up
You can't be here and be shy
Raising it up
Six guns to the sky

Come in emission control
Emission control
Come in emission control
Emission control
It's good for the soul, yeah

Turn on emission
The engine comes alive
She takes to pairing mama
Like a lion ready to strike (Ready to strike)
Hey yeah

Hold it up
Take full flight and fly
Hold it up
You got to raise it on high
Reaching it up
You can't be here and be shy
Reaching it up
Six guns to the sky
Giving it up
Giving it up

Come in emission control
Emission control
Come in emission control
Emission control
It's good for the soul, it's good

Giving it up
Giving it up
Raising it up
Giving it up
Giving it up
Giving it up
Raising it up
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

int n,m;
vector<int> g[1<<19];
string st;
int lab[1<<19];
vector<long> S[501000];
vector<int> V[501000];
int timer;
int tin[1<<19],tout[1<<19];
vector<int> Ve[1<<19];
int D[1<<19];

int mdep;

void dfs(int v,int dep)
{
    mdep=max(mdep,dep);
    D[v]=dep;
    V[dep].push_back(v);
    ++timer;
    tin[v]=timer;
    Ve[dep].push_back(tin[v]);
    ++timer;
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        dfs(to,dep+1);
    }
    ++timer;
    tout[v]=timer;
    ++timer;
}

int L,R;
long long cnt[1000];

void get(int dep,int bound,int sig)
{
    if (dep>mdep)
        return;
//  cout<<dep<<" "<<bound<<" "<<sig<<" "<<endl;
    
    int les=lower_bound(Ve[dep].begin(),Ve[dep].end(),bound+1)-Ve[dep].begin();
//  cout<<"#"<<les<<endl;
    for (int i=0;i<26;i++)
            cnt[i]^=(S[dep][les]&(1<<i));
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=2;i<=n;i++)
{
    int id;
    cin>>id;
    g[id].push_back(i);
}

cin>>st;
for (int i=1;i<=n;i++)
    lab[i]=st[i-1]-'a';

dfs(1,1);

    for (int j=1;j<=mdep;j++)
    {
        S[j].resize(V[j].size()+1);
    }
    
for (int i=1;i<=mdep;i++)
{
    S[i][0]=0;
    
    for (int j=0;j<V[i].size();j++)
    {
        S[i][j+1]=S[i][j];
     
        int id=V[i][j];
        S[i][j+1]^=(1<<(lab[id]));;
    }
}
/*
for (int i=0;i<=26;i++)
    cout<<S[i][1][1]<<endl;z
*/  
for (;m;--m)
{
    int v,d;
    cin>>v>>d;
    
    //cout<<v<<"%"<<D[v]<<" "<<d<<endl;
    
    if (d<D[v])
    {
        puts("Yes");
        continue;
    }
    
    L=tin[v]-1;
    R=tout[v];
    
    for (int i=0;i<=26;i++)
        cnt[i]=0;
    
    get(d,R,1);
    get(d,L,-1);
    
    int bad=0;
    for (int i=0;i<26;i++)
        if (cnt[i])
            ++bad;
    /*
    for (int i=0;i<26;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;
    */
    if (bad>1)
        puts("No");
    else
        puts("Yes");
}

//cin.get();cin.get();
return 0;}