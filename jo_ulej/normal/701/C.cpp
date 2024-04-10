#include <iostream>
#include <string>

using namespace std;

int n;
string str;
int count[100000][256];

int count_chr(int l, int r, char chr)
{
	if(r >= n)
		r = n - 1;

	if(l == 0)
		return count[r][chr];

	return count[r][chr] - count[l - 1][chr];
}

bool good(int l, int r)
{
	for(char c = 'a'; c <= 'z'; ++c)
		if(count_chr(0, n - 1, c) > 0 && count_chr(l, r, c) == 0)
			return false;

	for(char c = 'A'; c <= 'Z'; ++c)
			if(count_chr(0, n - 1, c) > 0 && count_chr(l, r, c) == 0)
				return false;

	// 4cout << "(" << l << "," << r <<") is good " << endl;

	return true;
}

int main(int argc, char** argv)
{
	cin >> n;
	cin >> str;

	for(char chr = 'a'; chr <= 'z'; ++chr)
		count[0][chr] = 0;

	for(char chr = 'A'; chr <= 'Z'; ++chr)
		count[0][chr] = 0;

	++count[0][str[0]];

	for(int i = 1; i < n; ++i)
	{
		for(char chr = 'a'; chr <= 'z'; ++chr)
			count[i][chr] = count[i - 1][chr];

		for(char chr = 'A'; chr <= 'Z'; ++chr)
			count[i][chr] = count[i - 1][chr];

		++count[i][str[i]];
	}

	int l = 0;
	int r = 0;
	int ans = n;

	while(l < n)
	{
		while(r < n && !good(l, r))
			++r;

		if(r >= n - 1 && !good(l, r))
			break;

		ans = min(ans, r - l + 1);

		++l;
		if(r < l)
			r = l;
	}

	cout << ans << endl;

	return 0;
}