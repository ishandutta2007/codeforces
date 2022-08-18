/*
Everybody knows,
Everybody knows,
That you cradle the sun, sun
Living in remorse,
Sky is over,

Dont you want to hold me baby,
Disappointed, going crazy,

Even though we cant afford
The sky is over,
Even though we cant afford
The sky is over,
I dont want to see you go,
The sky is over
Even though we cant afford
The sky is over,

Behind closes eyes lie
The minds ready to awaken you,
Are you at war with land
And all of its creatures,
Your not-so-gentle persuasion
Has been known to wreck economies
Of countries, of empires, the sky is over,

Dont you want to hold me baby,
Disappointed, going crazy,

Not even from the sun,
Not even from the sun
Not even from the sun,
Dont you want me to run,

Even though you cant afford
The sky is over,
Even though we cant afford
The sky is over,
I dont want to see you go,
The sky is over
Even though we cant afford
The sky is over,
I dont want to see you go,
The sky is over
Even though we cant afford
The sky is over,
I dont want to see you go,
The sky is over
Even though we cant afford
The sky is over,
The sky is over us.
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n,r,k;

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
r=1;
for (int i=1;i<=(n-k);i++)
r=r*(n-k)%bs;
for (int i=1;i<=k-1;i++)
{r*=k;r%=bs;}

cout<<r%bs<<endl;

cin.get();cin.get();
return 0;}