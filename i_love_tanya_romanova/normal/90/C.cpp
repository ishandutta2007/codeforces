/*
The world ain't all sunshine and rainbows
It's a very rough, mean place
And no matter how tough you think you are
It'll always bring you to your knees
And keep you there permanently if you let it

You, me or nobody ain't never gonna hit as hard as life
But it ain't about how hard ya hit
It's about how hard you can get hit and keep moving forward
How much you can take and keep moving forward

Now if you know what you're worth
Then go out and get what you're worth
But ya gotta be willing to take the hit

Once you die there's no coming back
Is it survival or is it emptiness?
I scratch the surface just to see another day

My eyes are bleeding, my hands are hurting
And the sun is burning, no one could understand
This life has given me addiction
Is just too hard to see

Even God forgot about me
As I stand here chaos reign's my destiny
Even God forgot about me
I'm just a useless being with no journey to fulfill

There's a hole in the sky
Big enough for me to fall
There's no one there to catch me
As I burn into this hell

The blade is touching my skin
Suicide is coming within
A past no one else sees
No hope, no time, no identity

Pain is underrated when your soul is annihilated
What is your fear? What is your motive for life?
I am the example of all that is your failures
Sink into me and drown with me

My eyes are bleeding, my hands are hurting
And the sun is burning, no one could understand
This life has given me addiction
Is just too hard to see

Even God forgot about me
As I stand here chaos reign's my destiny
Even God forgot about me
I'm just a useless being with no journey to fulfill

Tales of a soulless god

There's a hole in the sky
Big enough for me to fall
There's no one there to catch me
As I burn into this hell
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

long n,m,k,q,bst,onemove,pmove;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
bst=1e9;

for(int i=1;i<=n;i++)
{
        cin>>q;
        if (q<bst&&i%2==1)bst=q;
}

if (n%2==0)
{
 cout<<0<<endl;
 return 0;
}
else
{
 onemove=n+1;
 onemove/=2;
 pmove=m/onemove;
 if (pmove==0)bst=0;
 else 
 if (bst/pmove>=k)bst=pmove*k;
 cout<<bst<<endl;
}

cin.get();cin.get();
return 0;}