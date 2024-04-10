/*
Were a small crowd left to rotten, theres not many hard souls left
As the pop is growing stronger, will metal fade away

Will we be broken, will we go down?

No! Well never fall were the masters of the world
Get up lets break those chains now and party all night long
No! Well never fall were the masters of the world
Get up lets break those chains now and party all night long

As Im tweaking with my radio, theres disco everywhere
When I turn on my big TV, is hip hop what I want to see?

Have we been broken, did we go down?
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

long a[100],b[100];

long win(long at,long def)
{
 if (b[3]>at&&a[4]>def)return -1;
 if (b[4]>at&&a[3]>def)return -1;
 if (def>a[3]&&at>b[4])
  if (def>a[4]&&at>b[3])
   return 1;
 return 0;
}
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=4;i++)
 cin>>a[i]>>b[i];

if (win(a[1],b[2])==1||win(a[2],b[1])==1)cout<<"Team 1"<<endl;
else if (win(a[1],b[2])==-1&&win(a[2],b[1])==-1)cout<<"Team 2"<<endl;
else cout<<"Draw"<<endl;
cin.get();cin.get();
return 0;}