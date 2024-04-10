/*
She nursed him there, ooh, over a night
Wasn't so sure she wanted him to stay
What to say, what to say
But soon she was down, soon he was low

At a quarter past a holy no
She had to turn around

When she couldn't hold, oh, she folded
A dissident is here
Escape is never the safest path
Oh, a dissident, a dissident is here

And to this day, she's glided on
Always home but so far away
Like a word misplaced
Nothing to say, what a waste

When she had contact with the conflict
There was meanin', but she sold him to the state
She had to turn around

When she couldn't hold, she folded
A dissident is here
Escape is never the safest path
Oh, a dissident, a dissident is here, oh

She gave him away
When she couldn't hold, no, she folded
A dissident is here
Escape is never the safest path
Oh, a dissident, a dissident is here, oh

Couldn't hold on, she couldn't hold, no, she folded
A dissident is here
Escape is never the safest place, oh
A dissident is here
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
#define free adsgasdg

using namespace std;

long n,k,bad[1<<20];
vector<long> vec[1<<20];
long cnt;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/rai06.in","r",stdin);
//freopen("C:/rai06.out","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;


for (int i=1;i<=n;i++)
{
 vec[i].push_back(6*i-4);
 vec[i].push_back(6*i-5);
 vec[i].push_back(6*i-3);
 vec[i].push_back(6*i-1);
}
cout<<vec[n].back()*k<<endl;
for (int i=1;i<=n;i++)
{
 for (int j=0;j<vec[i].size();j++)
 {
  if (j)cout<<" ";
  cout<<vec[i][j]*k;
 }
 cout<<endl;
}
cin.get();cin.get();
return 0;}