/*
Staring at the sea
Will she come?
Is there hope for me
After all is said and done?

Anything at any price
All of this for you
All the spoils of a wasted life
All of this for you

All the world has closed her eyes
Tired faith all worn and thin
For all we could have done
And all that could have been

Ocean pulls me close
And whispers in my ear
The destiny I've chose
All becoming clear

The currents have their say
The time is drawing near
Washes me away
Makes me disappear

And I descend from grace
In arms of undertow
I will take my place
In the great below

I can still feel you
Even so far away
I can still feel you
Even so far away

I can still feel you
Even so far away
I can still feel you
Even so far away

Even so far away
Even so far away
Even so far away
So far away
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
#define bsize 512

using namespace std;

long n,q,calc,spans,ans;

int main(){
//freopen("highway.in","r",stdin);
//freopen("highway.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n+1;i++)
{
 if (i>n)q=0;else cin>>q;
 if (q==1)++calc;
 else
 {
     if (calc){ans+=calc+1;spans++;calc=0;}
 }
}

if (spans)--ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}