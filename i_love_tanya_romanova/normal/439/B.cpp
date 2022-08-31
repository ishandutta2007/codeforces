/*
Night falls, silence takes a grip. Guilt I retrieved, a burning will to die.
I need this to be over before I am bleeding dry.
Somewhere along the highway these tracks must end.
I pass a crowd on my way to the house on the hill.
Dead man with pitchfork arms tells me all that he knows.
Leave me here for the crows.
In the Fall she came back, and with her the birds.
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
#define bsize 256

using namespace std;

long long n,x,c[200000],ans;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>x;
for (int i=0;i<n;i++)
 cin>>c[i];

sort(c,c+n);
for (int i=0;i<n;i++)
{
 ans+=c[i]*x;
 if (x>1)--x;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}