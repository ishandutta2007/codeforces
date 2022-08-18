/*
No one survives such an attack
We all stood like monuments baring the nails in her back
Still moving sinews
in a graceful impression of life
shyly the arms, shyly the breasts
fold, fear, die

Ten fingers driven through the heart, through the core
I stare into these strange, magnetic eyes
and wonder, wonder for you, wonder for me
are the demons there?

I knew it all the time:
The misanthropes were right
to crucify themselves in the need of a saviour.
Still moving sinews struggle fearsome with a lifeline forlorn,
caught in the nest of the impending dark fate.

Ten fingers driven through the heart, through the core
I stare into these strange, magnetic eyes
and wonder, wonder for you, wonder for me
are the demons there?

Semi-worlds, lifetight lodges
where our faces stiffen,
plagued with the frost of disease
Our capsules barely meet

The worms of disorder like living black numbers that drip from her pergament skin
Joined in sweet fury to anoint the decay fragile and reddened in lifelost array

Ten fingers driven through the heart, through the core
I stare into these strange, magnetic eyes
and wonder, wonder for you, wonder for me
are the demons there?

Joined in sweet fury to anoint the decay
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
#define right asdashgasrhsdf

#define eps 1e-14
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int k,a,b,ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>k>>a>>b;
	int f1=a/k;
	int f2=b/k;
	int rem1=a%k;
	int rem2=b%k;

	ans=f1+f2;
	if (1ll*f1*(k-1)<rem2||1ll*f2*(k-1)<rem1)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}