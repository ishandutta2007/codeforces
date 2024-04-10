/*
My reality, flawed you oppress me
Immortality whored by God as the claws are left in me

My insanity, fallen dignity
Whored by God as were drenched in slavery

Peeling skin flesh from bone
Dealing sin, none shall roam

See the righteous fall at the rise of the damned, denied
See others crawl in the hour demand and fight

Unto deadly sin I fall
Praise to deadly sin!

My reality, flawed you oppress me
Immortality, whored by God as the claws are left in me

Peeling skin flesh from bone
Dealing sin, none shall roam

See the righteous fall as the rise of the damned, denied.
See others crawl to the towers of rancid spite

To the deadly king I fall
To the deadly king!
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 500031;

int n,ar[N];
int s;
int done[N];
int memo[N];

int solve(int ps)
{
	if (done[ps])
		return memo[ps];
	done[ps]=1;
	if (ps==n)
		return 0;
	int best_score=-1e9;
	best_score=ar[ps]-solve(ps+1);
	best_score=max(best_score,solve(ps+1)-ar[ps]);
	memo[ps]=best_score;
	return best_score;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
		s+=ar[i];
	}
//	sort(ar,ar+n);

	int bst=solve(0);

	int A=s-bst;
	A/=2;
	int B=s-A;

	cout<<A<<" "<<B<<endl;

	cin.get(); cin.get();
	return 0;
}