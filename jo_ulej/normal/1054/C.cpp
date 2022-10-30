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

int main(int argc, char** argv)
{
	int n, max_elem;
	vector<int> l, r, arr;

	cin >> n;
	l.resize(n);
	r.resize(n);
	arr.resize(n, -1);

	max_elem = n;

	for(int i = 0; i < n; ++i)
		cin >> l[i];

	for(int i = 0; i < n; ++i)
		cin >> r[i];

	for(int i = 0; i < n; ++i)
		arr[i] = n - l[i] - r[i];

	for(int i = 0; i < n; ++i)
	{
		if(arr[i] <= 0)
		{
			cout << "NO" << endl;

			return 0;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		int real_l = 0, real_r = 0;

		for(int j = 0; j < i; ++j)
		{
			if(arr[j] > arr[i])
				++real_l;
		}

		for(int j = i + 1; j < n; ++j)
		{
			if(arr[j] > arr[i])
				++real_r;
		}

		if(real_l != l[i] || real_r != r[i])
		{
			cout << "NO" << endl;

			return 0;
		}
	}

	cout << "YES" << endl;

	for(int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	cout << endl;

	return 0;
}