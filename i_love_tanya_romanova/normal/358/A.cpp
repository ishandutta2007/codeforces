/*
Be my one
Would you take my son?
Would you tell someone whether we had fun?
With your hero, double zero
Goin' in circles 'round your fear
Then I'm never ever falling again
Would you take my grace
Look into my face
With your limp handshake
And your smile thats fake
Would you back my fight
Say you're down for right
See its easy to say when you weren't doin' nothing

Maker makes me long for a better way
You fear my strength if we're backed into a cage

Because I,
I defy

See my fate
Underestimate
I intoxicate while you emulate
With the losers and the users
Suckin' up to the abusers
And I'm never ever fallin' again
For the tricks you play
All the fronts you claim
And you just cant fake
The respect I make
You're a parasite
You conform on site
You're a leak and a cheat
Always weak and always will be

Maker makes me long for a better way
You fear my strength if we're backed into a cage

Because I,
I defy

So burn it apart son

I'll give it away
I'll see
Why didn't you end the pain

I can't take this
I can't fake this
I will break this
I will make this

Cause
I defy
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,ar[20000];
long fl;

bool inter(long x1,long y1,long x2,long y2)
{
     if (x1>y1)swap(x1,y1);
     if (x2>y2)swap(x2,y2);
     if (x2>x1){swap(x1,x2);swap(y1,y2);}
//     cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
     if (x1>x2&&x1<y2&&y1>y2)return true;
     return false;
}
int main(){
//freopen("codes.in","r",stdin);
//freopen("codes.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
cin>>ar[i];
for (int i=0;i<n-1;i++)
 for (int j=0;j<n-1;j++)
 if (inter(ar[i],ar[i+1],ar[j],ar[j+1]))fl=1;
 if (fl)cout<<"yes"<<endl;
 else cout<<"no"<<endl;
cin.get();cin.get();
return 0;}