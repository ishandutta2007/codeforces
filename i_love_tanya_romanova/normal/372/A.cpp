/*
On this earth - lay me down
Soil my blood - this shell will fade
Gods with eyes - i'm ready now
At the hanging tree - giver of life
Great mother heal - I will rise

(I believe in you - we all keep the flame
We are all pure flame inside)

Down spiraling outward
Revive to survive
Prey to the mystics
Prey on

Dust falls through my hands
Dreams shatter away
Burning glow turns to ash
Thrown to wind

The weave in my dreams
My strength of fates
The tunneling helix
Tongue a flame

A healing delusion
Beyond true will
A seering blue gaze
Breath my fire

What hath god wrought
Divine misthought
No senses, cold and sedate
A self-imposed
Fear-driven state
Too hurt to see
Unhidden truth
Increasing void
Worsened fate
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256
#define double long double

using namespace std;

long n,q,fu,ans;
vector<long> v;
long used[1000000];
long l,r,m,flag;

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
    v.push_back(q);
}
sort(v.begin(),v.end());
l=0;
r=n/2;
while (l<r)
{
 m=l+r+1;
 m/=2;
 flag=0;
 for (int i=0;i<m;i++)
  if (v[i]*2>v[v.size()-m+i])flag=1;
  if (flag)r=m-1;
  else l=m;
}

cout<<n-l<<endl;

cin.get();cin.get();
return 0;}