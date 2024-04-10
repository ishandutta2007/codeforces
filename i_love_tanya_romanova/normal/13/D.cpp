/*
May thou carry me to the sea
Like autumn leaves, Heaven wither
Savage is the winter prevailing within
I fall for thee, sorrow entreating me
Makes me leave Heaven

Breed my night like tears of sorrow
Creep with life the days that morrow
Descend like snow

I find thy lilies there of snow
Where once I died weeping for thee
Everlasting seems the strife ascending within
Falling for thee, darkness confounding me
Makes me leave life

Breed my night with thy sorrow
Creep with life the days that morrow
Descend like snow

Breed my night with thy sorrow

Examinate this pain like snow
Driven far from my efferly loss
Enter this extended night of sorrow
Pain, flowing tears

Breed my woe
Descend with broken wings
Midwinter night inside

Merged by life
Like thousand frozen tears
Come melt the ice, May time
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
#define bsize 512

using namespace std;

struct pt{
       long x;
       long y;};
long n,m;
pt a[2000],b[2000];
long calc[1000][1000];
long ans;
long long s;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=0;i<n;i++)
 cin>>a[i].x>>a[i].y;
for (int i=0;i<m;i++)
 cin>>b[i].x>>b[i].y;
 
 for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
  {
   if (a[i].x>=a[j].x)continue;
   for (int k=0;k<m;k++)
   {
    if (b[k].x<=a[i].x||b[k].x>a[j].x)continue;
    s=1ll*(b[k].x-a[i].x)*(a[j].y-a[i].y)-1ll*(b[k].y-a[i].y)*(a[j].x-a[i].x);
    if (s<0)++calc[i][j];
   }
   calc[j][i]=-calc[i][j];
  }

for (int i=0;i<n;i++)
 for (int j=i+1;j<n;j++)
  for (int q=j+1;q<n;q++)
  if (calc[i][j]+calc[j][q]+calc[q][i]==0)++ans;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}