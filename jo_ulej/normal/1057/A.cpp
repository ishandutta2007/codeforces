#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long int ll;

int main(int argc, char** argv)
{
	int n;
	int p[200002];

	cin >> n;

	for(int i = 2; i <= n; ++i)
		cin >> p[i];

	vector<int> ans;
	ans.push_back(n);

	for(;;)
	{
		int last = ans[ans.size() - 1];

		if(last == 1)
			break;

		ans.push_back(p[last]);
	}

	reverse(ans.begin(), ans.end());

	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";

	return 0;
}