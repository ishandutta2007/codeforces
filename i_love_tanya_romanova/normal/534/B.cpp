/*
Can't remember how I got
From here to there
Isn't any reason
Plain and simple
How I can't recall anymore
Would be misleading
Lead me on

Hell and Fire burning higher
Now I can see the ever after
Clock is moving only
While I see you down here me in laughter
Never more

Clutching to a bundle in the night
Nobody knows
Leaping dogs of winter on the fight
And everyone goes

Clutching to a bundle in the night
Nobody knows
Those leaping dogs of winter on the fight
And everyone goes
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
#define bsize 256

using namespace std;

long long v1,v2,t,d,ans,lwr,upr;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>v1>>v2;
cin>>t>>d;
for (int i=0;i<t;i++)
{
 ans+=v1;
 lwr=v2-(t-i-2)*d;
 upr=v2+(t-i-2)*d;
 upr=min(upr,v1+d);
 lwr=min(lwr,v1-d);
 v1=upr; 
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}