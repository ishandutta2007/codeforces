/*
Melodic stanzas
are symphonizing their way
through your weary head

To feed your distrust
And fill it's mouth with the desire
to soulfully be one with your creation

Not a subject to control
you call upon a higer power
for help and inspiration

The crowd waits
and turns their faces
towards you expectantly
you give them what they need
But their useless criticism
makes you die
a bit more inside

Not a subject to control
you call upon a higer power
for help and inspiration

Oh, I swoon
while loudspeakers play soft music

Leaning
over your fourtieth masterpiece
You must have loved
the colour of these violins

I wish I knew you
Your fit of insanity makes me sad

I wish you knew
your music was to stay forever
And I hope...

I have no clue
if you know how much it matters
And I hope...
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
//#define M_PI 3.141592653589793
#define bs 1000000009
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,x,cur,d,a,b;

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>x;
cur=1;
d=0;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
// cout<<d<<"  "<<cur<<endl;
 while (cur+x<=a)
 {
//  d++;
  cur+=x;
 }
 while (cur<a)
 {
  d++;
  cur++;
 }
 d+=(b-a+1);
 cur=b+1;
}

cout<<d<<endl;

cin.get();cin.get();
return 0;}