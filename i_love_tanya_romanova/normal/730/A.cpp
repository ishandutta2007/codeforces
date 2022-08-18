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

const int N = 1000;

int n;
int mn;
int ar[N];
vector<pair<int, int> > order;

vector<vector<int> > ans;
int used[N];

int can_add(int id)
{
	for (int i = 0; i < ans.size(); i++)
	{
		int ok = 1;
		for (int j = 0; j < ans[i].size(); j++)
		{
			int to = ans[i][j];
			if (id == to)
				ok = 0;
		}
		if (ok == 1)
			return i;
	}
	return -1;
}

int main()
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);

	cin >> n;
	mn = 1e9;

	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		mn = min(mn, ar[i]);
	}
	
	while (true)
	{
		order.clear();
		for (int i = 1; i <= n; i++)
		{
			order.push_back(make_pair(ar[i], i));
		}
		sort(order.begin(), order.end());
		
		if (order[order.size() - 1].first == order[0].first)
		{
			break;
		}

		if (order[order.size() - 2].first == order[0].first&&order[order.size() - 1].first == order[0].first + 1 && ans.size() > 0&&can_add(order[order.size()-1].second)!=-1)
		{
			int id = order[order.size() - 1].second;
			int whr = can_add(id);
			ans[whr].push_back(id);
			ar[id]--;
			continue;
		}

		int id1 = order[order.size() - 2].second;
		int id2 = order[order.size() - 1].second;
		vector<int> temp;
		temp.push_back(id1);
		temp.push_back(id2);
		ans.push_back(temp);
		if (ar[id1])
			--ar[id1];
		if (ar[id2])
			--ar[id2];
	}

	cout << ar[1] << endl;
	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			used[j] = 0;
		}
		for (int j = 0; j < ans[i].size(); j++)
		{
			used[ans[i][j]] = 1;
		}

		for (int j = 1; j <= n; j++)
		{
			cout << used[j];
		}
		cout << endl;
	}

	return 0;
}