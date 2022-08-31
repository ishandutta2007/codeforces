/*
Walking through the city, looking oh so pretty,
I've just got to find my way.
See the ladies flashing. All there legs and lashes.
I've just got to find my way.

Well you see me crawling through the bushes with it open wide.
What you seeing girl?
Can't you believe that feeling, can't you believe it,
Can't you believe your eyes?
It's the real thing girl.

Got me feeling myself and reeling around,
Got me talking but feel like walking around.
Got me feeling myself and reeling a...
Got me talking but nothing's with me...
Got me feeling myself and reeling around.
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long calc;
string st1,st2;

int main(){
//freopen("sumdist.in","r",stdin);
//freopen("sumdist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st1;
cin>>st2;
for (int i=0;i<st1.size();i++)
if (st1[i]=='1')++calc;

if (calc%2)++calc;

for (int i=0;i<st2.size();i++)
if (st2[i]=='1')--calc;
if (calc<0)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}