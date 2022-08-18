/*
Asked a girl what she wanted to be
She said baby, "Can't you see
I wanna be famous, a star on the screen
But you can do something in between"

Baby you can drive my car
Yes I'm gonna be a star
Baby you can drive my car
And maybe I love you

I told a girl that my prospects were good
And she said baby, "It's understood
Working for peanuts is all very fine
But I can show you a better time"

Baby you can drive my car
Yes I'm gonna be a star
Baby you can drive my car
And maybe I love you
Beep beep'm beep beep yeah

Baby you can drive my car
Yes I'm gonna be a star
Baby you can drive my car
And maybe I love you

I told that girl I can start right away
And she said, "Listen baby I got something to say
I got no car and it's breaking my heart
But I've found a driver and that's a start"

Baby you can drive my car
Yes I'm gonna be a star
Baby you can drive my car
And maybe I love you
Beep beep'm beep beep yeah
Beep beep'm beep beep yeah
Beep beep'm beep beep yeah
Beep beep'm beep beep yeah (fade out)
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n,k,s,a,b;

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>a>>b;
    s+=b-a+1;
}
s%=k;
if (s==0)cout<<0<<endl;
else cout<<k-s<<endl;

cin.get();cin.get();
return 0;}