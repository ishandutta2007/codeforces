/*
And when life seems to be complete
It comes and knocks us off our feet
The element of surprise
The vengeful attack
Straight on your back it will send you
Into a state of deja-vu
Here it comes one more time
Showing its ugly face

Assaulting the senses
Screaming into the mind
Premeditating master plans
No need to underestimate

Prepare for what you cannot see
Expect the unexpected
And you will save yourself a state of shock
A waiting game, waiting to see
Expect the unexpected
And you will save yourself a state of shock

Another lesson learned to go with the others
That sit and wait to see
A silent voice

It doesn't matter who you are
In this sense we're all the same
To taste tranquility would be ecstasy
I'm holding on with all my might
To this ride we call life
Strapped down to clarity
Surprised no more
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
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n,m,val1,val2;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

if (n==1)
    cout<<1<<endl;
else
if (n%2==1&&m==n/2+1)
    cout<<m-1<<endl;
else
{
    val1=m-1;
    val2=n-m;
    if (val1>val2)
        cout<<m-1<<endl;
    else
        cout<<m+1<<endl;
}
//cin.get();cin.get();
return 0;}