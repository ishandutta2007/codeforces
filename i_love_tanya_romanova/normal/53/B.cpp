/*
This broken wheel is coming undone
And the roads exploding
But you're keeping me strong
Rolling along with you,...

Love is a tower
And you're the key
Leading me higher
When you let me in

Keeping us close,... so close
On down the line

Sometimes I burn like a dot on the sun
With no one knowing
But you're keeping me strong
Rolling along with you

You are a tower of
Strength to me
The darkening hour
Sees light again

Ooh wah, ooh wah, you are...

Love is a tower
Of strength to me
I am the shoreline
But you're the sea

You are.
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
#include <memory.h>

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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long long h,w,bh,bw,th,tw;

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>h>>w;

bh=bw=0;

for (int t=0;t<31;t++)
{
 th=(1ll<<t);
 tw=min(th*1.25+0.001,w+0.01);   
 if (tw<th*0.8-0.001)continue;
 if (th>h)continue;
 if (th*tw>bh*bw||th*tw==bh*bw&&th>bh){bh=th;bw=tw;}
// cout<<th<<" "<<tw<<endl;
}

for (int t=0;t<31;t++)
{
 tw=(1ll<<t);
 th=min(tw*1.25+0.001,h+0.01);   
 if (th<tw*0.8-0.001)continue;
 if (tw>w)continue; 
 if (th*tw>bh*bw||th*tw==bh*bw&&th>bh){bh=th;bw=tw;}
}

cout<<bh<<" "<<bw<<endl;

cin.get();cin.get();
return 0;}