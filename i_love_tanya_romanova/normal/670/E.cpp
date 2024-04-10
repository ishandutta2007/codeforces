/*
Yeah, it's over now
But I can breathe somehow
When it's all worn out
I'd rather go without

You know its been on my mind
Could you stand right there
Look me straight in the eye and say
That it's over now

We pay our debt sometime

Well it's over now
Yet I can see somehow
When its all gone wrong
It's hard to be so strong

You know its been on my mind
Could you stand right there
Look me straight in the eye and say
That it's over now

We pay our debt sometime
We pay our debt sometime
We pay our debt sometime
We pay our debt sometime

Guess it's over now
I seem alive somehow
When it's out of sight
Just wait and do your time

You know its been on my mind
Could I stand right here
Look myself in the eye and say
That it's over now

We pay our debt sometime
Yeah, we pay our debt sometime
We pay our debt sometime
We pay our debt sometime
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
const int N = 610000;

vector<int> v;
int n, m, ps;
string st;
int paired[N];
int l[N], r[N];
string op;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m >> ps;
	
	cin >> st;

	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == '(')
		{
			v.push_back(i);
		}
		else
		{
			int q = v.back();
			v.pop_back();
			paired[q + 1] = i + 1;
			paired[i + 1] = q + 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		l[i] = i - 1;
		r[i] = i + 1;
	}

	l[n + 1] = n;
	r[0] = 1;

	cin >>op;

	for (int i = 0; i < op.size(); i++)
	{
	//	cout << "!" << ps <<" "<<l[ps]<<" "<<r[ps]<< endl;

		if (op[i] == 'L')
		{
			ps = l[ps];
			continue;
		}
		if (op[i] == 'R')
		{
			ps = r[ps];
			continue;
		}
		if (op[i] == 'D')
		{
			int ps1 = ps;
			int ps2 = paired[ps];
			if (ps1 > ps2)
				swap(ps1, ps2);
			r[l[ps1]] = r[ps2];
			l[r[ps2]] = l[ps1];
			if (r[ps2] != n + 1)
				ps = r[ps2];
			else
				ps = l[ps1];
			//cout << "@" << ps1 << " " << ps2 << endl;
		}
	}

	int cur = 0;
	while (true)
	{
		cur = r[cur];
		if (cur == n + 1)
			break;
		cout << st[cur-1];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}