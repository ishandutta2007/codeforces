/*
Histories are held within your heart, so let it go
Open all the doors around your eyes and let us know
Certain keys are held within your hand, so let it show

Bring us closer to the flame, bring us closer to the fire
Where's the spark within your eye? Where's the spark?

Thunder in your ears until you can't hear this at all
Rivers flowing tears until your destinies dissolve
Drifting through the years until a voice receives your call

Bring us closer to the fire, bring us closer to the flame
The end and beginning are the same, it's all the same

Mysteries are kept within your heart, so let it show
Open all the doors around your eyes and let us know
Certain keys were held until they must have let you go

Bring us closer to the flame, bring us closer to the fire
This world can't take us any higher
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
#define right adsgasgadsg

using namespace std;

string st;
long s;
long res;

long pw(long a,long b)
{
 long r=1;
 for (int i=1;i<=b;i++)
  r=r*a;
 return r;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
 {s=s*10+st[i]-48;
 s%=4;}
 
res=pw(1,s)+pw(2,s)+pw(3,s)+pw(4,s);
cout<<res%5<<endl;

cin.get();cin.get();
return 0;}