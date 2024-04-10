/*
Pandemonium all around
Can't you fell it coming down
Pandemonium in my brain
Over and over and over again
Over and over and over again
Over and over and over again
Over and over and over again

And now you know the answer
And now you see the truth
Swallow this bitter pill
As all religion dies for you
and all the things that happened
In all those times long gone
Gave birth to life like lies
Apocalyptic pandemonium
Pandemonium

Pandemonium in the air
god has left us in despair
Desperate could not stand the pain
Over and over and over again
Over and over and over again
Over and over and over again
Over and over and over again

Now that your world is buring
Now that it ends in tears
Inferno has arrived
Nothing can make it disappear
And all the things that happened
In all those times long gone
Gave birth to life likes lies
Apocalyptic pandemonium
Pandemonium

A psychodrama is dragging you
Out of a life surreal
A better future waits for you
A life that might have been
So give your soul and you may live
Limitless fantasies
This celebration of the night
Can light your shattered life
If you believe...
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 210000;

using namespace std;

int n;
int len;
int ar[N];
vector<int> vals;
long long ans;
vector<int> uv;
map<int, int> mapp;
int k;

long long cnt_plus[N * 4], cnt_minus[N * 4], sum_plus[N * 4], sum_minus[N * 4];
long long sum;
int sz;

void compress()
{
	sort(vals.begin(), vals.end());
	for (int i = 0; i < vals.size(); i++)
	{
		if (i>0 && vals[i] == vals[i - 1])
			continue;
		uv.push_back(vals[i]);
		mapp[vals[i]] = uv.size();
		++sz;
	}
}

void combine(int v)
{
	cnt_plus[v] = cnt_plus[v * 2] + cnt_plus[v * 2 + 1];
	cnt_minus[v] = cnt_minus[v * 2] + cnt_minus[v * 2 + 1];
	sum_plus[v] = sum_plus[v * 2] + sum_plus[v * 2 + 1];
	sum_minus[v] = sum_minus[v * 2] + sum_minus[v * 2 + 1];
}

void add(int v, int tl, int tr, int ps, int val, int am)
{
	if (tl == tr)
	{
		if (val > 0&&am>0||val<0&&am<0||val==0)
			cnt_plus[v] += am,
			sum_plus[v] += val;
		else
			cnt_minus[v] += am,
			sum_minus[v] += val;
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	if (ps <= tm)
		add(v * 2, tl, tm, ps, val, am);
	else
		add(v * 2 + 1, tm + 1, tr, ps, val, am);
	combine(v);
}

void add_element(int val)
{
	add(1, 1, sz, mapp[val], val,1);
	sum += val;
}

void remove_element(int val)
{
	add(1, 1, sz, mapp[val], -val, -1);
	sum -= val;
}

long long get1(int v, int tl, int tr, int am)
{
	if (am == 0||cnt_plus[v]==0)
		return 0;
//	cout << v << " " << tl << " " << tr << " " << am << endl;

	if (tl == tr)
	{
		if (am >= cnt_plus[v])
			return sum_plus[v];
		return sum_plus[v] / cnt_plus[v] * am;
	}

	int tm = tl + tr;
	tm /= 2;
	if (am <= cnt_plus[v * 2 + 1])
		return get1(v * 2 + 1, tm + 1, tr, am);
	return sum_plus[v * 2 + 1] + get1(v * 2, tl, tm, am - cnt_plus[v * 2 + 1]);
}

long long get2(int v, int tl, int tr, int am)
{
	if (am == 0||cnt_minus[v]==0)
		return 0;
//	cout << v << " " << tl << " " << tr << " " << am << endl;

	if (tl == tr)
	{
		if (cnt_minus[v] <= am)
			return sum_minus[v];
		else
			return sum_minus[v] / cnt_minus[v] * am;
	}

	int tm = tl + tr;
	tm /= 2;
	if (am <= cnt_minus[v * 2])
		return get2(v * 2, tl, tm, am);
	return sum_minus[v * 2] + get2(v * 2 + 1, tm + 1, tr, am - cnt_minus[v * 2]);
}

long long eval()
{
	long long val1 = get1(1, 1, sz, k);
	long long val2 = get2(1, 1, sz, k);
	//cout << sum << " " << val1 << " " << val2 << endl;

	pair<long long, long long> P = make_pair(val1, val2);
	long long res = abs(sum);
	res = max(res, abs(sum - P.first * 2));
	res = max(res, abs(sum - P.second * 2));
	return res;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> len;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
		vals.push_back(ar[i]);
	}

	compress();

	cin >> k;
	for (int i = 0; i < len; i++)
	{
		add_element(ar[i]);
	}
	//cout << "!" << endl;

	ans = eval();
	//cout << "@" << endl;

	for (int i = len; i < n; i++)
	{
		add_element(ar[i]);
		remove_element(ar[i - len]);
		ans = max(ans, eval());
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}