#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	string s, t;

	cin >> s >> t;

	int j;
	for(j = 0; j < s.size() && j < t.size() && s[s.size() - 1 - j] == t[t.size() - 1 - j]; ++j);


	cout << s.size() + t.size() - 2 * j << endl;

	return 0;
}