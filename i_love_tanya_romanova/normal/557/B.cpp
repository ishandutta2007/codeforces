/*
Suck it up, it's a new sensation
He's a 21st century man
Hooked on into the new vibration
You can tell by shaking his hand
Feeling his head throb, he lights up a flash mob

Hey damnation, watch him go now, a better battle plan

Hey mutation, techno freak how, 21st century man
Hey damnation, in your face, he does the best I can
Hey mutation, outer space for the 21st century man

Suck it up as the worlds collide
He's a 21st century man
Living large than he's cast aside
There's got to be a better plan
Preparing for the next war, iPhone in his hand

Feeling his heart jump, turn up the heat pump

All the colors turn to gray
The innocence has gone away
Too much info here to stay
21st century man

Suck it up, and the masturbation
Said the 21st century man
I'm hooked on into a goodbye nation
You can tell by his futile hands
He's heading down the fast road
Limited attention span
Feeling his soul burn
Never did quite learn
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
#define bsize 512

using namespace std;

int n;
double w,ans,upr;
int a[1<<20];

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>w;
for (int i=0;i<n*2;i++)
    cin>>a[i];
sort(a,a+2*n);

upr=a[0];
upr=min(upr,a[n]*0.5);
upr=min(upr,w*1.0/(3*n));
ans=upr*3*n;
cout.precision(10);
cout<<fixed<<ans<<endl;

//cin.get();cin.get();
return 0;}