/*
A child was born, forever young
Alone in virgin' s hands
A son for mankind?s innocence
Raised in a holy land, alone

A star shined on a thousand nights
Diamond in the sky
Freedom for us all

High up in the sky
Guide our path through life
Save us from despair
Blazing rays of light
Feel so warm inside
Take us to this holy land
Until the day comes we return
to innocence, again

Pass through the gates of time
Be our guiding light
Saviour of our souls
Keep us all alive
Eyes are open wide
Stare into your crystal ball
The time has come for us -
return to innocence

Forever again, forever - whenever again, whenever

Shine on, starlight
Saviour comes from somewhere
Ride on, guardian
Take us back where eagles dare

Fly into our fantasy
Take us to eternity
We' ll never cry,
we' ll never die
Return to innocence
forever again - forever - whenever again - whenever

Shine on, starlight
Saviour comes from somewhere

Ride on, guardian
Take us back where eagles dare
Shine on, starlight
Saviour comes from everywhere
Ride on, guardian
Take us back where eagles dare, tonight

A child was born forever young - fly
Bring us back the wayward son - cry
Freedom for us all

Shine on, starlight
savior comes from somewhere
ride on, guardians
take us back where eagles dare
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

set<long> s1,s2;
long n,a,b;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 s1.insert(a);s2.insert(b);
}
cout<<min(s1.size(),s2.size())<<endl;

cin.get();cin.get();
return 0;}