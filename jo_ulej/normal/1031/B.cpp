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
	int n;
	vector<int> a, b;

	cin >> n;
	a.resize(n - 1);
	b.resize(n - 1);

	for(int i = 0; i < n - 1; ++i)
		cin >> a[i];

	for(int i = 0; i < n - 1; ++i)
		cin >> b[i];

	for(int i = 0; i < n - 1; ++i)
	{
		if(a[i] < b[i])
		{
			cout << "NO" << endl;

			return 0;
		}
	}

	for(int first_elem = 0; first_elem <= 3; ++first_elem)
	{
		vector<int> t;
		bool good;
		t.push_back(first_elem);

		for(int i = 0; i < n - 1; ++i)
		{
			good = false;

			for(int elem = 0; elem <= 3; ++elem)
			{
				if((t[i] | elem) == a[i] && (t[i] & elem) == b[i])
				{
					t.push_back(elem);
					good = true;

					break;
				}
			}

			if(!good)
			{
				break;
			}
		}

		if(good)
		{
			cout << "YES" << endl;

			for(int i = 0; i < n; ++i)
				cout << t[i] << " ";

			cout << endl;

			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}