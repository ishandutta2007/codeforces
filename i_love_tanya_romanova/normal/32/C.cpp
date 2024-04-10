/*
The clock strikes twelve and moondrops burst
Out at you from their hiding place?
Like acid and oil on a madman's face
His reasons tend to fly away

Like lesser birds on the four winds, yeah
Like silver scrapes in May
Now the sands become a crust
And most of you have gone away...
Yea, gone away

Ah, come Susie dear, let's take a walk
Just out there upon the beach
I know you'll soon be married
And you'll want to know where winds come from

Well, it's never said at all
On the map that Carrie reads
Behind the clock back there you know
At the four winds bar, mm, yeah

Yeah
Hey!
Hey!
Hey!
Hey!
Four winds at the four winds bar
Two doors locked, ten windows barred
One door left to take you in
The other one just mirrors it
Hey!
Hey! Yeah!
Hey! Yeah!
Hey!

Ooh, in hellish glare and inference
The other one's a duplicate
The queenly flux, eternal light
Or the light that never warms
Yes, the light that never, never warms
Yes, the light that never, never warms
Never warms, never warms

The clock strikes twelve and moondrops burst
Out at you from their hiding place?
Miss Carrie nurse and Susie dear
Would find themselves at four winds bar

It's the nexus of the crisis
And the origin of storms
Just the place to hopelessly
Encounter time and then came me

Hey!
Hey!
Hey!
Hey!

Call me Desdenova, eternal light
These gravely digs of mine
Will surely prove a sight
And don't forget my dog, fixed and consequent

Astronomy - a star
Astronomy - a star
Astronomy (astronomy) - a star, yeah
Astronomy - a star

Astronomy
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,m,s;

long long solve(long long x,long long y)
{
 if (x%y==0)return x;
 return (x%y)*(x/y+1);
}
int main(){
//freopen("test.in","r",stdin);
//freopen("test.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>s;
cout<<1ll*solve(n,s)*solve(m,s)<<endl;

cin.get();cin.get();
return 0;}