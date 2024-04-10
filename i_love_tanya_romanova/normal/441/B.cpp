/*
Two hearts that shouldn't talk to each other, become close
In a town much like a prison cell
People speak our names on the street in hushed tones
Of the stories they'd tell, if anyone would listen

You come from a town where, people don't bother saying hello
Unless somebody's born or dies
And I come from a place where they drag your hopes through the mud
Because their own dreams are all dying

And when we walk down the street
The wind sings our name in rebel songs
The sounds of the night should make us anxious
But it's much too late when the fear is gone

I will meet you in the next life, I promise you
Where we can be together, I promise you
I will wait till then in heaven, I promise you
I promise, I promise

There's so many fighting to get past the pearly gates
But nobody ever wants to die or get saved
Their intentions aren't that good and I can smell the asphalt
That's their personal road to hell being paved

And when we walk down the street
The wind sings our names in rebel songs
And it's much too late when the fear is gone

I will meet you in the next life, I promise you
Where we can be together, I promise you
I will wait till then in heaven, I promise you
I promise, I promise

I will meet you in the next life, I promise you
Where we can be together, I promise you
I will wait till then in heaven, I promise you
I promise, I promise
*/

#pragma comment(linker, "/STACK:16777216")
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

long n,m,a,b,rem[10000],ta,tb,ans,q;
vector<pair<long, long> > v;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 v.push_back(make_pair(a,-b));
}
for (int i=1;i<=3005;i++)
 rem[i]=m;
 
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 ta=v[i].first;
 tb=-v[i].second;
 q=min(rem[ta],tb);
 rem[ta]-=q;
 tb-=q;
 ans+=q;
 q=min(rem[ta+1],tb);
 rem[ta+1]-=q;
 tb-=q;
 ans+=q;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}