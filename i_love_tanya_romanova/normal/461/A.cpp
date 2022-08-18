/*
Don't remember where I was
I realized, life was a game
The more seriously I took things
The harder the rules became

I had no idea what it'd cost
My life passed before my eyes
I found out how little I accomplished
All my plans denied

So as you read this know my friends
I'd love to stay with you all
Smile when you think of me
My body's gone that's all

A tout le monde
A tous mes amis
Je vous aime
Je dois partir
These are the last words
I'll ever speak
And they'll set me free

If my heart was still alive
I know it would surely break
And my memories left with you
There's nothing more to say

Moving on is a simple thing
What it leaves behind is hard
You know the sleeping feel no more pain
And the living all are scarred

A tout le monde
A tous mes amis
Je vous aime
Je dois partir
These are the last words
I'll ever speak
And they'll set me free

So as you read this know my friends
I'd love to stay with you all
Please smile, smile when you think about me
My body's gone that's all

A tout le monde
A tous mes amis
Je vous aime
Je dois partir
These are the last words
I'll ever speak
And they'll set me free

A tout le monde
A tous mes amis
Je vous aime
Je dois partir
These are the last words
I'll ever speak
And they'll set me free
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
#define rmost agasdgasdg

using namespace std;

long long n,ar[500000],ans;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
 cin>>ar[i];

sort(ar,ar+n);
for (int i=0;i<n;i++)
{
 ans+=1ll*ar[i]*(i+1);
 if (i!=n-1)ans+=ar[i];
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}