/*
Endless mornings cut by the dawn razor
Whipping the nightmares to a froth
Endless questions with no answers
No replacement for what's been lost

Lost

Everything suffocates in the dust of past fortunes squandered
The empire of lies to whom you pandered
Suffer a self-imposed exile, taste the bitter fruits of denial
In the presence of greatness the humble can only bow

Frost on the breath of life
Empty of warmth or light
Full of nothing but deprivation
Frost on the breath of life
Empty of warmth or light
Caught in eternal winter

Tell me a lie with the best of intentions
Mute in the age of mass communication
Dark days lead to darker nights
Frozen, out of time.
It dies for blessed ego, the once mighty laid low

Frost on the breath of life
Empty of warmth or light
Full of nothing but deprivation
Full of nothing but deprivation, eternal winter
Full of nothing but deprivation, eternal winter

You taught me hate, I'll teach you fear
Open the eyes, kill despair
You cannot squeeze the life from me
Son of a bitch, I'm going to break you
Son of a bitch, I'm going to break you
Break you
I'm going to break you
Break you
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
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n,ans,ar[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		if (i>=3&&ar[i]==1&&ar[i-1]==0&&ar[i-2]==1){
			++ans;
			ar[i]=0;
		}
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}