/*
Join in my quest to leave life overturned
Spanning the world wave of doom
Spewing out death with the evil I've churned
Awaken the dead from their tombs
Love turns to lust the sensations I've felt
Exploring the pleasures of sin
Making the best of the cards I've been dealth
Adjusting the odds so I win

Unleash all my burning wrath
Potential killing machine
Take down all who block my path
Enjoying all that's obscene... born of fire

Prince of all darkness initiation
Ritually baptized in flames
Next to the throne my abomination
Spreads horror throughout the domain
Master the art that controls the impure
Inherit the infamous keys
Thousands of centuries I will endure
Tyrant of all the prophecies

Some have called me Satan's son
A name I cannot deny
Wielding fury that's second to none
Far to vile to confine... born of fire

All things dead must rise again
When twilight's blanket falls
Splattered red you'll find my den
Blood dripping from the walls

Dreams born of desire
Shaped and forged within the fire
Twisted, warped, deranged I see
The world's corrupt insanity

Dreams possess nightmarish figures
Burning can't escape the embers
Lost are those who trust the Liar
Satan's son I'm born of fire
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007

#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 1200031;

int n,ans,cnt[N];
int cur;

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n*2;i++)
	{
		int val;
		cin>>val;
		if (cnt[val]==1)
		{
			--cur;
			cnt[val]=0;
		}
		else
		{
			cnt[val]++;
			++cur;
		}
		ans=max(ans,cur);
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}