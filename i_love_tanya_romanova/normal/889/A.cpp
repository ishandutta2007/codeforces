/*
Inner perception trapped in a soul cage
Human wreckage i leave my liquid face
Who am i sense blurred who's my mind
In this life obscured
Visual progressions leave me no peace
Subliminal merger clutch the
Fence of needs
What's there in desperation what's real
Flawless confusion

Void of emptyness reign my truth
Before my eyes flashes of youth
Memory-nuances pass where's my life
Frayed pictures mass
Insidious deception feelings fade
Reenous mirrors i praise the
Blackened day
What am i to reality what's in line
Subsequently

Forever turning through a lifetime
Endless burning of soul and mind
Step by step i'm taken through the past
To burn in fear of lies i'm lost mouldering
Oblivions grasp makes my soul burn
Burn

This astray mind has sieged my soul
Forever chained to this tearing cold
I'll never tell the truth from lies
Disbelief covers my eyes i'm lost mouldering
Perpetual pain in this soul burn

Pieces to me strange wrapped up disguise
Reflections of myself in another life

I see it vague before my eyes
Pictures drawn of naked bare lies
It makes no sense to live this mess
Constant until i find my rest
Enemy within a soul in flames
Gaining it's pulse breeding inside
Pressure increase drowns my belief
As i unveil myself in me
Burn
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int n,ans,have_pointer[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	ans=n;

	for (int i=1;i<=n;i++){
		int v;
		cin>>v;
		have_pointer[v]=1;
	}
	for (int i=1;i<=n;i++){
		if (have_pointer[i])
			--ans;
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}