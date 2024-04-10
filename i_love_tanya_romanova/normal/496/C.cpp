/*
Sleep now
Fragile
Cradle my hope
Dream 'til morning
Rising again
To uphold my claims to power
Promises bind
This place to me
Peace I have found
In a vision pure and simple
Here in this world
I am the king
Dreams trouble my conscience
With thoughts of those betrayed
Prophecies certain
Bring me to conflict often
But comfort has always triumphed
Against a change

Walking again
Among these familiar faces
Hearing the same
Praises they speak
All here is well
But somehow so unnerving
In the eyes of a child
The world looks bleak
Fears grow ever bolder
Threatening disgrace
All that will be
Grows clearer with every moment
Whispers turn now to shouting for my escape

Awake

Brashly you stifled warnings
See now the fruits of failure
Ignorant liar
Did you truly think
You could stay here awhile
And avoid your fate
Crawling, grasping, searching, reaching for a path
Through all this chaos choking on the ashes
Of a life that suddenly has passed
And as the screams subside
I slowly raise my head
To watch the final ruin
And see my kingdom's end
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs1 1000000007ll
#define bs2 1000000009ll
#define P1 173
#define P2 187
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,m;
string st[1<<12];
long bad,done[1<<12];
long ans;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st[i];
}

for (int j=0;j<m;j++)
{
 bad=0;
 for (int i=2;i<=n;i++) {
  if (done[i]==0&&st[i][j]<st[i-1][j])
   bad=1;
 }
 if (bad)++ans;
 else
 for (int i=2;i<=n;i++)
  if (st[i][j]>st[i-1][j])
   done[i]=1;   
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}