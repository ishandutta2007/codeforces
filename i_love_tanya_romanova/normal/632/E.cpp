/*
All along it was me who changed
Morning now waits for me
All along it was me who changed
Morning now waits
Morning now waits for me

What I have to gain
Does not matter
If what I give is all to You
If what I give is all to You

I have seen the stars fall
And the sun rise again
But You are yet to change

You are yet to change
You are all that is worth
You are all that is worth living for

What I have to gain
Does not matter
If what I give is all to You
If what I give is all to You

You are all that is worth living for
You are all that is worth living for
You are all that is worth living for
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
#define PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 1000010;

using namespace std;

int n, k;
vector<int> vec[20];
vector<int> ans;

typedef complex<double> base;

void fft(vector<base> & a, bool invert) {
	int n = (int)a.size();

	for (int i = 1, j = 0; i<n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i<n; i += len) {
			base w(1);
			for (int j = 0; j<len / 2; ++j) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
	for (int i = 0; i<n; ++i)
		a[i] /= n;

}

vector<int> mult(vector<int> a, vector<int> b) {
	//cout << a.size() << "%" << b.size() << endl;
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	size_t n = 1;
	while (n < max(a.size(), b.size()))  n <<= 1;
	n <<= 1;
	//cout << a.size() << " " << b.size() << endl;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	for (size_t i = 0; i<n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);

	vector<int> res;
	res.resize(n);
	for (size_t i = 0; i<n; ++i)
		res[i] = int(fa[i].real() + 0.5);
	return res;
}


vector<int> squ(vector<int> a) {
	vector<base> fa(a.begin(), a.end()), fb(a.begin(), a.end());
	size_t n = 1;
	while (n < a.size())  n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, false);
	fb = fa;
	for (size_t i = 0; i < n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);

	vector<int> res;
	res.resize(n);
	for (size_t i = 0; i < n; ++i)
		res[i] = int(fa[i].real() + 0.5);
	return res;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	
	vec[0].resize(1 << 10);

	for (int i = 0; i < vec[0].size(); i++)
		vec[0][i] = 0;

	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		vec[0][val] = 1;
	}

	for (int i = 1; i <= 9; i++)
	{
		vec[i] = squ(vec[i - 1]);
		while (vec[i].size() > (1 << 20))
			vec[i].pop_back();
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j]>1)
				vec[i][j] = 1;
		}
		//cout << i << "%" << vec[i].size() << endl;
	}

	vector<int> res;
	res.resize(1 << 10);
	for (int i = 0; i < res.size(); i++)
		res[i] = 0;
	res[0] = 1;

	for (int i = 0; i <= 9; ++i)
	{

//		cout << i << " "<<res.size()<<endl;
		if (k&(1 << i))
			res = mult(res, vec[i]);
		for (int j = 0; j<res.size(); j++)
		{
			if (res[j]>1)
				res[j] = 1;
		}
		while (res.size() > (1 << 20))
			res.pop_back();
	}

	for (int i = 0; i < res.size(); i++)
	{
		if (res[i])
			ans.push_back(i);
	}

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