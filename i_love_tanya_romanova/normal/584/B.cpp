/*
Arriving in boats, black hooded coats
Tormentors climbed into my room
I crawled under my bed, covered my head
But they're flushin' me out with a broom

The leader, she's small, pinned my ass to the wall
For my seeds or she'd be losin' her past
Time after time, she'd be readin' my mind
But she never got the feelin' to last

Celebrate, celebrate, celebraid it
This is the critical mass

So far so good, I heard the other say
So good so far, they're takin' me away
I drink to you, your mind, her ass
We'll take a drink and break the glass

Celebrate, celebrate, celebreak it
This is the critical mass

Now the tallest of two, with a brush full of blue
Paints surrealist scenes on the wall
So I tell her for fun, that it's really well done
But she just ain't listenin' at all

She points to my heart, tellin' me if I'm smart
I'll practice and phase
Out and admit, when the shoe doesn't fit
And I went screaming out down the hall

Really need it
Really need your love
Really need your love
Need your love need your love love love love love love love love love love

Just then I heard a poundin' on the door
We're all here, sang the voice of twenty more
I drink to you alas
We'll take a drink and break the glass

Celebrate, celebrate, celebreak it
We are the critical mass

Time in space, is takin' me away
Time erase, don't know the time of day
Time in space, is takin' me away
Time erase, don't know the time of day
Time in space, is takin' me away
Time erase, don't know the time of day
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

long long n,ans1,ans2;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
ans1=ans2=1;
for (int i=1;i<=n;i++)
{
	ans1=ans1*27%bs;
}
for (int i=1;i<=n;i++)
{
	ans2=ans2*7%bs;
}

ans1=ans1-ans2;
if (ans1<0)
	ans1+=bs;
cout<<ans1<<endl;

//cin.get();cin.get();
return 0;}