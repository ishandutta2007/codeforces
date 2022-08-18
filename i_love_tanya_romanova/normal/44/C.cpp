/*
Never feared for anything
Never shamed but never free
A laugh that healed the broken heart
With all that it could

Lived the life so endlessly
Saw beyond what others see
I tried to heal your broken heart
With all that I could
Will you stay?
Will you stay away forever?

How do I live without the ones I love?
Time still turns the pages of the book it's burned
Place and time always on my mind
I have so much to say but you're so far away

Plans of what our futures hold
Foolish lies of growing old
It seems we're so invincible
The truth is so cold

A final song, a last request
A perfect chapter laid to rest
Now and then I try to find
A place in my mind
Where you can stay
You can stay away forever

How do I live without the ones I love?
Time still turns the pages of the book it's burned
Place and time always on my mind
I have so much to say but you're so far away

Sleep tight I'm not afraid (not afraid)
The ones that we love are here with me
Lay away a place for me (place for me)
'Cause as soon as I'm done I'll be on my way
To live eternally

How do I live without the ones I love?
Time still turns the pages of the book it's burned
Place and time always on my mind
And the light you left remains but it's so hard to stay
When I have so much to say and you're so far away

I love you, you were ready
The pain is strong and urges rise
But I'll see you, when He lets me
Your pain is gone, your hands untied

So far away (so close)
And I need you to know
So far away (so close)
And I need you to, need you to know
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
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
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

long n,m,a,b,calc[1000],ans;

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{cin>>a>>b;
for (int j=a;j<=b;j++)calc[j]++;}

ans=n+1;
for (long i=1;i<=n;i++)
if (calc[i]!=1)ans=min(ans,i);
if (ans>n)cout<<"OK"<<endl;
else cout<<ans<<" "<<calc[ans]<<endl;

cin.get();cin.get();
return 0;}