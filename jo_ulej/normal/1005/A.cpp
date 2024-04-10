#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	vector<int> input, ans;
	cin >> n;

	input.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> input[i];

	for(int i = 0; i < n; ++i)
	{
		if(i == n - 1 || input[i + 1] == 1)
			ans.push_back(input[i]);
	}

	cout << ans.size() << endl;

	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";

	cout << endl;

	return 0;
}