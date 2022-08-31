/*
I have lost myself within a curse
And must become someone else, someone worse...

I have lost the track of days for a night has fallen upon me
A darkness too thick for all light to penetrate
My eyes have grown to wear the dark yet still I cannot see
No strength left in this shell to rise from my ill-fate

It feels like ages since I've last spoken
It feels like aeons since I last slept
But in this silence there is no comfort
Nothing to dry the rivers I have wept

I barely remember what joy felt like
Hardly recall what it was once to live
Drowning ever deeper into the dark despite for ages
This wretched soul has had nothing more to give

And forgive me for holding you too tight
That just to breathe you had push yourself away
And forgive me for far too long stealing your eyes
That without sight you were bound to walk away

For what is given can never be returned
A heart, a life, a shell now broken, incomplete
Like a world far too long allowed to burn
Nothing left to salvage, nothing left to keep

And forgive me for all my dreams
That far too long kept you awake
And forgive me for replacing the Sun with you
Leaving you in the dark, too dense for you to take

Now at the heart of dying, from the depths I dwell
I grant thee heaven, and for myself I reserve only Hell...

Like all flowers too fair for this world
Draw near the beasts to devour and to rend
Then how could a love far too fair for this cold world
Do nothing more but end

And in my heart the memories of those years
I would cherish and I would hold
But without one there is nothing left to do
But to succumb to the bleak and cold...

And forgive me for all my crimes
Unforgive me for all these lines...
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

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n,m;
string st;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=0;j<st.size();j++)
  if (st[j]=='-')cout<<st[j];
  else if (i%2==j%2)cout<<"B"; else cout<<"W";
  cout<<endl;
}
cin.get();cin.get();
return 0;}