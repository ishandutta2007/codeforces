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
	set<int> possible;
	vector<int> arr;
	int n;

	possible.insert(0);

	cin >> n;
	arr.resize(n + 1);

	for(int i = 1; i <= n; ++i)
		cin >> arr[i];

	for(int idx = 1; idx <= n; ++idx)
	{
		if(possible.find(arr[idx]) == possible.end())
		{
			cout << idx << endl;

			return 0;
		}

		possible.insert(arr[idx] + 1);
	}

	cout << "-1" << endl;

	return 0;
}