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

int n,ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	ans=1e9;

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int j=n/i+(n%i>0);
		ans=min(ans,2*(i+j));
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}