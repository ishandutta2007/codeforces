/*
Today the warning came in the flood
Architects and fools never cared for poor men's blood
Cursed to repeat the past they are
The river dragon swims upstream
They've built another wall

The three will fall
Save us from the flood
Washed away we drown
Three will fall

The river dragon
Has come
Souls wash away
The earth has spoken and taken them to their graves

Those who cannot remember the last
Fall away, far away
The distance meets its task

The three will fall
Save us from the flood
Washed away we drown
Three will fall

The river dragon
Has come
Souls wash away
The earth has spoken and taken them to their graves
The river dragon has come
At first light of dawn
The earth has spoken
And in the crush they are gone

The three will fall
Save us from the flood
Washed away we drown
Three will fall

The river dragon
Has come
Souls wash away
The earth has spoken and taken them to their graves
In the mass destruction the bringer shows his form
Technology the beast
The seventh crown
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

const int N = 1100000;

using namespace std;

int n, a, b, T;
string st;
int rot[N];
int l, r;
int ans;

int best_span(int l, int r)
{
	if (l == n + 1)
		return r - (n + 1);
	if (r == n + 1)
		return n + 1 - l;

	return min(n + 1 - l + (r - l), r - (n + 1) + (r - l));
}

int need(int l, int r)
{
	int res = 0;
	res += (r - l + 1);
	//cout << l << "%" << r << endl;
	//cout << rot[r] - rot[l - 1] << endl;
	//cout << best_span(l, r) << endl;

	res += (rot[r] - rot[l - 1])*b;
	res += best_span(l, r)*a;
	//cout << res << endl;
	return res;
}

bool can_solve(int l, int r)
{
	return need(l, r) <= T;
}

int G(int a, int b)
{
	int res = b - a + 1;
	if (res > n)
		res = n;
	return res;
}

int main(){
	//	freopen("packing.in", "r", stdin);
	//	freopen("packing.out", "w", stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> a >> b >> T;

	cin >> st;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == 'w')
			rot[i+1] = 1;
		else
			rot[i+1] = 0;
	}

	for (int i = 1; i <= n; i++)
		rot[i + n] = rot[i];


	for (int i = 1; i <= n*2; i++)
	{
		rot[i] += rot[i - 1];
	}

	r = n + 1;
	l = n + 1;
	while (l>1&&can_solve(l-1,r))
	{
		--l;
	}

	for (int i = r; i <= n * 2; i++)
	{
		if (l > n + 1)
			break;
		//cout << i << "%" << l << endl;
		while (l <= n + 1 && can_solve(l, i) == 0)
			++l;
		if (l<=n+1)
			ans = max(ans, G(l,i));
	}
	
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}