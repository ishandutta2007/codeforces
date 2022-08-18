/*
As human beings, we're a complex thing
Sometimes so beautiful, other times so vain
We've built an empire, the blood is on our hands
Genocide and the chains that bind
The consequence ahead

Oh, you ought to know
Oh, you ought to know

Wrote about in history as if it's all O.K.
A race of people murdered another one enslaved
Now our world crumbles, it's happening within
Open your eyes and realize
The world we're living in

Oh, you ought to know
Oh, you ought to know

If we could focus on important things
Live and let live true freedom, not everyone's the same
No more war for your god, no more war for your race
It's our world, it's what we make it
Make it a better place

Oh, you ought to know
Oh, you ought to know

We can change the world that we're living in
Live and let live true freedom
Let the reign begin
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

char ar[10][10];
long c[10000];
long ans;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=4;i++)
for (int j=1;j<=4;j++)
cin>>ar[i][j];

for (int i=1;i<=3;i++)
for (int j=1;j<=3;j++)
{
 c['.']=c['#']=0;
 for (int q=0;q<=1;q++)
 for (int w=0;w<=1;w++)
  c[ar[i+q][j+w]]++;
  if (c['.']<2||c['#']<2)
  ans=1;   
}

if (ans)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}