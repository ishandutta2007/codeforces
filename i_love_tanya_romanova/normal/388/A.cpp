/*
I have got a secret, hidden behind my eyes
A violation tragedy of violence hate and lies
Locked deep within a chamber, dark recesses of my mind
A tribute to insanity through hours days and time

Rotten to the core
Rotten to the core
Rotten to the core
Rotten to the core

Recite the testimonial, truth and nothing more
Accusations nominal fall rotten to the core
So take a look, read a book, reach a new plateau
But stain the soul a life you took you know not what I know

Rotten to the core
Rotten to the core
Rotten to the core
Rotten to the core

Misguided youth the bitter truth nothing left to chance
Angel seeking adventure, new romance
How dare you touch you take the soul of one so pure so white
The violation tragedy took all she had that night

Rotten to the core
Rotten to the core
Rotten to the core
Rotten to the core

I have got a secret hidden behind my eyes
A violation tragedy of violence hate and lies
Recite the testimonial, the truth and nothing more
Accusations nominal fall rotten to the core

Rotten to the core
Rotten to the core
Rotten to the core
Rotten to the core

To the core
Rot, rot, rot, rot, rot
Rot rot, rot, rot, rot, rot rotten to the core
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

long n,q,calc[20000],t;
long ans;

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{cin>>q;calc[q]++;}

for (int iter=1;iter<=100;iter++)
{
 t=0;
 for (int i=0;i<=100;i++)
 {
     while (t<=i&&calc[i]>0){++t;--calc[i];}
 }
 if (t)++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}