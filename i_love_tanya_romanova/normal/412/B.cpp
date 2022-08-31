/*
He is the King of all the land
In the Kingdom of the sands
Of a time tomorrow

He rules the sandworms and the Fremen
In a land amongst the stars
Of an age tomorrow

He is destined to be a King
He rules over everything
In the land called planet Dune

Body water is your life
And without it that you would die
In the desert the planet Dune

Without a still suit you would fry
On the sands so hot and dry
In a world called Arrakis

It is a land that's rich in spice
The sand riders and the mice
That they call the 'Muad'Dib'

He is the Kwizatz Haderach
He is born of Caladan
And will take the Gom Jabbar

He has the power to foresee
Or to look into the past
He is the ruler of the stars

The time will come for him
To lay claim his crown
And then the foe
Yes they'll be cut down
You'll see he'll be
The best that there's been
Messiah supreme
True leader of men

And when the time
For judgment's at hand
Don't fret, he's strong
He'll make a stand
Against evil and fire
That spreads through the land
He has the power
To make it all end
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define bsize 256

using namespace std;

long n,k,ar[200000];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>k;
for (int i=0;i<n;i++)
cin>>ar[i];
sort(ar,ar+n);
cout<<ar[n-k]<<endl;

cin.get();cin.get();
return 0;}