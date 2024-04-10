/*  
Silence disguised
I watch you
Show me the hurt
that haunts you
would you despise the thrill
If all you hide were mine?

I can't hold on any longer
These feelings keep growing stronger
Echoes that deafen the mind
will bury my voice in their wake

Caught in a Web
Removed from the world
Hanging on by a thread
Spinning the lies
devised in my head

I've seen the path
the one you take
shows the truth
for you to make
This turn of phrase
we might not see
is the thirst of desire
found so easily

Try to push me 'round
the world some more
And make me live in fear
I bare all that I am
made of now
Attractive I don't care
'Cause even when I danced with life
no one was there to share

Does this voice the wounds of your soul?
Does this voice the wounds of your soul?

Caught in a Web
Removed from the world
Hanging on by a thread
Spinning the lies
devised in my head

Tried to live the life
you live and saw
It doesn't work for me
I bare all that I am
made of now
Attractive, I can't be
Inside the Dance of Life is one
I'll never hold to me

You can't heal the wounds of my soul.
You can't heal the wounds of my soul.

Caught in a Web
Removed from the world
Hanging on by a thread
Spinning the lies
devised in my head

Caught in a Web
Refused by the world
Hanging on by a thread
Spinning a cage
Denied and misread
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,m,aa,bb,a[1000],b[1000];
char ar[100][100];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
 cin>>ar[i][j];
 if (ar[i][j]=='S'){a[i]=1;b[j]=1;}   
}

for (int i=1;i<=max(n,m);i++)
{
    aa+=a[i];bb+=b[i];
}
cout<<n*m-aa*bb<<endl;

cin.get();cin.get();
return 0;}