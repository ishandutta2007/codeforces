/*
Sunrise showing every flaw
Paying for the nights before
Dark eyes, scanning every vein
Exploding cannot stand the strain

Standing on trial, scrutinize me
Questionize my strong denial
Bullet, bullet, bullet train
Piercing through my brain

Windows, illuminating stains
Breakdown closing in again
Free fall as I close my eyes
Voices talking many lies

Changing my course blurred and scorched
Breathing exhausts we distort
By gravity of such G-force
Bullet, bullet, bullet train
Piercing through my brain

Breakdown close my eyes
Voices talking many lies
Stained glass bursting in
Shattering my world again

Free fall never can
Ever reach the ground again
Dark eyes scanning in
Feel my mind explode within

Wanting much more implore you
Near to death's door to ignore
The screams of all
Who fall before

Bullet, bullet, bullet train
Piercing through my brain
Bullet, bullet, bullet train
Piercing through my brain

Bullet, bullet, bullet
Bullet, bullet, bullet
Bullet, bullet, bullet
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 300000;

using namespace std;

int n, k;
int ar[N];
int t[N];

long long ans;

int sum(int r)
{
	int res = 0;
	for (; r >= 0; r = (r&(r + 1)) - 1)
		res += t[r];
	return res;
}

void inc(int i, int delta)
{
	for (; i <= n; i = (i | (i + 1)))
		t[i] += delta;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		ar[i] = i;
	}

	for (int i = 1; i <= k; i++)
	{
		if (i < n - i + 1)
			swap(ar[i], ar[n - i + 1]);
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
	*/
	for (int i = n; i; --i)
	{
		ans += sum(ar[i]);
		inc(ar[i], 1);
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}