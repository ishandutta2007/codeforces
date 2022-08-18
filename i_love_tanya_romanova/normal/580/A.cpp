/*
The lives of some men
If walls can taught to spills the lies
We'll see the world through devil's eyes

I maintain an addiction
Been known to take it too high
I gotta a inch with a loaded head trigger
And a one way ticket to fly

When there's no writing on the wall
I see the lifeless devils start to crawl
And I don't need no lessons
After all
Everybody's doing their time

Caught your eye in the corner,
Don't you look at me wrong
Fucked up and thrown into the gutter,
gotta fix what don't belong

I see the writing on the wall
I see the lifeless devils start to crawl
And I don't need no lessons
After all
Everybody's doing their time

That's just a price to play
So tell me what you like
Gotta hand on the kerosene match tonight, right

Had enough of opinions
I got enough on my mind
Sell your soul for approval and a dollar
Got a pretty little body to grind

I see your number on the wall
I see the lifeless devils start to crawl
I don't need no lessons
Watch the fall
You lost my attention
After all
Everybody's doing their time, time
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

int n,ar[1<<20];
int l;
int ans;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
	cin>>ar[i];
	if (ar[i]>=ar[i-1])
		l++;
	else
		l=1;
	ans=max(ans,l);
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}