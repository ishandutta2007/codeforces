/*
Here it comes,
The story,
of mankind's final glory,
Into the nightfall.
The showdown,
Now has come.
This will be the last curtain,
Before the Night falls.

In a desert burning,
Children's faces turning,
Into another enemy in war.
Icy winds are blowing,
Over bodies piling high,
There's no place left for more.

Oh, save me from sharing this hell.
Oh, save me from my blame.

Here it comes,
The story,
of mankind's final glory,
Into the nightfall.
The showdown,
Now has come.
This will be the last curtain,
Before the Night falls.

We are worshipping the gods that keep twisting our thoughts.
Every day, a new sensation.
While a million creatures see their soil turning to dust,
Hrimata Eleison.

Oh, save me from sharing this hell.
Oh, save me from my blame.

Here it comes,
The story,
of mankind's final glory,
Into the nightfall.
The showdown,
Now has come.
This will be the last curtain,
Before the Night falls.

Forever and ever,
You hear them crying,
Forever and ever,
This world is dying,
We had so much time to understand.

Here it comes,
The story,
of mankind's final glory,
Into the nightfall.
The showdown,
Now has come.
This will be the last curtain,
Before the Night falls.

We are rising higher, closer to the fire,
Let the final dance begin.
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

long n;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
if (n<4)
{
 cout<<"NO"<<endl;
}
else
{
    cout<<"YES"<<endl;
    if (n%2==0)
    {
               for (int i=n-1;i>=5;i-=2)
               {
                cout<<i+1<<" - "<<i<<" = 1"<<endl;
                cout<<i-1<<" * 1 = "<<i-1<<endl;
               }
               cout<<"4 * 3 = 12"<<endl;
               cout<<"12 * 2 = 24"<<endl;
               cout<<"24 * 1 = 24"<<endl;
    }
    else
    {
                for (int i=n-1;i>=6;i-=2)
               {
                cout<<i+1<<" - "<<i<<" = 1"<<endl;
                cout<<i-1<<" * 1 = "<<i-1<<endl;
               }
               cout<<"1 - 5 = -4"<<endl;
               cout<<"2 - 4 = -2"<<endl;
               cout<<"-2 * -4 = 8"<<endl;
               cout<<"3 * 8 = 24"<<endl;
    }
}

cin.get();cin.get();
return 0;}