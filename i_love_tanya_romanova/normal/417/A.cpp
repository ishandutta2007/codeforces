/*
I spit in your face preachers and leaders
Spewing false dogma
to their believers
A nation of wolves hunting the sheep
Their fangs in your flesh
So painful and deep

Despise your heros
Living a lie
Despicable heros
Fooling the blind
(Open your mind)

Puppets on strings, face on the ground
Nothing more than a shallow farce
Consume the young thoughtless ones
Eat their brain, leave them blind
And then destroy
Destroy

I spit in the face or your preachers and leaders
Spewing false dogma to their believers
A nation of fools, nothing but sheep
Their fangs in your flesh so painful and deep
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
#define bs 1000000009
#define bsize 256
#define nice dhhssgsggsgsgs

using namespace std;

long ans,c,d,n,m,k;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

ans=1e9;

cin>>c>>d;
cin>>n>>m;
cin>>k;
for (int i=0;i<=10000;i++)
 for (int j=0;j<=10000;j++)
 {
  if (i*n+j+k<m*n)continue;
  ans=min(ans,i*c+j*d);
 }
cout<<ans<<endl;

cin.get();cin.get();
return 0;}