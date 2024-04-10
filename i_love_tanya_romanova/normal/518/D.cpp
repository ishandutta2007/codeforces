/*
I scream at the sky, it's easier than crying
I'm shyest when I'm shouting out loud
I feel so alone in a room full of people
I'm loneliest when and I'm in a crowd

I'm alone and nobody hears me
Can't nobody heal me?
Won't nobody help me?

I'm alone, I just need someone to take my hand
And pick me up when I'm feeling down
Someone to take my heart and give it a home
Someone to be with me
And help me through the times when I'm down and lonely
Someone to be with me when I'm alone

Alone is the way I live
It's not the way I want it but you know you can't give in
Alone is the way I feel
It's so hard to understand why I've got to be alone

If you look in my heart you'd see it
That I'm trying to be something better
If you look in my heart you'd feel it
I've got to keep moving on

If you look in my heart you'd know it
I'm just trying to make my world better
If you look in my heart you'd see it
I got to do it alone

Well, I've been down, I've been down
I've been down, so down, so low
I've been lost, so lost with no place left to go
I've had emotions, emotions
That you better hope you never know
Sometimes it feels like I just can't take no more

If you look in my heart you'd see it
Well, I'm trying to be something better
If you look in my heart you'd feel it
I've got to keep moving on

If you look in my heart you'd know it
I'm just trying to make my world better
If you look in my heart you'd know it
I got to do it alone

Seems like things just keep getting further out of hand
Why can't for once things just go as I plan
How dare you, how dare you tell me that you understand
Let me tell you straight out there ain't nobody here that can

Well, I'm all alone, well, I'm so alone
To be alone now, just leave me alone
Well, I'm all alone, well so alone
To be alone, don't know why

If you look in my heart you'll see it
If you look in my heart you'd feel it
If you look in my heart you'd know it
I ain't trying to make no one bitter
I'm just alone, leave me alone
Alone alone, now leave me

I've lived in places that you wouldn't never ever want to be
Places where for a minute you couldn't ever stand to be
Well, I've seen things, I've seen things you'd never want to see
So what gives, what gives you the right to be the judge of me
I'm all alone, I'm so alone, to be alone, just leave me alone

A room full of people, can't nobody help me
Can't nobody help me
Well, I'm alone

Someone to take my hand
And pick me up when I'm feeling down
Someone to take my heart and give it a home
Someone to be with me
And help me through the times when I'm down and lonely
Someone to be with me when I'm alone

Alone is the way I live
It's not the way I want it but I know I can't give in
Alone is the way I feel
There ain't nothing quite as sad as a person that's alone
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

double p,ans,dp[2500][2500];
long n,t;

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>p>>t;
dp[0][0]=1;
for (int i=0;i<t;i++)
{
 for (int j=0;j<=n;j++)
 {
  if (j==n){dp[i+1][j]+=dp[i][j];continue;}
  dp[i+1][j+1]+=dp[i][j]*p;
  dp[i+1][j]+=dp[i][j]*(1.0-p);
 }
}
for (int i=0;i<=n;i++)
 ans+=dp[t][i]*i;

cout.precision(10);
cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}