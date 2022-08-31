/*
Kept in the guard of Mother Nature's womb
Resting in the safety of their tomb
Sheltered by six feet of soil and rock
The spade is the key with which their gate we'll unlock

Why should they be resting so peacefully
When we're up above in pure misery
I don't care that they've already died
That's not enough to make me satisfied

So we wait till the stroke of the midnight hour
Then we'll unleash the darkest of power
Hell's gates will open a new judgment day
Now is the time that the dead will pay

Why should they be resting so peacefully
When we're up above in pure misery
I don't care that they've already died
That's not enough to make me satisfied

Waking the dead, waking the dead, waking the dead

All rise
Hell's gates open the earth trembles and shakes
Now their pardons are over they pray for their mistakes
Mausoleums firebombed now rage in flames
When the dead come out their bodies we'll maim

Rob, robbing their graves stealing their bones
Bang, banging our heads to their screams and their moans
Fix, fixing the wounds that even time cannot heal
Soon, soon we will know how good it feels

This is not damnation or an act of God
Now the dead they rise ripping through the sod
Purgatory has to wait, but how can this be
The dead are free, the dead are free

Waking the dead, you said that it wouldn't be
Waking the dead, you said that we wouldn't see
Waking the dead, now the dead stand before our own eyes

Silence is blaring the earth opens wide
History repeats, reburied they die
Darkness descends through nature's pores
They return to their sleep on earth's basement floor

Now they rest not so peacefully
As they've had a taste of our misery
I didn't care that they'd already died
That wasn't enough to make me satisfied

Return back to their tombs now they lay
This is no game for the novice to play
Repeat not a word lest ye be forewarned
The punishment of Hell's darkness and scorn

Repeat not a word of the sermon said
A prayer for the dead, don't play with the dead
Don't try to comprehend what's going on
You can't understand, please don't understand

Waking the dead, and we'll be
Waking the dead, all rise now
Waking the dead, we're gonna wake the dead
Waking the dead

I said the words, what have I done
I thought it cool, I thought it fun
The words I say they start to change
The syllables now rearranged

A language I can't comprehend
I shut my mouth, it doesn't end
The bowels of nature open wide
I cannot move, I cannot hide

I can't believe the things I see
The dead are free, the dead are free
I close my eyes and pray it's not real
Their presence close, coldness I feel

What have I done, Lord, please forgive
Once they died but now they live
I wake the dead, I wake the dead
I wake the dead, I wake the dead

Cleanse the lepers
Cast out the demons
Wake the dead
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
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,m,k,ar[1<<20],ps[1<<20];
long long ans;
long id;

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 ps[ar[i]]=i;
}

for (int i=1;i<=m;i++)
{
 cin>>id;
 ans+=(ps[id]-1)/k+1;
 long a=ps[id];
 long b=ps[id]-1;
 if (b==0)continue;
 swap(ar[a],ar[b]);
 ps[ar[a]]=a;
 ps[ar[b]]=b;
/* for (int j=1;j<=n;j++)
  cout<<ar[j]<<" ";
 cout<<endl;
 for (int j=1;j<=n;j++)
  cout<<ps[j]<<" ";
  cout<<endl;*/
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}