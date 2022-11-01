#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>
#include <set>

#define INF 1e9
#define MAX_DIGITS 18

using namespace std;

typedef long long int ll;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
	cout << "[";

	for(int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i];

		if(i != vec.size() - 1)
			cout << ", ";
	}

	cout << "]";

	return os;
}

template<typename T>
T max3(T a, T b, T c)
{
	return max(max(a, b), c);
}

template<typename T>
T min3(T a, T b, T c)
{
	return min(min(a, b), c);
}

ll n, x, y, full_x = 0, full_y = 0;
string str;

bool check(ll k)
{
	ll res_x = 0, res_y = 0;

	for(int i = 0; i < k; ++i)
	{
		switch(str[i])
		{
			case 'R': ++res_x; break;
			case 'L': --res_x; break;
			case 'U': ++res_y; break;
			case 'D': --res_y; break;
		}
	}

	int x_wo = full_x - res_x;
	int y_wo = full_y - res_y;

	int d = abs(x - x_wo) + abs(y - y_wo);

	if(d <= k && k % 2 == d % 2)
		return true;

	for(int j = 0; j < n - k; ++j)
	{
		switch(str[j])
		{
			case 'R': --res_x; break;
			case 'L': ++res_x; break;
			case 'U': --res_y; break;
			case 'D': ++res_y; break;
		}

		switch(str[j + k])
		{
			case 'R': ++res_x; break;
			case 'L': --res_x; break;
			case 'U': ++res_y; break;
			case 'D': --res_y; break;
		}

		int x_wo = full_x - res_x;
		int y_wo = full_y - res_y;

		int d = abs(x - x_wo) + abs(y - y_wo);

		if(d <= k && k % 2 == d % 2)
			return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	cin >> n >> str >> x >> y;

	for(int i = 0; i < n; ++i)
	{
		switch(str[i])
		{
			case 'R': ++full_x; break;
			case 'L': --full_x; break;
			case 'U': ++full_y; break;
			case 'D': --full_y; break;
		}
	}

	if(x == full_x && y == full_y)
	{
		cout << "0" << endl;

		return 0;
	}

	if(!check(n))
	{
		cout << "-1" << endl;

		return 0;
	}

	int l = 0;
	int r = n;

	while(abs(l - r) > 1)
	{
		int m = (l + r) / 2;

		if(check(m))
			r = m;
		else
			l = m;
	}

	if(check(l))
		cout << l << endl;
	else
		cout << r << endl;

	return 0;
}