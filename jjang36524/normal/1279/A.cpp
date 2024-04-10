#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int T, N;
vector<string>s;
int main()
{
	cin >> T;
	while (T--)
	{
		int a, w, m;
		cin >> a >> w >> m;
		vector<int>cp = { a,w,m };
		sort(cp.begin(), cp.end());
		if (!(cp[2] > cp[1] + cp[0] + (a + w + m) % 2))
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
}