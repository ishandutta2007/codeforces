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
	int w, h, k, ans = 0;
	cin >> w >> h >> k;

	while(w > 0 && h > 0 && k > 0)
	{
		 ans += 2 * (w + h) - 4;

		 w -= 4;
		 h -= 4;
		 --k;
	}

	cout << ans << endl;

	return 0;
}