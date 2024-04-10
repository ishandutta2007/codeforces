/*
On a long and lonesome highway east of Omaha
You can listen to the engines, moanin' out it's one old song
You can think about the woman, or the girl you knew the night before

But your thoughts will soon be wandering the way they always do
When you're riding sixteen hours and there's nothing much to do
You don't feel much like ridin', you just wish the trip was through

[Chorus:]
But here I am, on the road again
There I am, up on the stage
There I go, playing the star again
There I go, turn the page

You walk into a restaurant, strung out from the road
And you feel the eyes upon you, as you're shaking off the cold
You pretend it doesn't bother you, but you just want to explode
And most times you can't hear 'em talk, other times you can

All the same 'ole cliches: is it woman? Is it man?
And you always seem outnumbered, you dare not make a stand, make your stand.

[Chorus]

Out there in the spotlight, your a million miles away
Every ounce of energy, you try to give away
And the sweat pours out your body, like the music that you play
Later in the evening, as you lie awake in bed
With the echoes of the amplifiers, ringin' in your head
You smoke the days last cigarette, rememberin' what she said
What she said

[Chorus]

There I go, turn that page
There I go, yeah, there I go, yeah
There I go, yeah, Here I go
There I go, there I go

And I'm gone
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

long n,ar[1000000];
map<long, long> calc;
long fl;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    calc[ar[i]]++;
    if (calc[ar[i]]*2>n+1)fl=1;
}
if (fl)cout<<"NO"<<endl;
else cout<<"YES"<<endl;
cin.get();cin.get();
return 0;}