/*
We all came out to Montreux
On the Lake Geneva shoreline
To make records with a mobile
We didn't have much time
Frank Zappa and the Mothers
Were at the best place around
But some stupid with a flare gun
Burned the place to the ground

Smoke on the water, a fire in the sky
Smoke on the water

They burned down the gambling house
It died with an awful sound
Funky Claude was running in and out
Pulling kids out the ground
When it all was over
We had to find another place
But Swiss time was running out
It seemed that we would lose the race

Smoke on the water, a fire in the sky
Smoke on the water

We ended up at the Grand Hotel
It was empty, cold and bare
But with the Rolling truck Stones thing just outside
Making our music there
With a few red lights, a few old beds
We made a place to sweat
No matter what we get out of this
I know, I know we'll never forget

Smoke on the water, a fire in the sky
Smoke on the water
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

const int N = 400031;

int ans,n;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<n;i++){
		int rem=n-i;
		if (rem%i==0)
			++ans;
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}