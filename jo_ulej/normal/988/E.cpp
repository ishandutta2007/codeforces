#include <iostream>
#include <string>
#include <algorithm>

int clear_zeros(std::string& s)
{
	if(s[1] != '0')
		return 0;

	int moves = 0;
	int pos = 1;

	while(s[pos] == '0')
	{
		pos++;

		if(pos >= s.size())
			return -1;
	}

	for(int i = pos; i > 1; --i)
	{
		std::swap(s[i], s[i - 1]);
		++moves;
	}

	return moves;
}

int move(std::string& s, char chr, int pos)
{
	if(s[pos] == chr)
		return 0;

	int moves = 0;

	int init_pos = -1;

	for(int i = 0; i < pos; ++i)
	{
		if(s[i] == chr)
			init_pos = i;
	}

	if(init_pos == -1)
		return -1;

	if(init_pos == 0)
	{
		int r = clear_zeros(s);

		if(r == -1)
			return -1;

		moves += r;
	}

	for(int i = init_pos; i < pos; ++i)
	{
		std::swap(s[i], s[i + 1]);
		++moves;
	}

	if(s[pos] != chr)
		return -1;

	return moves;
}

int solve(std::string s, const char* ending)
{
	int r, moves = 0;

	moves += (r = move(s, ending[1], s.size() - 1));

	if(r == -1)
		return -1;

	moves += (r = move(s, ending[0], s.size() - 2));

	if(r == -1)
		return -1;

	// std::cout << "s: " << s << " (" << ending << ")" << std::endl;
	// std::cout << "moves=" << moves << std::endl;

	return moves;
}

void update_ans(int& ans, int x)
{
	if(ans == -1 || (x < ans && x != -1))
		ans = x;
}

int main(int argc, char** argv)
{
	std::string s;
	std::cin >> s;

	int ans = -1;

	update_ans(ans, solve(s, "00"));
	update_ans(ans, solve(s, "25"));
	update_ans(ans, solve(s, "50"));
	update_ans(ans, solve(s, "75"));

	std::cout << ans << std::endl;

	return 0;
}