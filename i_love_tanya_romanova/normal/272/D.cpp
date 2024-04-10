/*
Adventure seeker on an empty street,
Just an alley creeper, light on his feet
A young fighter screaming, with no time for doubt
With the pain and anger can't see a way out,
It ain't much I'm asking, I heard him say,
Gotta find me a future move out of my way,
I want it all, I want it all, I want it all, and I want it now,
I want it all, I want it all, I want it all, and I want it now,

Listen all you people, come gather round
I gotta get me a game plan, gotta shake you to the ground
Just give me what I know is mine,
People do you hear me, just give me the sign,
It ain't much I'm asking, if you want the truth
Here's to the future for the dreams of youth,
I want it all, I want it all, I want it all, and I want it now,
I want it all, I want it all, I want it all, and I want it now,

I'm a man with a one track mind,
So much to do in one life time (people do you hear me)
Not a man for compromise and where's and why's and living lies
So I'm living it all, yes I'm living it all,
And I'm giving it all, and I'm giving it all,
It ain't much I'm asking, if you want the truth,
Here's to the future, hear the cry of youth,
I want it all, I want it all, I want it all, and I want it now,
I want it all, I want it all, I want it all, and I want it now,
[etc.]
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
 
#define  INF 100000000
#define eps 1e-9
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
//#define SIZE 60
using namespace std;

long long mn[200000],l,r;
long long t;
pair<long long, long long> p;
vector<pair<long long, long long> > v;
long long db,m,n;

long long calc(long long n,long long db)
{
     long long r=1;
     
     for (int i=1;i<=n;i++)
     mn[i]=i;
     
     for (int i=1;i<=n;i++)
     while (db>0&&(mn[i]%2==0))
     {
           db--;
           mn[i]/=2;
     }
     for (int i=1;i<=n;i++)
     r=r*mn[i]%m;
     return r;

}

int main(){
//freopen("elevator.in","r",stdin);
//freopen("elevator.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
    cin>>t;
    p=make_pair(t,i+1);
    v.push_back(p);
}
for (int i=0;i<n;i++)
{
    cin>>t;
    p=make_pair(t,i+1);
    v.push_back(p);
}
sort(v.begin(),v.end());

cin>>m;

l=1;
db=0;
r=1;
/*for (int i=0;i<v.size();i++)
cout<<v[i].first<<"  "<<v[i].second<<endl;
*/

for (int i=1;i<v.size();i++)
{
    //cout<<i<<endl;
    
    if (v[i].first!=v[i-1].first)
    {
     r=r*calc(l,db)%m;
     l=1;
     db=0;
    }
    else
    {
        ++l;
        if (v[i].second==v[i-1].second)++db;
    }
    
}
    r=r*calc(l,db)%m;

cout<<r<<endl;

cin.get();cin.get();
return 0;}