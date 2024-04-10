/*
Forever cursed by this game, he who plays with sin
Incantations summoned up our creations

We're players cast in this tale, believe it
stranger than fiction
This justice thunders our condemnation

Falling into innocence by a shadow's kiss
He speaks what mortals dare to say, will he betray?

If you dare play the game - your descent preordained
from their fiery thrones screaming,
cursing your name
On the terror it breeds - breathing fire and greed
watch him jest as you bleed...
Screaming enter the Damnation Game

We can not keep our heads clear,
or our tongues from evil
by this sword, certain death at our own hands

To have no wants is divine - untrue!
platinum waves tainted gold, we can only watch from
the shores

Falling into innocence by a shadow's kiss
He speaks what mortals dare to say, will he betray?

If you dare play the game - your descent preordained
from their fiery thrones screaming,
cursing your name
On the terror it breeds - breathing fire and gree
watch him jest as you bleed...
Screaming enter the Damnation Game

If you dare play the game -
your descent preordained
from their fiery thrones screaming,
cursing your name
On the terror it breeds - breathing fire and greed
watch him laugh as you bleed...
Screaming enter the Damnation Game

[Chorus x2]
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long double board[10][10],l,r;

pair<long double,long double> solve(long double l1,long double r1,long double l2,long double r2)
{
    long double mn,mx;
    mn=1e50;
    mx=-1e50;
    mn=min(mn,l1*l2);
    mn=min(mn,l1*r2);
    mn=min(mn,r1*l2);
    mn=min(mn,r1*r2);
    mx=max(mx,l1*l2);
    mx=max(mx,l1*r2);
    mx=max(mx,r1*l2);
    mx=max(mx,r1*r2);
    return make_pair(mn,mx);
}

bool can(long double val)
{
    pair<long double,long double> gg1=solve(board[0][0]-val,board[0][0]+val,board[1][1]-val,board[1][1]+val);
    pair<long double,long double> gg2=solve(board[0][1]-val,board[0][1]+val,board[1][0]-val,board[1][0]+val);
    //cout<<val<<"%"<<endl;
    //cout<<gg1.first<<" "<<gg1.second<<" "<<gg2.first<<" "<<gg2.second<<endl;
    return (min(gg1.second,gg2.second)>=max(gg1.first,gg2.first)-1e-19);
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<2;i++)
    for (int j=0;j<2;j++)
     cin>>board[i][j];

l=0;
r=1e18;
for (int iter=1;iter<=441;iter++)
{
    long double mid=l+r;
    mid/=2;
    if (can(mid))r=mid;
    else l=mid;
}
cout.precision(12);
cout<<fixed<<l<<endl;
//cin.get();cin.get();
return 0;}