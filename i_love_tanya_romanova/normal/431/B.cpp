/*
My loneliness makes you feel insecure
My loneliness will never let you find a cure
My loneliness has no directions for me and you
My loneliness speaks no truth of what you do
Listen to what I say

Turn me in
You're going crazy and I can't stand to feel your tears over me
Turn me in
It's not a crime to feel the way that I do, again and again

My loneliness does not lead you to my core
My loneliness always tell you to ignore
My loneliness, a waste of time if there's no trust
My loneliness is turning everything to dust
Listen to what I say

Turn me in
You're going crazy and I can't stand to feel your tears over me
Turn me in
It's not a crime to feel the way that I do, again and again

No one can save us from this pain
I wish that I could stop the rain
These dark gray skies are closing in

Oh
You're going crazy and I can't stand to feel your tears over me
Turn me in
It's not a crime to feel the way that I do, again and again
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

vector<long> v;
long c[200][200],s,ans,a,b;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=5;i++)
 for (int j=1;j<=5;j++)
  cin>>c[i][j];

for (int i=1;i<=5;i++)
 v.push_back(i);

do
{
 s=0;
 for (int st=0;st<=3;st++)
 {
  for (int j=st;j+1<v.size();j+=2)
  {
   a=v[j];
   b=v[j+1];
   s+=c[a][b]+c[b][a];
  }
 }
 ans=max(ans,s);
}
while (next_permutation(v.begin(),v.end()));
cout<<ans<<endl;;

cin.get();cin.get();
return 0;}