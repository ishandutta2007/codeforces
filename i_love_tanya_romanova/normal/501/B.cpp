/*
Unable to move from a point of view,
driven by reasons as old as time itself.

Symbiotic In Theory

In order for a life to be
commanded it must be owned.

Symbiotic In Theory

Gravity forces water
to flow downhill,
a will is not given.

Inferior or superior,
will is that which decides.

Gravity forces water
to flow downhill,
a will is not given.

To give and take, to be...

Symbiotic In Theory
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
#define bs 1000000007
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long tests;
string st;
set<string> names,orig;
map<string, string> mapp,endd;
string st1;
set<string> ::iterator it;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>st;
 if (names.find(st)==names.end())
 {
  names.insert(st);
  orig.insert(st);
  mapp[st]=st;
  endd[st]=st;
 }
 cin>>st1;
 if (names.find(st1)==names.end())
  names.insert(st1);
  
 mapp[st1]=mapp[st];
 endd[mapp[st]]=st1;
}

cout<<orig.size()<<endl;

for (it=orig.begin();it!=orig.end();it++)
{
 cout<<(*it)<<" "<<endd[*it]<<endl;   
}

cin.get();cin.get();
return 0;}