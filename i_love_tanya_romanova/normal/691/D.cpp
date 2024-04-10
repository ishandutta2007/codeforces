/*
Don't even think about reachin' me
'Cause I won't be home
Don't even think about stoppin' by
Don't think of me at all

I did, what I had to do
And if there was a reason, it was you

Don't even think about gettin' inside
Voices in my head, voices
I got scratches, all over my arms
One for each day, since I fell apart

I did, what I had to do
And if there was a reason, it was you, oh

Footsteps in the hole, it was you, you
Oh oh
Pictures on my chest, it was you, it was you

I did, what I had to do and if there was a reason
There wasn't no reason, no
And if, there's something you'd like to do
Oh just let me continue, to blame you, oh oh

Footsteps in the hole, it was you, you
Oh oh
Pictures on my chest, it was you, it was you
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 1000031;

int n, k, ar[N];
vector<int> vec[N];
int w[N];

int get(int x)
{
	if (w[x] == x)
		return x;
	return w[x] = get(w[x]);
}

void merge(int a, int b)
{
	a = get(a);
	b = get(b);
	w[a] = b;
}

int ans[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	for (int i = 1; i <= n; i++)
		w[i] = i;

	for (int i = 1; i <= k; i++)
	{
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	for (int i = 1; i <= n; i++)
	{
		int id = get(i);
		vec[id].push_back(ar[i]);
	}

	for (int i = 1; i <= n; i++)
		sort(vec[i].begin(), vec[i].end());

	for (int i = 1; i <= n; i++)
	{
		int id = get(i);
		int val = vec[id].back();
		vec[id].pop_back();
		ans[i] = val;
	}

	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}