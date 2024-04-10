/*
Oh God

Let me get this one flat out straight
Illuminate please, it's not too late
Since when did you become a god?
You might be right, I've been tattered and torn
Self destructing since I was born
So what's that got to do with you?

Close yet far, I've gone now
Safe and sound, I don't know how
Knuckled under, never giving up

So much fun when you can tell me I'm down
Such a sweet unchaining sound
Whisper me softly that I'm gonna die young
Before you do, take a look into the ground
It's not my funeral

If you rip my life apart in no time
I'll put it back together in 2.5
How's that for punctuality?

Since you wanna fuck me over and I know you really do
Better be aware I'm gonna fuck you too
But you should by now be schooled
In that very piece of my mind's obscurity

Close yet far, I've gone now
Safe and sound, I don't know how
Knuckled under, never giving up

So much fun when you can tell me I'm down
Such a sweet unchaining sound
Whisper me softly that I'm gonna die young
Before you do, take a look into the ground

So much fun when you can tell me I'm down
Such a sweet unchaining sound
Whisper me softly that I'm gonna die young
Before you do, take a look into the ground
It's not my funeral
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

long n,k,q,used[2000];
vector<long> vec[2000];
long cur;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=k;i++)
{
 cin>>q;
 used[q]=1;
 vec[i].push_back(q);
}
cur=1;
for (int i=1;i<=n*k;i++)
{
 if (used[i])continue;
 vec[cur].push_back(i);
 if (vec[cur].size()==n)++cur;
}
for (int i=1;i<=k;i++)
{
 for (int j=0;j<vec[i].size();j++)
 {
  if (j)cout<<" ";
  cout<<vec[i][j];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}