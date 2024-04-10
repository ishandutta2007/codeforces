/*
Don't care if I choke....
Sacrifice me for my sins
For my beliefs
Spit at me
Die...with me
When I'm gone
Death will come to you
Death will come...
The flames went high to lick the skin on her chin
The words she said
For those words she would die
The crowd circles around her
Praising their merciful god
Her screams got weaker
Heathen, heathen
The mass was shouting
The children that once were loving
Now their small hands were full of rocks
They found her bleeding
The dark night came creeping
Was she one of the devil's own kind?
Beyond belief
Beyond the pain
And grief
I lay low
And crawl deep
Choosing the narrow path
Fear your thoughts and let the father judge them
Walk the shining path and guide the weakling along
The crowd circles around her
Praising their merciful god
Their screams grew higher
Heathen, heathen
The mass was shouting
Hunt down the profane
And put them to the torch
Burn me on the fire
Call me liar
Shout at me
Cry for me
When I'm gone
Death will come to me
Death will come...
Burn me on the fire...
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
#define right adsgasgadsg

using namespace std;

long n,ar[1<<12];
vector<pair<long, long> > v;
vector<long> nice;

void show(vector<pair<long,long> > v)
{
 for (int i=0;i<v.size();i++)
 {
     if (i)cout<<" ";
     cout<<v[i].second;
 }
 cout<<endl;
}
long cur;


int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
for (int i=1;i<=n;i++)
 v.push_back(make_pair(ar[i],i));

sort(v.begin(),v.end());
for (int i=1;i<v.size();i++)
 if (v[i].first==v[i-1].first)
 nice.push_back(i);

if (nice.size()<2)
cout<<"NO"<<endl;
else
{
 cout<<"YES"<<endl;
 
 show(v);
 cur=nice[0];
 swap(v[cur-1],v[cur]);
 show(v);
 swap(v[cur-1],v[cur]);
 cur=nice[1];
 swap(v[cur-1],v[cur]);
 show(v);
}

cin.get();cin.get();
return 0;}