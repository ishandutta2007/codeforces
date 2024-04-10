/*
Burn beacon fires, blow horns of doom
Sinister ascendancy, death's coming soon

We shall take the fire everywhere
And all our enemies shall burn, yeah
In the fire they all shall die...

And like the dragons we shall reign
Reign in fire, reign in flames
We bring the fire where we turn
Burn fire burn

Flames upon Faerun, sound battle cries
Raging fires, time to die

Fire burning everywhere, death has come
Upon Faerun, our work is done
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

long calc[200],n,s,q;

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 q/=100;
 s+=q;
 calc[q]++;
}

if (s%2>0){cout<<"NO"<<endl;return 0;}
s/=2;
if (calc[1]<2&&s%2==1)cout<<"NO"<<endl;else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}