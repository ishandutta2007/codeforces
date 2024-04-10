/*
I'm through with standing in line
To clubs we'll never get in
It's like the bottom of the ninth
And I'm never gonna win
This life hasn't turned out
Quite the way I want it to be

(Tell me what you want)

I want a brand new house
On an episode of Cribs
And a bathroom I can play baseball in
And a king size tub big enough
For ten plus me

(So what you need?)

I'll need a credit card that's got no limit
And a big black jet with a bedroom in it
Gonna join the mile high club
At thirty-seven thousand feet

(Been there, done that)

I want a new tour bus full of old guitars
My own star on Hollywood Boulevard
Somewhere between Cher and
James Dean is fine for me

(So how you gonna do it?)

I'm gonna trade this life for fortune and fame
I'd even cut my hair and change my name

[Chorus:]
'Cause we all just wanna be big rockstars
And live in hilltop houses driving fifteen cars
The girls come easy and the drugs come cheap
We'll all stay skinny 'cause we just won't eat
And we'll hang out in the coolest bars
In the VIP with the movie stars
Every good gold digger's
Gonna wind up there
Every Playboy bunny
With her bleach blond hair

Hey hey I wanna be a rockstar
Hey hey I wanna be a rockstar

I wanna be great like Elvis without the tassels
Hire eight body guards that love to beat up assholes
Sign a couple autographs
So I can eat my meals for free
(I'll have the quesadilla on the house)
I'm gonna dress my ass
With the latest fashion
Get a front door key to the Playboy mansion
Gonna date a centerfold that loves to
Blow my money for me
(So how you gonna do it?)
I'm gonna trade this life for fortune and fame
I'd even cut my hair and change my name

[Chorus]

And we'll hide out in the private rooms
With the latest dictionary and today's who's who
They'll get you anything with that evil smile
Everybody's got a drug dealer on speed dial, well

Hey hey I wanna be a rockstar

I'm gonna sing those songs
That offend the censors
Gonna pop my pills from a pez dispenser

I'll get washed-up singers writing all my songs
lip sync 'em every night so I don't get 'em wrong

[Chorus]

And we'll hide out in the private rooms
With the latest dictionary and today's who's who
They'll get you anything with that evil smile
Everybody's got a drug dealer on speed dial

Hey hey I wanna be a rockstar
Hey hey I wanna be a rockstar
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

long long n,m,p,ar1[100000],ar2[10000];

long long gcd(long long a,long long b)
{
     a=abs(a);
     b=abs(b);
     while (a&&b)a>b?a%=b:b%=a;
     return a+b;
}
int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
++n;++m;
for (int i=0;i<n;i++)
cin>>ar1[i];

for (int i=0;i<m;i++)
cin>>ar2[i];

if(m>n)cout<<"0/1"<<endl;
else if (m<n)
{
     if (ar1[0]*ar2[0]<0)cout<<"-Infinity"<<endl;
     else cout<<"Infinity"<<endl;
}
else
{
    p=gcd(ar1[0],ar2[0]);
    ar1[0]/=p;ar2[0]/=p;
    if (ar2[0]<0){ar1[0]=-ar1[0];ar2[0]=-ar2[0];}
    cout<<ar1[0]<<"/"<<ar2[0]<<endl;
}
cin.get();cin.get();
return 0;}