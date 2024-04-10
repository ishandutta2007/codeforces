#pragma comment(linker, "/STACK:36777216")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>

#include <unordered_map>

using namespace std;

#ifdef LOCAL
#define debug_flag 1
#else
#define debug_flag 0
#endif

template <class T1, class T2 >
std::ostream& operator << (std::ostream& os, const pair<T1, T2> &p)
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	bool first = true;
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<vector<T>>& v)
{

	os << "[" << endl;
	bool first = true;
	for (typename std::vector<vector<T>>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		os << *it << endl;
	}
	os << "]" << endl;
	return os;
}

int tests;
vector<int> upper, lower;
int n;

int main()
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	cin >> tests;
	for (; tests; --tests)
	{
		cin >> n;

		if (n == 1)
		{
			cout << "! 1 1" << endl;
			continue;
		}

		upper.clear();
		lower.clear();
		for (int i = 1; i + 1 <= n; i += 2)
		{
			cout << "? " << i << " " << i + 1 << endl;
			string st;
			cin >> st;
			if (st == "<")
			{
				upper.push_back(i + 1);
				lower.push_back(i);
			}
			else
			{
				lower.push_back(i + 1);
				upper.push_back(i);
			}
		}

		int cur_min = lower[0];
		int cur_max = upper[0];
		for (int i = 1; i < lower.size(); i++)
		{
			cout << "? " << lower[i] << " " << cur_min << endl;
			string st;
			cin >> st;
			if (st == "<")
				cur_min = lower[i];
		}
		for (int i = 1; i < upper.size(); i++)
		{
			cout << "? " << upper[i] << " " << cur_max << endl;
			string st;
			cin >> st;
			if (st == ">")
				cur_max = upper[i];
		}

		if (n % 2)
		{
			cout << "? " << n << " " << cur_min << endl;
			string st;
			cin >> st;
			if (st == "<")
				cur_min = n;

			cout << "? " << n << " " << cur_max << endl;
			cin >> st;
			if (st == ">")
				cur_max = n;
		}

		cout << "! " << cur_min << " " << cur_max << endl;
	}

	return 0;
}