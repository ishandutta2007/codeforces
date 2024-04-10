/*
I'm victimized and tantalized
Brutalized and chained
They'll devastate - intoxicate
They're driving me insane - forever

They regulate - investigate
Complicate my life
Everyday insanity
There's nothing going right -
I mean forget it

I've been there before
Can't take it no more

That's why I'm like a loaded gun
A man with a mission
Like a loaded gun
I'm human ammunition

They mutilate and penetrate
They masturbate my brains
When all I need for sanity
Is love to ease my pain

I'm tortured, sick and tired
I'm that weapon to be fired
Overloaded - unexploded
Don't you make me cross the final line

I've been there before
I can't take it no more

That's why I'm like a loaded gun
I'm a man with a mission
Like a loaded gun
You can pull my trigger

Just like a loaded gun
On a social collision
See my eyes - I mesmerize
Read my lips - it's time to cut the crap

I've been there before
I can't take it no more

That's why I'm like a loaded gun
A man with a mission
Like a loaded gun
I'm human ammunition

Like a loaded gun
On a social collision
Like a loaded gun
I'm ready to explode -
like a loaded gun
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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,k;

int main(){
//freopen("supper.in","r",stdin);
//freopen("supper.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
if (k==n)cout<<-1<<endl;
else if (k==n-1)
{
     for (int i=1;i<=n;i++)
     {
         if (i)cout<<" ";
         cout<<i;
     }
     cout<<endl;
}
else
{
    cout<<n;//<<" ";
    for (int i=2;i<=k+1;i++)
    {
        cout<<" "<<i;
    }
    for (int i=k+2;i<=n;i++)
    {
        if (i==k+2)cout<<" "<<1;
        else cout<<" "<<i-1;
    }
    cout<<endl;
}
cin.get();cin.get();
return 0;}