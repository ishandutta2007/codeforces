/*
No sense at all
do what you want
for I will hunt you
Untill you will be

Locked away

just so what you'll
be scred of me
Behind my power
I will hide all my fears

Right now you are punished
for absolutely nothing
And I feel so good
Because once more
I don't have to be honest

With myself
While you're locked away

Just so you'll
be scared of me
behind my power
I will hide al my fears
It is fierce and it moves slow
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000009
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,m;
string st1,st2;
map<string, string> mapp;
string st;

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>st1>>st2;
 if (st1.size()<=st2.size())
  mapp[st2]=st1;
  else mapp[st1]=st2;
}
for (int i=1;i<=n;i++)
{
 if (i>1)cout<<" ";
 cin>>st;
 if (mapp.find(st)!=mapp.end())
  cout<<mapp[st];
 else cout<<st;
}
cout<<endl;

cin.get();cin.get();
return 0;}