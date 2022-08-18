/*
Still I'm spreading my disease
You work it out this time
Hell no, I won't retreat
Two times won't make it happen
Three times won't make it go
Overcome, make it run
I insist to make it flow

Now I'm chasing what I've learned
You won't be blind this time
Getting back what they have burned
Two times won't make it happen
Three times won't make it go
Overload, still grows
I resist and make it flow

Trusting the ways of my vulnerable heart
A million times before I get things right
So fragile it hurts when I just fall apart
Wait now!

Still I won't get what I deserve
Your search for the dreams may falter
Paying back won't make it turn
Four times won't make it happen
Five times won't make it go
Overrule, from a tool
That brings me everlasting pain

Trusting the ways of my vulnerable heart
A million times before I get things right
So fragile it hurts when I just fall apart

Those thoughts are rulin' my valuable time
In search for shelter I draw the lines
Won't you give me another break
To examine my growing and countless mistakes

Trusting the ways of my vulnerable heart
A million times before I get things right
So fragile it hurts when I just fall apart

Trusting the ways of my vulnerable heart
A million times before I get things right
So fragile it hurts when I just fall apart
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

using namespace std;

long r1,r2,c1,c2,d1,d2,ar[20][20],ans[20][20];

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>r1>>r2>>c1>>c2>>d1>>d2;

for (ar[1][1]=1;ar[1][1]<=9;ar[1][1]++)
for (ar[1][2]=1;ar[1][2]<=9;ar[1][2]++)
for (ar[2][1]=1;ar[2][1]<=9;ar[2][1]++)
for (ar[2][2]=1;ar[2][2]<=9;ar[2][2]++)
if (ar[1][1]!=ar[1][2]&&ar[1][1]!=ar[2][1]&&
ar[1][1]!=ar[2][2]&&ar[1][2]!=ar[2][1]&&ar[1][2]!=ar[2][2]&&
ar[2][1]!=ar[2][2])
{
 if (ar[1][1]+ar[1][2]==r1)
 if (ar[2][1]+ar[2][2]==r2)
 if (ar[1][1]+ar[2][1]==c1)
 if (ar[1][2]+ar[2][2]==c2)
 if (ar[1][1]+ar[2][2]==d1)
 if (ar[1][2]+ar[2][1]==d2)
 ans[1][1]=ar[1][1],
 ans[1][2]=ar[1][2],
 ans[2][1]=ar[2][1],
 ans[2][2]=ar[2][2];
}

if (ans[1][1]==0)
cout<<-1<<endl;
else
{
 cout<<ans[1][1]<<" "<<ans[1][2]<<endl;
 cout<<ans[2][1]<<" "<<ans[2][2]<<endl;
}

cin.get();cin.get();
return 0;}