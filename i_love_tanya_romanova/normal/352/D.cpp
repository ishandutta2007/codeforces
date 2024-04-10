/*
We've lost the light another night
Kill these days and make them go away
Skulls on fire
The burning faces know iall hope is gone
Would you lie in wait or
Would you kill your brother
Would you offer out your hand
Then unleash the dagger

Black angel, white angel
Kneel down and lick from the razor
Dark angel, light angel
Come down and lay in the danger

You've lost your way among the fray
The blackest days
Are waiting up ahead
Blazing skulls
The burning children know it's all a game
Would you die in pain or
Would you feed the maelstrom
Would you offer up the necessary soul
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
#define bsize 256

using namespace std;

long n,answ;
long ar[5000];
double prob[1000][1000];

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

//cin>>n;
/*
prob[0][n]=1;

for (int i=0;i<=100;i++)
 for (int j=1;j<=100;j++)
 {
  if (i%2==0){prob[i+1][j-1]+=prob[i][j];}
  else {prob[i+1][j-1]+=prob[i][j]*0.5;prob[i+1][j+1]+=prob[i][j]*.5;   }
 }
 double 
 answ=0;
 for (int i=0;i<=100;i++)
 answ+=i*prob[i][0];
 cout<<answ<<endl;
 */
 
 cin>>n;
 for (int i=1;i<=n;i++)
 cin>>ar[i];
 for (int i=1;i<=n;i++)
  for (int j=i+1;j<=n;j++)
  if (ar[j]<ar[i])
  ++answ;
  cout.precision(9);
  if (answ==0)cout<<fixed<<0<<endl;
  else if (answ%2==0)cout<<fixed<<answ*2.0<<endl;
  else cout<<fixed<<2.0*(answ-1)+1<<endl;
cin.get();cin.get();
return 0;}