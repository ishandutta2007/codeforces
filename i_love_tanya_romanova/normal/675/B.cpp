/*
Some way, some day, I'll find a way
To make you see my way

Even if you don't think like I do
You know that it's true
It's your mind that I seek

Tried so hard to make me think my point of view was bad
Although at times when you kept on I thought that I was mad

I'm glad it's goodbye
You don't have to ask why
Come back another day
Come back when you see my way
You see my way

Tried so hard to make me think my point of view was bad
Although at times when you kept on I thought that I was mad

Some way, some day, I'll find a way
To make you see my way

I'm glad it's goodbye
You don't have to ask why
Come back another day
Come back when you see my way
You see my way
You see my way
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
#define bs 100000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n, ar[N], mx, mn, s[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		cin >> ar[i];
	}

	swap(ar[3], ar[2]);

	int mx = 0;
	int mn = 0;
	for (int i = 0; i < 4; i++)
	{
		s[i] = ar[i] + ar[(i + 1) % 4];
	}
	for (int i = 0; i < 4; i++)
	{
		mx = max(mx, s[i] - s[0]);
		mn = min(mn, s[i] - s[0]);
	}
	
	int good = n - (mx - mn);
	if (good < 0)
		good = 0;
	long long ans = 1ll*good*n;
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}