/*
I - I've seen it all before
Heading north the parole
I sit here and watch it all come down
A mile away from hell
Back in a foreign land
But will tomorrow ever come

No regrets, no reason why
Release me, I'm dying

We stood side by side
Everybody's asking why
We had a dream, it ended in screams
They sold us as a question of honour

A flash of a shtogun blast lightens the dark
Dan dies in a pool of blood
A jet's coming close as gas hits my nose
All the prayers came too late

No regrets, no reason why
Release me, I'm dying

We stood side by side
Everybody's asking why
We had a dream, it ended in screams
They sold us as a question of honour

The night has fallen but I'm still awake
My chances at zero
Breath for the last time, help's out of reach
No time for heroes

No regrets, no reason why
Release me, I'm dying

We stood side by side
Everybody's asking why
We had a dream, it ended in screams
They sold us as a question of honour
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,l,r,ar[20000];
long score[200];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
l=1;
r=n;
for (int i=1;i<=n;i++)
{
 score[i%2]+=max(ar[l],ar[r]);
 if (ar[l]>ar[r])++l;
 else --r;
}
cout<<score[1]<<" "<<score[0]<<endl;

cin.get();cin.get();
return 0;}