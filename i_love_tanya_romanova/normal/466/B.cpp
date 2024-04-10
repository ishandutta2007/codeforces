/*
My heart is redeemed, once summer defeated,
By the flowers laid to rest until it last

Fall, fall into pieces now
Collecting my emotions as I bury them 'till dawn

Falling
Fading Sun
Falling
Fading Sun

Autumn inspiring my deepest desires
To fall as flowers do from this room without a view

Fall, fall into pieces now
Collecting my emotions as I bury them 'till dawn

Falling
Fading Sun
Falling
Fading Sun
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
#define bsize 512

using namespace std;

long long ts,temp,s;
long long n,a,b;
long long bst,b1,b2;

int main(){
//freopen("optimize.in","r",stdin);
//freopen("optimize.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>a>>b;
s=n*6;

bst=2e18;

for (int i=a;i<=a+50000;i++)
{
 temp=s/i+(s%i>0);
 if (temp<b)temp=b;
 ts=temp*i;
 if (ts<bst)
 {
  bst=ts;
  b1=i;
  b2=temp;
 }
}


for (int i=b;i<=b+50000;i++)
{
 temp=s/i+(s%i>0);
 if (temp<a)temp=a;
 ts=temp*i;
 if (ts<bst)
 {
  bst=ts;
  b1=temp;
  b2=i;
 }
}

cout<<bst<<endl;
cout<<b1<<" "<<b2<<endl;

cin.get();cin.get();
return 0;}