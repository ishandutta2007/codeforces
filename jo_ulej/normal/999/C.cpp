#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
	int n, k;
	string s;
	vector<int> pos[26];

	cin.tie(0);
	cin >> n >> k >> s;

	for(int i = 0; i < n; ++i)
		pos[s[i] - 'a'].push_back(i);

	for(int j = 0; j < 26 && k > 0; ++j)
	{
		if(pos[j].size() <= k)
		{
			k -= pos[j].size();

			pos[j].clear();
		}
		else if(!pos[j].empty())
		{
			pos[j].erase(pos[j].begin(), pos[j].begin() + k);

			k  = 0;
		}
	}

	std::fill(s.begin(), s.end(), '*');

	for(int j = 0; j < 26; ++j)
	{
		for(int i = 0; i < pos[j].size(); ++i)
			s[pos[j][i]] = 'a' + j;
	}

	for(int i = 0; i < n; ++i)
		if(s[i] != '*')
			cout << s[i];

	cout << endl;

	return 0;
}