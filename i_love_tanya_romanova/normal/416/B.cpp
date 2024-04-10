/*
So small in my greatness
I am the one who never wanted to be
So great in my smallness
I am the one who knows he is not
Around and inside
I am everywhere
ruling my mind
I am made of power
started down below but now
going higher and higher and higher
from one to ten
'cause ten is one and...
One thousand million hearts beating under my skin
I'm the word which means every word
I'm the truth hidden behind every lie
started down below but now
going higher and higher and higher
I'm the beginning, I'm the end
I am the Alpha, I am the Omega
One thousand million hearts beating under my skin
I'm the sword which leads every sword
I'm the path which contains every path
I'm Immortal, I'm Glorious
I'm Supreme, I'm My Saviour
My Saviour...
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

long m,n,t[100000][10],ans[10][100000];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>n;
for (int i=1;i<=m;i++)
for (int j=1;j<=n;j++)
cin>>t[i][j];
//t[i][j]=1;

for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
 {
  ans[i][j]=max(ans[i-1][j],ans[i][j-1])+t[j][i];
 }
}
for (int i=1;i<=m;i++)
{
 if (i-1)cout<<" ";
 cout<<ans[n][i];
 //cin.get();
}
cout<<endl;

cin.get();cin.get();
return 0;}