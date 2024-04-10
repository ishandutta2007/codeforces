/*
Now my monster is awake
Had no tears for my mistakes
Still I know I have a lot to learn

I can see it through your eyes
All your demons in disguise
I'll protect myself on garden heart

Won't be a fool no more
Won't fall into your trap

You control your evil side
And I do the same with mine
Just a one to lead control of me

Won't fall into your curse
I see you everywhere

Go! Black hearted soul!
Won't you fly all away from tonight?
Find your way through the rainbow of darkness
Go on to light!

Won't you go? Black hearted soul?
You will fly all away from our dream
Find your way through the rainbow of darkness
Go on to light!
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

int n,ar[1<<20];
vector<int> values;
map<int, int> mapp;
int cnt;
long long l,r;
vector<pair<int, pair<int, int> > > quer[1<<20];
vector<int> ent[1<<20];
int ans[1<<20];
int t[1<<20];

int sum(int r)
{
    int res=0;
    for (;r>=0;r=(r&(r+1))-1)
        res+=t[r];
    return res; 
}

void inc(int i, int val)
{
    for (;i<=n;i=(i|(i+1)))
        t[i]+=val;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
//  ar[i]=n-i;
    values.push_back(ar[i]);
}

sort(values.begin(),values.end());
//reverse(values.begin(),values.end());

for (int i=0;i<values.size();i++)
{
    if (i==0||values[i]!=values[i-1])
    {
        ++cnt;
        mapp[values[i]]=cnt;
    }   
}

for (int i=1;i<=n;i++)
ar[i]=mapp[ar[i]];

for (int i=1;i<=n;i++)
 ent[ar[i]].push_back(i);
 
for (int k=1;k<n;k++)
{
    for (int i=1;i<=n;i++)
    {
        l=1ll*k*(i-1)+2;
        r=1ll*k*i+1;
        if (r>n)
            r=n;
        if (l>n)
            break;
        quer[ar[i]].push_back(make_pair(r,make_pair(k,1)));
        quer[ar[i]].push_back(make_pair(l-1,make_pair(k,-1)));
        ++cnt;
    }
}

//cout<<cnt<<endl;

for (int i=1;i<=n;i++)
{
    for (int j=0;j<quer[i].size();j++)
    {
        int brd=quer[i][j].first;
        int id=quer[i][j].second.first;
        int sig=quer[i][j].second.second;
        int temp=sum(brd);
        if (sig==1)
            ans[id]+=temp;
        else
            ans[id]-=temp;
    }
    for (int j=0;j<ent[i].size();j++)
    {
        int ps=ent[i][j];
        inc(ps,1);
    }
}

for (int i=1;i<n;i++)
{
    if (i>1)
        cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}