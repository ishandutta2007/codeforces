/*
It's time to surrender, you know we feel no fear
Inferior contender, your men will not survive
You better tell your mortals, to step aside
Or be the last man standing to watch them die

Immortal, forever we stand in line

Battlefield burning, arroes shadow the sky
I feel the yearning, longing to see their skin fry
Too late to beg for mercy, to step aside
This is your termination just say goodbye

Immortal, forever, we just can't die

I am immortal, I cannot die, you better run and hide
We are immortal, we rule the slaughter, and side by side we ride

Immortal, forever, we stand in line
Immortal, forever, we just can't die
Immortal, forever, we stand in line

I am immortal, I cannot die, you better run and hide
We are immortal, we rule the slaughter, and side by side we ride
We are immortal, we show no fear, you better step aside
We are immortal, we rule the slaughter, and side by side we ride
We are immortal, we show no fear, you better step aside
I am immortal, I rule the slaughter, and side by side we ride
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

using namespace std;

long n,m,a,b,ar[20000];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>a>>b;
for (int i=0;i<m;i++)
cin>>ar[i];
sort(ar,ar+m);
if (m==n)
{
 if (ar[0]==a&&ar[m-1]==b)
 cout<<"Correct"<<endl;
 else cout<<"Incorrect"<<endl;
}
else if (m==n-1)
{
 if (ar[0]==a&&ar[m-1]<=b)
 cout<<"Correct"<<endl;
 else if (ar[0]>=a&&ar[m-1]==b)
 cout<<"Correct"<<endl;
 else cout<<"Incorrect"<<endl;
}
else
{
 if (ar[0]>=a&&ar[m-1]<=b)
 cout<<"Correct"<<endl;
  else cout<<"Incorrect"<<endl;
}

cin.get();cin.get();
return 0;}