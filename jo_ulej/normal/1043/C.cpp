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

void inv(string& s, int l, int r)
{
	for(int i = l, j = r; i < j; ++i, --j)
		swap(s[i], s[j]);
}

int main(int argc, char** argv)
{
	int n;
	string str;
	vector<int> ans;

	cin >> str;
	n = str.size();
	ans.resize(n, 0);

	for(int i = 0; i < n - 1; ++i)
	{
		if(str[i] == 'b' && str[i + 1] == 'a')
		{
			int j = i + 1;

			while(j + 1 < n && str[j + 1] == 'a')
				++j;

			ans[i] = ans[j] = 1;

			inv(str, 0, i);
			inv(str, 0, j);
			++i;
		}
	}

	for(int i = 0; i < n; ++i)
		cout << ans[i] << " ";

	cout << endl;

	return 0;
}