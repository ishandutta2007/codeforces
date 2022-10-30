#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>

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

template<typename T>
void read_vector(vector<T>& vec, int size)
{
	vec.resize(size);

	for(int i = 0; i < size; ++i)
		cin >> vec[i];
}

int main(int argc, char** argv)
{
	int n;
	vector<int> a, x;
	cin >> n;

	read_vector(a, n);
	a.insert(a.begin(), 0);
	x.resize(n);

	for(int i = 0; i < n; ++i)
		x[i] = a[i + 1] - a[i];

	vector<int> ans;

	for(int k = 1; k <= n; ++k)
	{
		bool good = true;

		for(int i = 0; i < n; ++i)
		{
			if(x[i] != x[i % k])
			{
				good = false;
				break;
			}
		}

		if(good)
			ans.push_back(k);
	}

	cout << ans.size() << endl;

	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";

	cout << endl;

	return 0;
}