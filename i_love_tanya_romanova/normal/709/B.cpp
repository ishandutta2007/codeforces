/*
We're gonna break these walls down
Come on baby
Let's bring them down
To the ground
Let's get outta here
Let's bring them down
No more fears
No more holding back
Let's be stronger
Than we were in the past
We're gonna break
These walls down
Come on, baby
Let's bring them down
We're tired of being held back
Captive by these walls and fear to tear them down
We're tired of being helpless
We're so weak, but as one we'll tear them down
You put it down
Breakin' free
Breakin' free
I'm so sick and tired
Tired of being held back
You hold it back
Breakin' free
Breakin' free
We're tired of being held back
Captive by these walls and fear to tear them down
We're tired, tired of being afraid
It will be hard
But we will keep trying till they fall
We're tired of being helpless
We're so weak, but as one
We'll tear them down
We're going to break these walls
We won't wait any more
Never been so strong before
Were gonna break these walls
We won't wait anymore
Never been so strong before
We are stronger
Today is the day
Beating harder
Today is the day
Breaking free
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

#define eps 1e-7
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n, a;
vector<int> v;
long long ans;

long long solve(vector<int> v)
{
	if (v[0] > a)
		return v.back() - a;
	if (v.back() < a)
		return a - v[0];
	return min((a - v[0]) * 2 + v.back() - a, (v.back() - a) * 2 + a - v[0]);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> a;
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}

	sort(v.begin(), v.end());

	int Q = v[0];
	v.erase(v.begin());
	ans = solve(v);
	v.insert(v.begin(), Q);
	v.pop_back();
	ans = min(ans, solve(v));
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}