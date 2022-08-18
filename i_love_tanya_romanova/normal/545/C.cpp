/*
On a long and lonesome highway east of Omaha
You can listen to the engines moanin' out it's one note song
You can think about the woman or the girl you knew the night before

But your thoughts will soon be wandering the way they always do
When you riding sixteen hours with nothing much to do
And you don't feel much like ridin', you just wish the trip was through

Here I am, on the road again
There I am, up on the stage
Here I go, playin' star again
There I go, turn the page

You walk into a restaurant, strung out from the road
And you feel the eyes upon you, as you're shaking off the cold
You pretend it doesn't bother you, but you just want to explode

And most times you can't hear 'em talk, other times you can
All the same old cliches, "Is it woman? Is it man?"
And you always seem outnumbered, you don't dare make a stand
Make your stand

Here I am, on the road again
There I am, up on the stage
Here I go, playin' star again
There I go, turn the page

Out there in the spotlight you're a million miles away
Every ounce of energy you try to give away
As the sweat pours out your body, like the music that you play

Later in the evening, as you lie awake in bed
With the echoes of the amplifiers ringin' in your head
You smoke the days last cigarette, rememberin' what she said
What she said

Here I am, on the road again
There I am, up on the stage
Here I go, playin' star again
There I go, turn the page

There I go, turn that page
There I go, yeah
There I go, yeah
There I go, yeah
Here I go, yeah
There I go
There I go
And I'm gone
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,x[1<<20],h[1<<20],L,ans;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>x[i]>>h[i];    
}

L=-1e9;

for (int i=1;i<=n;i++)
{
    if (L<x[i]-h[i])
    {
        ans++;
        L=x[i];
    }
    else if (i==n||x[i]+h[i]<x[i+1])
    {
        ans++;
        L=x[i]+h[i];
    }
    else L=x[i];
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}