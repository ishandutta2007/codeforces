/*
Crucible heats up
Arsening, mercury
And acid concoct
Hermetic theory
Hydrogen vapours
Exclusion principle
It's never over
For ever practical

And I try
Throughout time
Any rite
For the sign

Light rebounds
Pure neon
I surround
All am I, I am all
Fluorescent light
Pellucid mineral
Essential dogma
Excludes the logical
Immobile centre
One, two, three for nothing
Projection ponder
Under a raven's wing
Catalyst fusion
Inner combustion
A transmutation
For I am all
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

string st;
string res;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
 if (st[i]!='/'||res.size()==0||res[res.size()-1]!='/')res+=st[i];
 
 if (res[res.size()-1]=='/'&&res.size()>1)res.erase(res.end()-1);
 cout<<res<<endl;
cin.get();cin.get();
return 0;}