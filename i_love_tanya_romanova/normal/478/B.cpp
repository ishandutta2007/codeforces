/*
Sometimes I'm a selfish fake
You're always a true friend
And I don't deserve you
'Cause I'm not there for you
Please forgive me again

I wanna be there for you
Someone you can come to
Runs deeper than my bones
I wanna be there for you
I wanna be there for you

Swirling shades of blue
Slow dancing in your eyes
Sun kisses the earth
And I hush my urge to cry, cry

I wanna be there for you
Someone you can come to
Runs deeper than my bones
I wanna be there for you
I wanna be there for you

'Cause I hear the whispered words
In your masterpiece beautiful
You speak the unspeakable through
I love you too

I wanna be there for you
Someone you can come to

I wanna be there for you
And be someone you can come to
The love runs deeper than my bones
And I wanna be there for you
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
#define free adsgasdg

using namespace std;

long long n,m,a,ans1,ans2;

long long get(long long x)
{
 return x*(x-1)/2;
 
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
a=n-m+1;
ans2=get(a);
a=n/m;
ans1=get(a+1)*(n%m)+get(a)*(m-n%m);
cout<<ans1<<" "<<ans2<<endl;

cin.get();cin.get();
return 0;}