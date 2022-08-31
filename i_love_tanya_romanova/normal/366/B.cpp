/*
Let me go
Let me go
Let me seek the answer that I need to know
Let me find a way
Let me walk away
Through the Undertow
Please let me go

Let me fly
Let me fly
Let me rise against that blood-red velvet sky
Let me chase it all
Break my wings and fall
Probably survive
So let me fly
Let me fly...

Let me run
Let me run
Let me ride the crest of chance into the sun
You were always there
But you may lose me here
Now love me if you dare
And let me run

I'm alive and I am true to my heart now - I am I,
but why must truth always make me die?

Let me break!
Let me bleed!
Let me tear myself apart I need to breathe!
Let me lose my way!
Let me walk astray!
Maybe to proceed...
Just let me bleed!

Let me drain!
Let me die!
Let me break the things I love I need to cry!
Let me burn it all!
Let me take my fall!
Through the cleansing fire!
Now let me die!
Let me die...

Let me out
Let me fade into that pitch-black velvet night
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,q,k,s[200000],bst,bp;

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for(int i=0;i<n;i++)
{
 cin>>q;
 s[i%k]+=q;
}
bst=1e9;
bp=0;
for (int i=0;i<k;i++)
if (s[i]<bst){bst=s[i];bp=i;}
cout<<bp+1<<endl;

cin.get();cin.get();
return 0;}