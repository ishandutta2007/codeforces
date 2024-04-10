/*
I am not alone, I live with the memories
Regret is my home this is my true freedom
Express all the feelings of what I've become
I watch the rising sun, I hope I find some peace today

It seems I've gone away
It seems I've lost myself
It seems I've really lost my way
It seems I've lost myself
It seems I've

Shed my skin
Oh, are you ready for me?
Or purge my love
Oh, are you ready for me?

A bitter sinking feeling awake to the fact
There's no going back to this world in which I was living
I'm searching for something but found less than nothing
I watch the rising sun, I hope I find some peace today

It seems I've gone away
It seems I've lost myself
It seems I've really lost my way
It seems I've lost myself
It seems I've

Shed my skin
Oh, are you ready for me?
Or purge my love
Oh, are you ready for me?

Yeah, 'cause I'm dying to feel
What I have lost, oh, and what I was

All my life I've waited endless days have taken
Taken what made me free
Years have gone I'm broken left the past unspoken
Those years oh, they haunt me still

Shed my skin
Oh, are you ready for me?
Or purge my love
Oh, are you ready for me?
And shed my skin

All my life I've waited endless days have taken
What made me free
Years have gone I'm broken
Left the past unspoken
Those years they haunt me still
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
#define count adsgasdgasdg

using namespace std;

long n;
string st;
long ans;
long have[1000],worst[1000];
long need[1000];

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
for (int i=1;i<n;i++)
{
 char a,b;
 a=st[i*2-2];
 b=st[i*2-1];
 b=b-'A'+'a';
 have[a]++;
 need[b]++;
 worst[b]=max(worst[b],need[b]-have[b]);
}
ans=0;
for (int i='a';i<='z';i++)
 ans+=worst[i];
cout<<ans<<endl;

cin.get();cin.get();
return 0;}