/*
In life you're moving forward
But sometime for the worse
Always keep a step ahead
Never in reverse
The cars are stacked against you
In everything you do
But you try to get out alive
When you don't have a clue
You always feel the tension
Breathing at your back
To be the best that you can be
To be on the attack
Kicking down the wall
And kicking your face in
Means I'm moving forward
My new life can begin

Forward march in your face
Taking back, taking place
Before you die, living fast
Take a chance, hauling ass

[Chorus:]
Never, no never, no never
Move in reverse

Here I am, I'm moving straight
Fuckin' forward, and I'm taking all
The steps to blow on right past you
I'm never gonna back down to you
And all your people who think that
You're the best, no one can
Beat you, well I've got
Some news for you, you motherfucker
There's a new man in town who isn't
Any sucker, so if you don't back
Down I'll put my bat to an
Angry motherfucker such as yourself

Now I'm going to wipe out
All those who say they're first
I'll be the first in line
My attitudes the worst
Because I am so spoiled
And never second best
I will leave you in the dust
And lay your ass to rest
So never understimate
The mind of evil thoughts
I will bring you down
Spit you out before I'm caught
Because I have to power
And the upper hand
Everybody in the way
Will know that I'm the man

Forward march in your face
Taking back, taking place
Before you die, living fast
Take a chance, hauling ass

[Repeat chorus]
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
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

long n,tp,a,b,arp[1000];
vector<pair<long, long> > g;
void dfs(long v)
{
     arp[v]=1;
     for (int i=0;i<g.size();i++)
     if (arp[i]==0&&(g[i].first>g[v].first&&g[i].first<g[v].second))dfs(i);
     for (int i=0;i<g.size();i++)
     if (arp[i]==0&&(g[i].second>g[v].first&&g[i].second<g[v].second))dfs(i);
}
int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>tp;
 if (tp==1)
 {
           cin>>a>>b;
           g.push_back(make_pair(a,b));
 }   
 else
 {
     cin>>a>>b;
     --a;--b;
     for (int i=0;i<g.size();i++)
     arp[i]=0;
     dfs(b);
     if (arp[a])cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
 }
}

cin.get();cin.get();
return 0;}