/*
And may every seed you sow stretch out your mortal skin
so you dreams can grow to know the web you weave within
the healing process has begun, carving lessons on our arms
I hope you'll always look with love on the early days

reaching, reach through the healing
finding out you found your way home

got just what you wanted, didn't you?
stopped the whole fuckin' world, didn't you?
are you happy now?

tracing pathways in the sand, clutched tight to trembling whims
for the moment whole enough to know the feeling when
curiosity still calls, if only I could have grasped
the notion long enough to truly understand
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
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,ar[1<<10],ans,mx;
vector<long> v;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
ans=1e9;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int cp=2;cp<n;cp++)
{
 v.clear();
 for (int i=1;i<=n;i++)
  if (i!=cp)v.push_back(ar[i]);
//  cout<<v.size()<<endl;
 mx=0;
 for (int i=1;i<v.size();i++)
  mx=max(mx,v[i]-v[i-1]);
 ans=min(ans,mx);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}