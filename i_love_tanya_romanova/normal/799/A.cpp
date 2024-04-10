/*
The time has come, I am leaving now
Destination: sunken world of gold
I've been dreaming every night
And finally I'm on my way

Never gonna let it go
Always gonna keep the dream alive
Nothing's gonna change my mind
I know I'm gonna find the way this time

I'll see Atlantis rising
I burn my bridges, no return
I'll see Atlantis rising

Defy the storm, I make my way
To where I believe the treasure lies
I'll find the place that I was told
Is where the oceans took it down below

Never gonna let it go
Always gonna keep the dream alive
Nothing's gonna change my mind
I know I'm gonna find the way this time

I'll see Atlantis rising
I burn my bridges, no return
I'll see Atlantis rising

All my life I've had this feeling
That I'm not really home
And it feels like I'm lost forever

I've be dreaming with the shadows of the night
I've been singing to the angels of the lonely wind of the light
They've been telling me to leave it be
But I am closer to the waters where the gold will be one with my eyes

The horizon is telling me that I am near
That my journey is soon to end and my life is soon to begin
I am waiting for the night to come
When the lost world will resurface
When the dawn light the sparks in the sky

I hear the roar the surface come alive out here
Unruly waves caresses my tear-filled face
I can't believe it's true, this can't be happening to me
I never though I'd live to see this miracle right before my eyes

I find it hard to realize
That my dream would finally come true
I'm reaching out, I can touch the ground
Of my resurrected paradise

I am walking on the streets of gold
I can feel the magic in the air
Now the ground begins to shake again
I feel we're sinking but I stay right here

I saw Atlantis rising
I'm going down, there's no return
I saw Atlantis rising

I saw Atlantis rising
I fade away I let the waters feed my soul
I saw Atlantis rising
I am finally home again
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,t,k,d,ANS2;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>t>>k>>d;

	int ANS1=1e9;

	int s=0;

	for (int i=1;;i++)
	{
		if (i%t==0)
			s+=k;
		if (s>=n)
		{
			ANS1=i;
			break;
		}
	}

	s=0;
	for (int i=1;;i++)
	{
		if (i%t==0)
			s+=k;
		if (i>d&&(i-d)%t==0)
			s+=k;
		if (s>=n)
		{
			ANS2=i;
			break;
		}
	}

	if (ANS1!=ANS2)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}