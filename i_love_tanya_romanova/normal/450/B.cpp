/*
I'll never be your beast of burden
My back is broad but it's a hurting
All I want is for you to make love to me

I'll never be your beast of burden
I've walked for miles my feet are hurting
All I want is for you to make love to me

Am I hard enough
Am I rough enough
Am I rich enough
I'm not too blind to see

I'll never be your beast of burden
So let's go home and draw the curtains
Music on the radio
Come on baby make sweet love to me

Am I hard enough
Am I rough enough
Am I rich enough
I'm not too blind to see

Oh little sister
Pretty, pretty, pretty, pretty, girl
Pretty, pretty
Such a pretty, pretty, pretty girl
Come on baby please, please, please

I'll tell you you can put me out on the street
Put me out with no shoes on my feet
But, put me out, put me out
Put me out of misery

Yeah, all your sickness I can suck it up
Throw it all at me I can shrug it off
There's one thing baby that I don't understand
You keep on telling me I ain't your kind of man

Ain't I rough enough, oh honey
Ain't I tough enough
Ain't I rich enough in love enough
Oh please

I'll never be your beast of burden
I'll never be your beast of burden
Never, never, never, never, never, never, never be

I'll never be your beast of burden
I've walked for miles my feet are hurting
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
//#include <memory.h>

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
//#define N 120000

using namespace std;

long x,y,n;
vector<long> v;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x>>y;
v.push_back(x);
v.push_back(y);
v.push_back(y-x);
v.push_back(-x);
v.push_back(-y);
v.push_back(x-y);

cin>>n;
--n;
x=v[n%6]%bs;
while(x<0)x+=bs;
cout<<x<<endl;

cin.get();cin.get();
return 0;}