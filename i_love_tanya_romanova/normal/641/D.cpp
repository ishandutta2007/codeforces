/*
Don't look around, I tell you what you will see
There's only dirt everywhere
Step with my feet in puddles of acid rain
I cannot bear
Running around in a polluted world - it's such a drag
Taking a breath of this toxic air - I'm frekin' out
Hiding behind these walls every day - upset my mind
Cannot believe, it's getting worse - no solution in sight
I'm so fuckin' bored, can't stand it
I can't think of things to do
Only I know it's no pleasure
Expectations won't come true
Sick of this, I don't wanna go out
Too many people, much too many around
Heat gets stronger - better leave a last sigh
Fear the future 'cause a nuclear plant won't last for long
Spit on those who tell me that it makes sense
and that I'm wrong
Running around in a polluted world it's such a drag
Taking a breath of this toxic air -
I'm frekin' out
I'm so fuckin' bored
This world is passing away
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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n;
long double ar1[N], ar2[N];
long double ans1[N], ans2[N], pref1[N], pref2[N], suf1[N], suf2[N];
long double res1, res2;
pair<long double, long double> ans[N];

pair<long double,long double> solve(long double a, long double b)
{
	if (fabs(a) < eps)
	{
		return make_pair(0, b);
	}

	//cout << a << "%" << b << endl;
	//x*y=a
	//x+y=b;
	//y=b-x
	//x*(b - x) = a;
	//x*b-x*x-a=0;
	//x*x-x*b+a=0
	//d=b*b-4*a
	long double D = b*b - 4 * a;
	if (D<0)
		D = 0;
	D = sqrt(D);
	long double X = b + D;
	X /= 2;
	long double Y = a / X;
	if (Y > X)
		swap(X, Y);
	return make_pair(X, Y);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar1[i];
	}
	for (int i = 1; i <= n; i++)
	{
				cin >> ar2[i];
		//scanf("%lf", &ar2[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		pref1[i] = pref1[i - 1] + ar1[i];
		pref2[i] = pref2[i - 1] + ar2[i];
	}

	for (int i = n; i; --i)
	{
		suf1[i] = suf1[i + 1] + ar1[i];
		suf2[i] = suf2[i + 1] + ar2[i];
	}

	for (int i = n; i; --i)
	{
		res1 = suf2[i];
		res2 = suf1[i] + suf2[i];
		//res2 += res1;

		ans[i] = solve(res1, res2);
	}

	for (int i = n; i; --i)
	{
		ans1[i] = ans[i].first - ans[i + 1].first;
		ans2[i] = ans[i].second - ans[i + 1].second;
	}

	cout.precision(10);

	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " ";
		//printf("%.10lf", ans1[i]);
				cout << fixed<<ans1[i];
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " "; //printf(" ");
		//printf("%.10lf", ans2[i]);
				cout << fixed << ans2[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}