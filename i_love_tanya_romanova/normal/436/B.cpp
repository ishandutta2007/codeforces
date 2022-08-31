/*
And it feels right this time
On his crash course with the big time
Pay no mind to the distant thunder
New day filled his head with wonder, boy

Says it feel right this time
Turned around and found the light lime
"Good day to be alive.
It's a good day to be alive", he said

Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way
Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way, hey, yeah

Don't it feel right like this?
All the pieces fall to his wish
"Sucker for that quick reward, boy
Sucker for that quick reward", they say

Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way
Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way, hey, yeah
It's comin' your way, it's comin' your way, yeah, yeah, here it comes

Yeah, then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way

Then it comes to be, yeah, yeah
Then it comes to be, yeah, yeah
Then it comes to be, yeah, yeah
Then it comes to be, yeah

Then it comes to be, yeah
Then it comes to be, yeah
Then it comes to be, yeah, yeah
Then it comes to be, yeah
*/
 
#pragma comment(linker, "/STACK:16777216")
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

string st;
char ar[2100][2100];
long n,m,k,calc;
vector<long> ans;

bool check(long a,long b,char c)
{
     swap(a,b);
     if (a<1||a>n)return false;
     if (b<1||b>m)return false;
     if (ar[a][b]!=c)return false;
     return true;
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=m;j++)
 {
  ar[i][j]=st[j-1];
 }
}

for (int start=1;start<=m;start++)
{
 calc=0;
 for (int j=2;j<=n;j++)
 {
  if (check(start,1,'D'))++calc;
  if (check(start,j*2-1,'U'))++calc;
  if (check(start-j+1,j,'R'))++calc;
  if (check(start+j-1,j,'L'))calc++;
 }
 ans.push_back(calc);
}
for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}