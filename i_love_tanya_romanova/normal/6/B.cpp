/*
The great word of blessedness
And a feeling of ease
A cup of the well of freedom
And life we joyfully drink
Inside, all was new, but outwards
Nothing had changed

An escapade,
Then to the altar to
Evaluate all parts
Of the great mystery
But all remains
On the same spot,
No signs of a new season

In my hand is a new word,
But the word is still
Without a body
A hidden life-stream that
Swells in the deep
Will soon give the word
A 2nd face
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,m;
string zr,st[2000];
set<char> ans;

void check(long a,long b)
{
 if (a<1||a>n)return;
 if (b<0||b>=m)return;
 if (st[a][b]=='.')return;
 if (st[a][b]==zr[0])return;
 ans.insert(st[a][b]);
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>zr;
for (int i=1;i<=n;i++)
 cin>>st[i];
 
for (int i=1;i<=n;i++)
 for (int j=0;j<m;j++)
 {
  if (st[i][j]!=zr[0])continue;
  check(i-1,j);
  check(i+1,j);
  check(i,j-1);
  check(i,j+1);
 }

cout<<ans.size()<<endl;

cin.get();cin.get();
return 0;}