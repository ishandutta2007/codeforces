/*
Would you come and share
My cross, my pain, my heartbroken nature
For this burden is too heavy to bear
Too troublesome for one man to handle

Since my darkness swallowed
The last gleam of light
I've been rambling in the shadows
Hour after hour in the dark

They who never got sorrow,
Grinding grief in their hearts
Never lost a thing,
Never had a thing

They who never witnessed beauty,
That flamed even the all-encompassing night
Never lost a thing,
Never had a thing

Now these bitter tears run ceaseless,
And drown my hope far too deep
It must've been the day we parted
When I trapped this sadness in me

Since my darkness swallowed
The last gleam of light
I've been clothed in mourning,
Wearing sorrow day and night
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define bsize 256

using namespace std;

string st;
long n,m,calc[200];

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=0;i<n;i++)
 for (int j=0;j<m;j++)
 {
  cin>>st;
  calc[st[0]+st[1]-96]++;
 }

for (int i=0;i<n;i++)
{
 for (int j=0;j<m;j++)
 {
  if (j)cout<<" ";
  if (calc[2]){cout<<"11";--calc[2];continue;}
  if (calc[1]>=m-j){if (i%2)cout<<"10";else cout<<"01";
  --calc[1];continue;}
  cout<<"00";--calc[0];
 }
 cout<<endl;
}
cin.get();cin.get();
return 0;}