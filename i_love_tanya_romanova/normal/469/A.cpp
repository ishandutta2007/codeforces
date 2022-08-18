/*
Come and sail along the shores of your homeland
See the waves that break onto the walls surrounding all

Tell me
Why have you lost all your wildest desires?
Where is the treasure to die for?
Is there a heart that longs for the unknown in yourself?
No one else but you can...

Sail away to the end of the seas,
The land of dreams, the child to release
Once the horizon is left behind
All you will hear's the Call of the Wind

Leave behind the land that has been turned to grey
Where the winds have whispered only from so far away

Asking
Why don't you face all your wildest desires?
When is the time that you wait for?
There will be nothing to lose but your fear
So come on - and follow me now

Sail away to the end of the seas,
The land of dreams, the child to release
Once the horizon is left behind
All you will hear's the Call of the Wind

Sail away to the end of the seas,
The land of dreams, the child to release
Once the horizon is left behind
All you will hear's the Call of the Wind

Voluntas numerit anima viva 
Wishes are still sleeping in your heart

Sail away to the end of the seas,
The land of dreams, the child to release
Once the horizon is left behind
All you will hear's the Call of the Wind

Sail away to the end of the seas,
The land of dreams, the child to release
Once the horizon is left behind
All you will hear's the Call of the Wind

Turn the page and follow the lines
Through words of fear and hidden signs
Someday the story unveils what's within
And it is yours, the voice of the wind

Come and try to fight your demons away
Before the coldness drives you insane
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

using namespace std;

long n,t,q,ans[1<<10];

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>t;
for (;t;--t)
{
 cin>>q;
 ans[q]|=1;
}
cin>>t;
for (;t;--t)
{
 cin>>q;
 ans[q]|=1;
}
q=0;
for (int i=1;i<=n;i++) 
q+=ans[i];
if (q==n)
cout<<"I become the guy."<<endl;
else cout<<"Oh, my keyboard!"<<endl;

cin.get();cin.get();
return 0;}