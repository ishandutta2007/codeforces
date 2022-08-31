/*
Crocodile tears from industrial giants,
apologies counting for nothing
Graveyard obssessions and shallow confessions,
The game never ends in a draw.

An eternal horizon that reaches the sky
When we're standing together, we cannot ever die
And we're chasing the darkness away with our cry,
Never die, never die,
We never die.

Fragile and cold by the side of a mountain,
Big hopelessness bearing to promise,
Brothers and sisters of metal together
We'll conquer the evil as one!

An eternal horizon that reaches the sky
When we're standing together, we cannot ever die
And we're chasing the darkness away with our cry,
Never die, never die,
We never die.

An eternal horizon that reaches the sky
When we're standing together, we cannot ever die
And we're chasing the darkness away with our cry,
Never die, never die,
We never die.
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long flag;
long sz;
vector<char> ans;

int main(){
//freopen("gnu.in","r",stdin);
//freopen("gnu.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
    flag=0;
    sz=ans.size();
    if (sz>1&&ans[sz-1]==ans[sz-2]&&ans[sz-1]==st[i])
    flag=1;
    if (sz>2&&ans[sz-1]==st[i]&&ans[sz-2]==ans[sz-3])
    flag=1;
    if (flag==0)ans.push_back(st[i]);
}

for (int i=0;i<ans.size();i++)
cout<<ans[i];
cout<<endl;

cin.get();cin.get();
return 0;}