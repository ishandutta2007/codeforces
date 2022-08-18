/*
For today we will take the body parts
And put them on the wall
For treated indigenously, digenously
Human right is private blue chip, pry

For treated indigenously, digenously
(We're the prophetic generation of bottled water, bottled water)
Human right is private blue chip, pry
(Causing poor populations to die, to die, to die)

You, you went beyond
And you lost it all
Why did you go there?
From beyond, you saw it all
Why did you?

For treated indigenously, digenously
(We lost consumer confidence in casual karma, casual karma)
Human right is private blue chip, pry
(Confetti, camouflage, camouflage, the flage, the flage)

For treated indigenously, digenously
(We're the prophetic generation of bottled water, bottled water)
Human right is private blue chip, pry
(Causing poor populations to die, to die, to die)

You, you went beyond
And you lost it all
Why did you go there?
From beyond, you saw it all
Why did you go there?

She lost her mind, someone kicked her
Into the back of the line
She lost her head when they called
And they said that they thought he was dead

Dreaming of screaming
Someone kick me out of my mind
I hate these thoughts, I cant deny
Dreaming of screaming
Someone kick me out of my mind
I hate these thoughts, I cant de

For treated indigenously, digenously
(We lost consumer confidence in casual karma, casual karma)
Human right is private blue chip, pry
(Confetti, camouflage, camouflage, the flage, the flage)

For treated indigenously, digenously
(We're the prophetic generation of bottled water, bottled water)
Human right is private blue chip, pry
(Causing poor populations to die, to die, to die)

You, you went beyond
And you lost it all
Why did you go there?
From beyond, you saw it all
Why did you?

Na na na
Na na na
Na na na

Dreaming of screaming
Someone kick me out of my mind
I hate these thoughts, I cant deny
Dreaming of screaming
Someone kick me out of my mind
I hate these thoughts, I cant deny

You will take the body parts
And put them up on the wall
And bring the dark disaster
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

string st;
vector<long> nice;
long sz[200];
long bad;

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=4;i++)
{
 cin>>st;
 sz[i]=st.size()-2;
}
nice.clear();

for (int i=1;i<=4;i++)
{
 bad=0;
 for (int j=1;j<=4;j++)
  if (i-j)
   if (sz[i]<sz[j]*2)bad=1;
 if (bad==0)nice.push_back(i);
}
for (int i=1;i<=4;i++)
{
 bad=0;
 for (int j=1;j<=4;j++)
  if (i-j)
   if (sz[i]*2>sz[j])bad=1;
 if (bad==0)nice.push_back(i);
}

if (nice.size()!=1)
{
 nice.push_back(3);
}
cout<<char(nice.back()+'A'-1)<<endl;

cin.get();cin.get();
return 0;}