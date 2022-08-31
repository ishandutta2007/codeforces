/*
Forgotten faces.
Lost in yesterdays realm.
Drained with confusion.
Where did it all go?
Look into the past, look into their faces.
Never, the thought of being time fucked.
But now they're all gone and all that's left is this blank faced picture.
Ninety percent, nothing was done, nothing accomplished,
coasting through life didn't seize the day.
No one ever realized that they're already dead.
By the time you realize, you'll be dead too.
Without another chance to save the world,
these things they're gone, your gone, forgotten.
Now your face in my picture frame. It's gone, forever.
Right before my very eyes.
And just when I thought I made light of things.
It slips away, into darkness.
My life passes now I see.
Just what this world does hold for me.
It's getting hard, harder to breathe.
Am I out of time is that what this means?
Well that's what it means.
That's what it means, you and me try to breathe.
Now you. Realize.
Your life, flies by.
Now I. Realize.
My life, I die.
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

long n,q,calc[2000],ps;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 for (int j=1;j<=q;j++)
 calc[j]++;
}

for (;n;--n)
{
 ps=0;
 while (calc[ps+1]>=n)++ps;
 cout<<ps;if (n>1)cout<<" ";//<<" ";
}
cin.get();cin.get();
return 0;}