/*
Empty and sweating
Head lying in your hands
Shaking in the corner
Done too much alcohol
Gotta get away from it all
'Cause it feels my blood is freezing
My self insanity has taken its toll
Frustration has taken its control

Now I'm far from home
Spending time alone
It's time to set my demons free
Been put to the test
My mind laid to rest
I'm on a psycho holiday

Shot down on sight
You are the target of attention
One woman here another there
You can't please all the people all the time
Can't tell the strangers
From the friends you know
Frustration has taken it's control

Now you're far from home
Spending time alone
It's time to set your demons free
Been put through the test
Your mind laid to rest
You're on a psycho holiday

I'm strapped in for life
Is this where I lived
Or where I died
You want my money
You take my space
My mind is telling me
To leave this place
My self insanity has taken its toll
Frustration has taken its control

Now you're far from home
Spending time alone
It's time to set your demons free
Been put through the test
Your mind laid to rest
You're on a psycho holiday
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
#define clone agsdahfaassdg

using namespace std;

long a,b,ax1,ax2,ay1,ay2,sum;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b;
sum=abs(a)+abs(b);
ax1=sum;
if (a<0)ax1=-ax1;
ay1=0;
ax2=0;
ay2=sum;
if (b<0)ay2=-ay2;
if (ax1>ax2){swap(ax1,ax2);swap(ay1,ay2);}

cout<<ax1<<" "<<ay1<<" "<<ax2<<" "<<ay2<<endl;;

cin.get();cin.get();
return 0;}