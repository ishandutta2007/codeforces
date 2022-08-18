/*
Skull!

Ahhh, ahhh

They all know, they all know

Sorry, did I wake your dreams?
Some questions run too deep
We only, only wake up when we sleep

Led by the lunar light
Trouble's all we find
Lost our way tonight
(Way tonight, way tonight)

Is it something we said?
Is it something we said to them?
Is it something we said?

(Save me) I'm trapped in a vile world
(Save me) where the end game's all
the same as every other
We're only here to die

(Save me) I'm losing my only dream
(Save me) I can use some guiding light
Some place to go
Ya hear me let me know

(They) all know, they all know

Ever since the day you left
My fate's been set unknown
How many years
To walk this path alone?

So much to see tonight
So why'd you close your eyes?
Why can't I shut mine?
(I shut mine, shut mine, shut mine)

Is it something we did?
Is it something we did to them?
Is it something we did?

(Save me) I'm trapped in a vile world
(Save me) where the endings
are the same as every other
We're only here to die

(Save me) I'm losing my only dream
(Save me) I can use some guiding light
Some place to go
If you hear me let me know
If you hear me let me know

Ahhh

Help me find my way
Said help me find my way

No pulse inside of me
Stone cold lips and heresy
All lies into a degree
Losing who I wanna be

You'll find out, right now
He may be out of his mind
But someday you will find
That sanity's left us all blind
And dragged us all behind

A moment seen with those eyes
Crystal blue disguise
They say that all beauty must die
I say it just moves on

If you'd only open your mind
Then someday you will find
Insanity left us behind
And walk right through the (door)

I can see the picture's clear as yesterday
Pictures of my (own)
I can hear the voices begging you to stay
But know you're not alone

(Save me) I'm trapped in a vile world
(Save me) where the endings
are the same as every other
We're only here to die

(Save me) I'm losing my only dream
(Save me) I can use some guiding light
Some place to go
If you hear me let me know
If you hear me let me know

Tonight we all die young
Tonight we all die young
Tonight we all die young
Tonight we all die young
Tonight we all die young
Tonight we all die young

Tonight we all die
Tonight we all die young
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

string st;
string temp,bst;
set<string>v;

string rl(string st)
{
 char c=st[0];
 st[0]=st[1];
 st[1]=st[2];
 st[2]=st[3];
 st[3]=c;
 return st;
}

string ru(string st)
{
char temp=st[4];
 st[4]=st[0];
 st[0]=st[5];
 st[5]=st[2];
 st[2]=temp;
 return st;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
sort(st.begin(),st.end());
do
{
                          temp=st;
                          bst=temp;
                          for (int iter=1;iter<=2000;iter++)
                          {
                              if (rand()%2)temp=rl(temp);
                              else temp=ru(temp);
                              if (bst>temp)bst=temp;
                          }
                          v.insert(bst);
}
while (next_permutation(st.begin(),st.end()));

cout<<v.size()<<endl;

cin.get();cin.get();
return 0;}