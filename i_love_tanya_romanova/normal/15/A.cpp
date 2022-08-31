/*
Dreams close the reality of truth
An endless sleep, an immortal life
Reality banned to the past
Fixation of another world

Floating on glass clouds, I can fly
I feel free, feelings of life are distant
A dream captured in the next dream
The dead end of subconsciousness extends, extends

Into the infinity of truth, the dreams of making
Hope, wishes, love or uncertainty
Fear, hate, like, like a self developed film
Like a self developed film

But who will show you the way
Your mind playing on tricks on you
Everything over when you awaken
Or is it an awakening in another dream
Dreams of confusion, dreams of confusion

Dreams close the reality of truth
An endless sleep, an immortal life
Reality banned to the past
Fixation of another world

Floating on glass clouds, I can fly
I feel free, feelings of life are distant
A dream captured in the next dream
The dead end of subconsciousness extends

Into the infinity of truth, the dreams of making
Hope, wishes, love or uncertainty
Fear, hate, like, like a self developed film
Like a self developed film

But who will show you the way
Your mind playing on tricks on you
Everything over when you awaken
Or is it an awakening in another dream
Dreams of confusion, dreams of confusion
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

long n,t,x[200000],r[200000];
set<long> ans;

void check(long p)
{
 if (ans.find(p)!=ans.end())return;
 for (int i=1;i<=n;i++)
 {
  if (x[i]-r[i]<=p-t&&x[i]+r[i]>p-t)return;
  if (x[i]-r[i]<p+t&&x[i]+r[i]>=p+t)return;
  if (x[i]-r[i]>=p-t&&x[i]+r[i]<=p+t)return;
 }
 ans.insert(p);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>t;
for (int i=1;i<=n;i++)
 {cin>>x[i]>>r[i];
 x[i]*=2;
 //r[i]*=2;
 }

for (int i=1;i<=n;i++)
{
 check(x[i]-r[i]-t);
 check(x[i]+r[i]+t);
}

cout<<ans.size()<<endl;

cin.get();cin.get();
return 0;}