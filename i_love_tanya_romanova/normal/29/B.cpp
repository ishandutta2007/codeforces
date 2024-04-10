/*
I hold a magazine in my hand
Facing the cover - it's me
They write about my coming end
No more than twelve months for me

Tainted and fainted and lonely I picture my life
Blameless and shameless I'm leaving in awful disgrace

Another second to be
Not another second to be

All the things I just have done
Passing my mind hundred times
All the tears I have cried, all the lies I have lied
All in hope for a better life

Tainted and fainted and lonely I picture my life
Blameless and shameless I'm leaving in awful disgrace

Another second to be
Not another second to be

Not another second to be
Lonely I picture my life - no second to be
Time's running out and there's just no second to be
I'm leaving in awful disgrace - no second to be
There's not another second to be
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

long l,d,v,g,r;
double t;
double cur;

int main(){
//freopen("substr.in","r",stdin);
//freopen("substr.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cout.precision(10);
cin>>l>>d>>v>>g>>r;
t=d*1.0/v;
while (t>cur+g+r){cur+=g+r;}if (t>=cur+g)t=cur+g+r;
t+=(l-d)*1.0/v;
cout<<fixed<<t<<endl;

cin.get();cin.get();
return 0;}