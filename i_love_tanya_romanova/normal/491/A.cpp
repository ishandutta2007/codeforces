/*
Take my eyes the things I've seen in this world coming to an end
My reflection fades, I'm weary of these earthly bones and skin
You may pass through me and leave no trace, I have no mortal face
Solar winds are whispering, you may hear me call

We can shed our skins and swim into the darkened void beyond
We will dance among the world that orbit stars, they're on our side
All the oxygen that trapped us in a carbon spider's web
Solar winds are whispering, you may hear the sirens of the dead

Left the elders to their parley meant to satisfy our lust
Leaving Damocles still hanging over all their promised trust
Walk away from freedoms offered by their jailers in their cage
Step into the light startripping over mortals in their rage

Starblind - with sun
The stars are one
We are the light that brings the end of night

Starblind - with sun
The stars are one
We are, with the Goddess of the sun tonight

The preacher loses face with Christ
Religion's cruel device is gone
Empty flesh and hallowed bones
Make pacts of love but die alone

The crucible of pain will forge
The blanks of sin, begin again
You are free to choose a life to live
Or one that's left to lose

Virgins in the teeth of God are meat and drink to feed the damned
You may pass through me and I will feel the life that you live less
Step into my light startripping, we will rage against the night
Walk away from comfort offered by your citizens of death

Starblind - with sun
The stars are one
We are the light that brings the end of night

Starblind - with sun
The stars are one
We're one with the goddess of the sun tonight

Take my eyes for what I've seen
I will give my sight to you
You are free to choose whatever
Life to live or life to lose

Whatever God, you know
He knows you, better than you believe
In your once and future grave
You'll fall endlessly deceived

Look into our face reflected in the moon glow in your eyes
Remember you can choose to look but not to see and waste your hours
You believe you have the time but I tell you your time is short
See your past and future all the same and it cannot be bought

Starblind - with sun
The stars are one
We are the light that brings the end of night

Starblind - with sun
The stars are one
We're one with the Goddes of the sun tonight

Take my eyes for what I've seen
I will give my sight to you
You are free to choose whatever
Life to live or life to lose

Whatever God, you know
He knows you, better than you believe
In your once and future grave
You'll fall endlessly deceived

The preacher loses face with Christ
Religion's cruel device is gone
Empty flesh and hollow bones
Make pacts of love but die alone

The crucible of pain will forge
The blanks of sin, begin again
You are free to choose a life to live
Or one that's left to lose
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long a,b;
vector<long> ans;

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b;
for (int i=1;i<=a;i++)
{
 ans.push_back(i);
}
long n=a+b+1;
ans.push_back(n);
for (int i=1;i<=b;i++)
 ans.push_back(n-i);

for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}