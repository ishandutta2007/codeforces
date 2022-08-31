/*
On this day I see clearly everything has come to life
A bitter place and a broken dream
And we'll leave it all behind
On this day its so real to me
Everything has come to life
Another chance to chase a dream
Another chance to feel
Chance to feel alive

I've been defeated and brought down
Dropped to my knees when hope ran out
The time has come to change my ways

On this day I see clearly everything has come to life
A bitter place and a broken dream
And we'll leave it all, leave it all behind

I'll never long for what might have been
Regret won't waste my life again
I won't look back
I'll fight to remain:

On this day I see clearly everything has come to life
A bitter place and a broken dream
And we'll leave it all behind
On this day its so real to me
Everything has come to life
Another chance to chase a dream
Another chance to feel
Chance to feel alive

Fear will kill me, all I could be
Lift these sorrows
Let me breathe, could you set me free
Could you set me free

On this day I see clearly everything has come to life
A bitter place and a broken dream
And we'll leave it all behind
On this day its so real to me
Everything has come to life
Another chance to chase a dream
Another chance to feel
Chance to feel alive
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
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define count adsgasdgasdg

using namespace std;

string st;
long s[1<<20];
long tests,x;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>tests;
for (;tests;--tests)
{
 cin>>x;
 s[x-1]++;
}
int rev=0;
for (int i=0;i<st.size()-i-1;i++)
{
 rev+=s[i];
 if (rev%2) swap(st[i],st[st.size()-i-1]);
}
for (int i=0;i<st.size();i++)
cout<<st[i];
cout<<endl;

cin.get();cin.get();
return 0;}