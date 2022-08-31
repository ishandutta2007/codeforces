/*
All my life I have been afraid.
All my life scared to lose my way.
All my life led me to today.
The day when I must learn the hardest way.
Every step leading to this day.
The day I learn to lose and fail.

A deeper cut into the flesh of life.
A sharper kind of knife.

A deeper cut into the throat of grey.
Come take me far away.
Come take me far away.
Lead me astray.

The deepest cut will never really mend.
The deepest cut might kill you in the end.
The deepest cut is playing not to win.
It's what you hear in every word I sing.
It's beauty in the ugliest of things.
It's birds that fly with broken wings.

A deeper cut into the flesh of life.
A sharper kind of knife.

A deeper cut into the throat of grey.
Come colors lead the way.
Come colors lead the way.
Into the wild
(Into the wild...)
Into the wild
(Into the wild)
Into the wild
(Into the wild)
Into the wild
(Into the wild)

Today I go beyond control
(Into the wild)
Beyond all purpose, aim or goal
(Into the wild)
To win my soul
(Into the wild)
'Cause today I choose to lose my way
(Into the wild)
To fall and fail
(Into the wild...)
I choose the wilderness today
(Into the wild)

Into the wild...
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

long n,a,b,c,d,ans,ac1,ac2;

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=4;i++)
{
    cin>>a>>b>>c>>d;
    if (min(a,b)+min(c,d)<=n)
    {
     ans=i;
     ac1=min(a,b);
     ac2=min(c,d);
     while (ac1+ac2<n)++ac1;
    }
}
if (ans==0)cout<<-1<<endl;
else cout<<ans<<" "<<ac1<<" "<<ac2<<endl;

cin.get();cin.get();
return 0;}