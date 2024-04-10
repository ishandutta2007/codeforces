/*
In my town where the system sleeps
Nobody gives a damn
It's up to you how to hide or flee
Their hunger never ends

Hateful design builds the structure divine
A territory cold as ice
An endless empire with cynic desire
Born of a broken spell

Feelin' like a guttersnipe standing in line
Deciding his lifestyle by rolling the dice
One will stand another will fall down
Find your way out from the constant lack

Feelin' like a guttersnipe standing in line
Deciding his lifestyle by rolling the dice
One will stand another will fall down
Find your way out from the constant lack

You gotta get yourself a picture
(Gotta get yourself a picture)
Of what is going on
(What is going on)
'Cause their lips are sealed now
Their honesty never to be found

Hateful design builds the structure divine
A territory cold as ice
An endless empire with cynic desire
Born of a broken spell

Feelin' like a guttersnipe standing in line
Deciding his lifestyle by rolling the dice
One will stand another will fall down
Find your way out from the constant lack

Feelin' like a guttersnipe standing in line
Deciding his lifestyle by rolling the dice
One will stand another will fall down
Find your way out from the constant lack

Your pride is just a symbol
Another hidden excuse
For being such a savior
Distorting your sick self abuse

Turn over, turn over, turn over
(Argh!)

Feelin' like a guttersnipe standing in line
Deciding his lifestyle by rolling the dice
One will stand another will fall down
Find your way out from the constant lack

Feelin' like a guttersnipe standing in line
Deciding his lifestyle by rolling the dice
One will stand another will fall down
Find your way out from the constant lack

Feelin' like a guttersnipe standing in line
Deciding his lifestyle by rolling the dice
One will stand another will fall down
Find your way out from the constant lack

Feelin' like a guttersnipe standing in line
Deciding his lifestyle by rolling the dice
One will stand another will fall down
Find your way out from the constant lack
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

using namespace std;

long n,x,q;
vector<long> v;
long has;

long gett()
{
 sort(v.begin(),v.end());
 return v[(v.size()+1)/2-1];
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>x;
for (int i=0;i<n;i++)
{
 cin>>q;
 v.push_back(q);
 if (q==x)
 has=1;
}
if (has==0)v.push_back(x);

while (true)
{
 q=gett();
 if (q<x)v.push_back(100000);
 if (q>x)v.push_back(1);
 if (q==x)break;
}
cout<<v.size()-n<<endl;

cin.get();cin.get();
return 0;}