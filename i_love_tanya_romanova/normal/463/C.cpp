/*
Do we remember why they're suffering
None of this seems real
We see their sadness, it's all madness
Darkness has descended upon us

All the nameless fears have come true
Faceless secrets revealed
All this loathing that we feel inside
It doesn't justify our deeds

Dead emotions all around us
Time of sickness begins
Never believed in tomorrow since day one
We were walking dead

All the nameless fears have come true
Faceless secrets revealed
All this loathing that we feel inside
It doesn't justify our deeds

Fall on evil days, remember there's no way out
What is done is done
Fall on evil days when agony breaks us down
We murdered love

Pathetic lives, too sick to cure
There is no medication
Fall on evil days, we are walking evil ways
Hand in hand towards hell

Fall on evil days, remember there's no way out
What is done is done
Fall on evil days when agony breaks us down
We murdered love
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
#define rmost agasdgasdg

using namespace std;

pair<long long,long long> bst1,bst2;
long long bv1,bv2,n,ar[2100][2100],s1[10000],s2[10000];
long long s;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=n;j++)
 {
     cin>>ar[i][j];
     s1[i+j]+=ar[i][j];
     s2[i-j+2000]+=ar[i][j];
 }
}

bst1=make_pair(-1,-1);
bst2=make_pair(-1,-1);
bv1=bv2=-1;

for (int i=1;i<=n;i++)
{
 for (int j=1;j<=n;j++)
 {
  s=s1[i+j]+s2[i-j+2000]-ar[i][j];
  if (i%2==j%2)
  {
   if (s>bv1){bv1=s;bst1=make_pair(i,j);}
  }
  else
  {
   if (s>bv2){bv2=s;bst2=make_pair(i,j);}
  }
 }    
}

cout<<bv1+bv2<<endl;
cout<<bst1.first<<" "<<bst1.second<<" "<<bst2.first<<" "<<bst2.second<<endl;

cin.get();cin.get();
return 0;}