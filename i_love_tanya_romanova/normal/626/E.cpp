/*
I could be mean
I could be angry
You know I could be just like you

I could be fake
I could be stupid
You know I could be just like you

You thought you were standing beside me
You were only in my way
You're wrong if you think that I'll be just like you
You thought you were there to guide me
You were only in my way
You're wrong if you think that I'll be
Just like you

I could be cold
I could be ruthless
You know I could be just like you

I could be weak
I could be senseless
You know I could be just like you

You thought you were standing beside me
You were only in my way
You're wrong if you think that I'll be just like you
You thought you were there to guide me
You were only in my way
You're wrong if you think that I'll be
Just like you

On my own, cause I can't take livin' with you
I'm alone, so I won't turn out like
You want me to

You thought you were standing beside me
You were only in my way
You're wrong if you think that I'll be just like you
You thought you were there to guide me
You were only in my way
You're wrong if you think that I'll be
Just like you

I could be mean
I could be angry
You know I could be just like you
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 220000;

using namespace std;

int n;
int ar[N];
long long s[N];
int ans_type;
int ans_center;
int ans_span;

// odd, l short r long
long double eval1(int center, int span)
{
	int elements = span * 2 + 1;
	long long sum = s[center + 1] - s[center - span];
	sum += s[n] - s[n - span];
	return sum *1.0 / elements;
}

// even, l short r long
long double eval2(int center, int span)
{
	int elements = span * 2 + 2;
	long long sum = s[center + 2] - s[center - span];
	sum += s[n] - s[n - span];
	return sum*1.0 / elements;
}

// odd, l long r short
long double eval3(int center, int span)
{
	int elements = span * 2 + 1;
	long long sum = s[center + 1 + span] - s[center];
	sum += s[span];
	return sum*1.0 / elements;
}

// even, l long r short
long double eval4(int center, int span)
{
	int elements = span * 2 + 2;
	long long sum = s[center + 2 + span] - s[center];
	sum += s[span];
	return sum*1.0 / elements;
}

vector<int> ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}

	sort(ar, ar + n);

	long double best_ans = -1;

	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + ar[i - 1];

	// single center
	for (int i = 0; i < n; i++)
	{
		int l, r;
		l = 0;
		r = min(i, n - i - 1);
		while (l < r - 5)
		{
			int mid1 = l * 2 + r;
			int mid2 = l + 2 * r;
			mid1 /= 3;
			mid2 /= 3;
			long double res1 = eval1(i, mid1) - ar[i];
			long double res2 = eval1(i, mid2) - ar[i];
			if (res1 < res2)
			{
				l = mid1;
			}
			else
			{
				r = mid2;
			}
		}
		for (int j = l; j <= r; j++)
		{
			long double here = eval1(i, j) - ar[i];
			if (here > best_ans)
			{
				best_ans = here;
				ans_type = 1;
				ans_center = i;
				ans_span = j;
			}
		}
	}

	// two centers

	for (int i = 0; i + 1 < n; i++)
	{
		int l, r;
		l = 0;
		long double hr = .0 + ar[i] + ar[i + 1];
		hr /= 2;
		r = min(i, n - i - 2);
		while (l + 5 < r)
		{
			int mid1 = l * 2 + r;
			int mid2 = l + 2 * r;
			mid1 /= 3;
			mid2 /= 3;
			long double res1 = eval2(i, mid1) - hr;
			long double res2 = eval2(i, mid2) - hr;
			if (res1 < res2)
			{
				l = mid1;
			}
			else
			{
				r = mid2;
			}
		}

		for (int j = l; j <= r; j++)
		{
			long double here = eval2(i, j) - hr;
			if (here > best_ans)
			{
				best_ans = here;
				ans_type = 2;
				ans_center = i;
				ans_span = j;
			}
		}
	}


	// cpy paste, reverse

	// single center
	for (int i = 0; i < n; i++)
	{
		int l, r;
		l = 0;
		r = min(i, n - i - 1);
		while (l < r - 5)
		{
			int mid1 = l * 2 + r;
			int mid2 = l + 2 * r;
			mid1 /= 3;
			mid2 /= 3;
			long double res1 = eval3(i, mid1) - ar[i];
			long double res2 = eval3(i, mid2) - ar[i];
			if (res1 < res2)
			{
				l = mid1;
			}
			else
			{
				r = mid2;
			}
		}
		for (int j = l; j <= r; j++)
		{
			long double here = eval3(i, j) - ar[i];
			if (here > best_ans)
			{
				best_ans = here;
				ans_type = 3;
				ans_center = i;
				ans_span = j;
			}
		}
	}

	// two centers

	for (int i = 0; i + 1 < n; i++)
	{
		int l, r;
		l = 0;
		r = min(i, n - i - 2);
		long double hr = ar[i] + ar[i + 1];
		hr /= 2;
		while (l + 5 < r)
		{
			int mid1 = l * 2 + r;
			int mid2 = l + 2 * r;
			mid1 /= 3;
			mid2 /= 3;
			long double res1 = eval4(i, mid1) - hr;
			long double res2 =	eval4(i, mid2) - hr;
			if (res1 < res2)
			{
				l = mid1;
			}
			else
			{
				r = mid2;
			}
		}

		for (int j = l; j <= r; j++)
		{
			long double here = eval4(i, j) - hr;
			if (here > best_ans)
			{
				best_ans = here;
				ans_type = 4;
				ans_center = i;
				ans_span = j;
			}
		}
	}

	//	cout << best_ans << " " << ans_type << " " << ans_center << " " << ans_span << endl;

	if (ans_type == 1)
	{
		for (int i = ans_center - ans_span; i <= ans_center; i++)
		{
			ans.push_back(ar[i]);
		}
		for (int i = n - 1; i >= n - ans_span; i--)
			ans.push_back(ar[i]);
	}

	if (ans_type == 2)
	{

		for (int i = ans_center - ans_span; i <= ans_center + 1; i++)
		{
			ans.push_back(ar[i]);
		}
		for (int i = n - 1; i >= n - ans_span; i--)
			ans.push_back(ar[i]);
	}


	if (ans_type == 3)
	{
		for (int i = ans_center; i <= ans_center + ans_span; i++)
		{
			ans.push_back(ar[i]);
		}
		for (int i = 0; i < ans_span; i++)
			ans.push_back(ar[i]);
	}

	if (ans_type == 4)
	{
		for (int i = ans_center; i <= ans_center + ans_span + 1; i++)
		{
			ans.push_back(ar[i]);
		}
		for (int i = 0; i < ans_span; i++)
			ans.push_back(ar[i]);
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}