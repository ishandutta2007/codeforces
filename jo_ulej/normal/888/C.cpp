#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define INF 1000*1000*1000

using namespace std;

int main(int argc, char** argv)
{
	vector<int> pos[26];
	string s;

	cin >> s;

	for(int i = 0; i < s.size(); ++i)
		pos[s[i] - 'a'].push_back(i);

	int ans = INF;

	for(int chr = 0; chr < 26; ++chr)
	{
		if(pos[chr].empty())
			continue;

		int k = max(pos[chr][0] + 1, (int)s.size() - pos[chr][pos[chr].size() - 1]);

		for(int i = 0; i + 1 < pos[chr].size(); ++i)
			k = max(k, pos[chr][i + 1] - pos[chr][i]);

		//cout << char('a' + chr) << " --> " << k << endl;

		ans = min(ans, k);
	}

	cout << ans << endl;

	return 0;
}