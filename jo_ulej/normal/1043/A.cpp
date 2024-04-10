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
	int n, sum = 0, a_max = 0;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		a_max = max(a_max, temp);

		sum += temp;
	}

	cout << max((2 * sum) / n + 1, a_max) << endl;
	
	return 0;
}