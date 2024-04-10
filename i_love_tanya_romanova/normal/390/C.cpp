/*
When life begins, young and free from sins
Under the skies of love, we're thriving on and on
As the years go by, on the stage of life
With blinded eyes, we believe in lies

Back to the ages of power, it's time for us to learn
One day it's far too late, too late for a return
Arise from the cower from the day on we have learned
It's high time to break the spell that's chaining up the world

We glorify all our endless crimes
In a high degree, will we ever see the signs?
We will prevail, we will never fail
We pay for all, we're the last to fall

Back to the ages of power, it's time for us to learn
One day it's far too late, too late for a return
Arise from the cower from the day on we have learned
It's high time to break the spell that's chaining up the world

Time for return is here
We overcome our fear
Will we ever see our agony?
Will we ever try?

Unleashed, the beast is raging on
Dark angel with the serpent's tongue
Beware that the ending has begun

Back to the ages of power, it's time for us to learn
One day it's far too late, too late for a return
Arise from the cower from the day on we have learned
It's high time to break the spell that's chaining up the world
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
 
//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 2048
 
using namespace std;

long n,k,w,s[200000][12],s1[200000],a,b;
string st;
long span;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k>>w;
cin>>st;

for (int i=1;i<=n;i++)
{
 for (int j=0;j<k;j++)
 s[i][j]=s[i-1][j];
 if (st[i-1]=='1')s[i][i%k]++;
 for (int j=0;j<k;j++)
 s1[i]+=s[i][j];
}

for (;w--;)
{
 cin>>a>>b;long summ;
 span=b-a+1;
 summ=s1[b]-s1[a-1];// all in
 summ-=s[b][b%k]-s[a-1][(a-1)%k];// tr
 summ+=(b-a)/k+1-(s[b][b%k]-s[a-1][(a-1)%k]);
 cout<<summ<<endl;
}

cin.get();cin.get();
return 0;}