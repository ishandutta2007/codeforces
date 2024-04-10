#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int n, m, val;
	vector<int> seq;
	vector<bool> has;

	has.resize(10, false);

	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		cin >> val;

		seq.push_back(val);
	}

	for(int i = 0; i < m; ++i)
	{
		cin >> val;

		has[val] = true;
	}

	for(int i = 0; i < n; ++i)
	{
		if(has[seq[i]])
			cout << seq[i] << " ";
	}

	cout << endl;

	return 0;
}