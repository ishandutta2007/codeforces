/*
We're walking, the streets
We know where, we'll meet
Can't stop us
They don't know why
They try

Can't hurt us
We'll never die
We are on the march of the damned
Of the damned

March of the damned

We know what's, at stake
Won't take your, mistakes

Can't break us
We'll never fall
That's all

It's over, just watch us grow
We are on the march of the damned
Of the damned

March of the damned

We're walking the streets
We know where we'll meet

Can't stop us
They don't know why
They try

Can't hurt us
We'll never die
We are on the march of the damned
Of the damned

March of the damned
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
const int SZ = 300000;

int tests;
set<long long> bad;

long long pw[100];
string make_string(int val, int len)
{
	string res = "";
	for (int i = 0; i < len; i++)
	{
		res += char(val % 10 + 48);
		val /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

long long eval(string st)
{
	long long res = 0;
	for (int i = 0; i < st.size(); i++)
	{
		res = res * 10 + st[i] - 48;
	}
	return res;
}

long long first_good(string temp)
{
	for (int len = 0; len <= 9; len++)
	{
		for (int val = 0; val < pw[len]; val++)
		{
			string temp2 = make_string(val, len); 
			string cur = temp2 + temp;
			long long val2 = eval(cur);
			if (cur[0] == '0')
				continue;
			if (bad.find(val2) != bad.end())
				continue;
			if (val2 < 1989)
				continue;
			return val2;
		}
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	//cout << make_string(46, 3) << endl;

	pw[0] = 1;
	for (int i = 1; i <= 9; i++)
	{
		pw[i] = pw[i - 1] * 10;
	}

	cin >> tests;

	for (; tests; --tests)
	{
		string st;
		cin >> st;
		string need = "";
		for (int i = 4; i < st.size(); i++)
		{
			need += st[i];
		}

		bad.clear();

		for (int i = need.size() - 1; i>0; --i)
		{
			string temp = "";
			for (int j = i; j < need.size(); j++)
			{
				temp += need[j];
			}
			long long id = first_good(temp);
			bad.insert(id);
		}

		long long res = first_good(need);
		cout << res << endl;
	}

	cin.get(); cin.get();
	return 0;
}