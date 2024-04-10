/*
An invitation to clairvoyance
It's hard to stand around and watch while they ignore us
She is dumped on
Used as an ashtray
At the expense of an organized association
I see the stones in the path we laid
It's a question of tomorrow
We like to breathe the ancient wind that we have followed
A perfect fire to burn the land
Before they knew it
The sun had falledn
Boiling the water where the hydra's crawling
The righteous go in blazing fury
And we cleanse the earth to bring it down
Bring it down
And God will watch it burn
Releasing souls
Within the wrath we wait
To be dirt again
There is a flame I lit
I upon high
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,ans[555555];
long q;
long li,ps;
vector<pair<long, long> > v;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    v.push_back(make_pair(q,i));
}
sort(v.begin(),v.end());

li=-1;

for (int i=0;i<v.size();i++)
{
 ps=v[i].second;
 ++li;
 if (li<v[i].first)li=v[i].first;
 ans[ps]=li;
}

for (int i=1;i<=n;i++)
{
    if (i-1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}