/*
When did this all start anyway?
We have all the time in the world to kill
So lets converse over my imperfections
You did it all the time even when I was standing next to you

Why should now be any different?
You already shattered my self image
With your self righteous fist of disapproval
I guess when I wasn't there, I wasn't there, period

Was I?
No

Trust is not an option with me anymore
My secrets are my secrets
I've been pushed into this state of discomfort once before
I cannot act like it doesn't bother me

My eyes strain
Clearly enough for you to understand something
You lack of compassion
Will never allow you to see
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

long n,ans;
vector<long> v[1<<10];
long q;

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>q;
 v[q].push_back(i+1);
}
ans=n;
for (int i=1;i<=3;i++)
 if (v[i].size()<ans)
  ans=v[i].size();

cout<<ans<<endl;
for (int i=1;i<=ans;i++)
{
 for (int j=0;j<3;j++)
 {
  if (j)cout<<" ";
  cout<<v[j+1][i-1];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}