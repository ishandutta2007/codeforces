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
	vector<int> inv_a;

	cin >> n;
	inv_a.resize(n + 1);

	for(int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;

		inv_a[a] = i;
	}

	int idx = 0;

	for(int i = 1; i <=n; ++i)
	{
		int b;
		cin >> b;

		int j = inv_a[b];

		if(j > idx)
		{
			cout << j - idx << " ";
			idx = j;
		}
		else
		{
			cout << "0 ";
		}
	}

	return 0;
}