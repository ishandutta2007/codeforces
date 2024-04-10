/*
Tonight I mourn the loss of heart and soul.

The path is taken, The curse received.
Dark and barren in the winter night.
Shadows move along the tree line.

A life is cleansed in blood.
Cleansed by these guilt hands.
Purged in a hollow soul.
Scorched and punished.

At the harbor I waited.
Kept an eye on the Baltic Sea.
Across these eastern waters a country of filth and dirt.
He emerged from the forest, how did he know? I damn this forsaken land.
Still the moon is looming low.
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

long long w,m,k,ans;
vector<long long> v;
long long ps,qval;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>w>>m>>k;
w/=k;
v.push_back(9ll);
v.push_back(99ll);
v.push_back(999ll);
v.push_back(9999ll);
v.push_back(99999ll);
v.push_back(999999ll);
v.push_back(9999999ll);
v.push_back(99999999ll);
v.push_back(999999999ll);
v.push_back(9999999999ll);
v.push_back(99999999999ll);
v.push_back(999999999999ll);
v.push_back(9999999999999ll);
v.push_back(99999999999999ll);
v.push_back(999999999999999ll);
v.push_back(9999999999999999ll);
v.push_back(99999999999999999ll);
v.push_back(999999999999999999ll);

ps=0;
qval=m;
while (w>0)
{
 if (v[ps]<qval){++ps;continue;}
 if ((v[ps]-qval+1)*(ps+1)<w)
 {
 ans+=(v[ps]-qval+1);
 w-=(v[ps]-qval+1)*(ps+1);
 qval=v[ps]+1;
 ++ps;
 }
 else
 {ans+=w/(ps+1);break;}
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}