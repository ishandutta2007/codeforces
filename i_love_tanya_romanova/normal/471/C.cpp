/*

Am I alive?
Feels like dying

Down, down
Fists are striking me
It gets so dark
Or are my eyes blinded?

Down, down
Boots are kicking me
The coward, the sinner, the thief
The liar, the misfit, the creep

I'm running out of
Steps to walk
Of air to breathe
And words to talk

I'm running out of
Noise to make
Of jokes to tell
And hearts to break

For days burned and frozen lies
The years that passed me by
The child in me just died

The scars in me will never heal
An overdose of nothingness
My visions are for sale, I'm selling out

I am alive but always falling

Down, down
I hear voices calling me
The coward, the sinner, the thief
I am alive kind of wasted

Down, down
Hands are reaching me
The coward, the sinner, the thief
The liar, the misfit, the creep

I'm running out of dreams to dream
Of tears to spend and screams to scream
I'm running out of life again smothering
Turning into dust
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
#define right adsgasgadsg

using namespace std;

long long n,ans;
long long solve(long long x)
{
 long long res=3*x*(x+1)/2;
 res-=x;
 return res;
}

int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=5000000;i++)
if (solve(i)<=n&&solve(i)%3==n%3)++ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}