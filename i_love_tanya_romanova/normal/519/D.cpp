/*
Say it once, tell me twice
Are you certain I'm alright?
Just a sign, to remind me
Tomorrow's worth the fight
Ever changing the storyline that keeps me alive

So make a wish, and say...

Give me life, give me love
Scarlet angel from above
Not so low, not so high
Keep it perfectly disguised
Ever changing the storyline that keeps me alive

My Mona Lisa's making me smile
Right before my eyes!

Take another look
Take a look around
It's you and me
It's here and now
As you sparkle in the sky
I'll catch you while I can
Cause all we are is all I am
I just want you to see
What I've always believed
You are
The miracle in me

Show me faith, like you do
I'm amazed at how you move
Side to side, front to back
You know how to make it last
Ever changing the storyline that keeps us alive

My Mona Lisa's making me smile
Right before my eyes!

Take another look
Take a look around
It's you and me
It's here and now
As you sparkle in the sky
I'll catch you while I can
Cause all we are is all I am
I just want you to see
What I've always believed
You are
The miracle in me

These are the moments you can't pass back
Let's turn the water to wine
One more time!

Take another look
Take a look around
It's you and me
It's here and now
As you sparkle in the sky
I'll catch you while I can
Cause all we are is all I am
I just want you to see
What I've always believed
You are
The miracle in me
The miracle in me
You're the miracle in me
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
#define l 19

using namespace std;

string st;
long cost[1<<10];
long long s;
map<long long, long> mapp[100];
long long ans;

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<26;i++)
 cin>>cost[i];

cin>>st;
for (int i=1;i<=st.size();i++)
{
 long id=st[i-1]-'a';
 s=s+cost[id];
 ans+=mapp[id][s-cost[id]];
 mapp[id][s]++;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}