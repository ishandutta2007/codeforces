/*
Thermal count is rising
In perpetual writhing
The primordial ooze
And the sanity they lose

Awakened in the morning
To more air pollution warnings
Still we sleepwalk off to work
While our nervous systems jerk

Pretending not to notice
How history had forebode us
With the green house in effect
Our environment was wrecked

Now I can only laugh
As I read our epitaph
We end our lives as moles
In the dark of dawn patrol
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

const int N = 600031;

int n;

bool is_bad(int x){
	for (int i=0;i<=1000;i++){
		if (i*i==x)
			return false;
	}
	return true;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
//	cin.tie(0);

	int ans=-1e9;

	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		if (is_bad(x))
			ans=max(ans,x);
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}