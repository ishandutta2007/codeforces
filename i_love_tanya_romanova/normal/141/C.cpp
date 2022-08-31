/*
Wish I was too dead to cry
My self affliction fades
Stones to throw at my creator
Masochists to which I cater

You don't need to bother
I don't need to be
I'll keep slipping farther
But once I hold on I won't let go till it bleeds

Wish I was too dead to care
If indeed I cared at all
Never had a voice to protest
So you fed me shit to digest

I wish I had a reason
My flaws are open season
For this, I gave up trying
One good turn deserves my dying

You don't need to bother
I don't need to be
I'll keep slipping farther
Once I hold on I won't let go till it bleeds

Wish I'd died instead of lived
A zombie hides my face
Shell forgotten with its memories
Diaries left with cryptic entries

And you don't need to bother
I don't need to be
I'll keep slipping farther
But once I hold on I won't let go till it bleeds

You don't need to bother
I don't need to be
I'll keep slipping farther
But once I hold on I'll never live down my deceit
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

string st;
string name;
vector<pair<long, string> > v;
vector<pair<string, long> > ans;
long n,p,er;
pair<string, long> tp;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>name>>p;
 v.push_back(make_pair(p,name));
}

sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
 if (v[i].first>i)er=1;

if (er){cout<<-1<<endl;
return 0;}

for (int i=0;i<v.size();i++)
{
 tp=make_pair(v[i].second,100000-i);
 ans.insert(ans.begin()+v[i].first,tp);
}
 
for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

cin.get();cin.get();
return 0;}