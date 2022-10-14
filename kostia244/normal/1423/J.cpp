#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

namespace IO
{
	const int BUFFER_SIZE = 1 << 15;

	char input_buffer[BUFFER_SIZE];
	int input_pos = 0, input_len = 0;

	char output_buffer[BUFFER_SIZE];
	int output_pos = 0;

	char number_buffer[100];
	uint8_t lookup[100];

	void _update_input_buffer()
	{
		input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
		input_pos = 0;

		if (input_len == 0)
			input_buffer[0] = EOF;
	}

	inline char next_char(bool advance = true)
	{
		if (input_pos >= input_len)
			_update_input_buffer();

		return input_buffer[advance ? input_pos++ : input_pos];
	}

	inline bool isspace(char c)
	{
		return (unsigned char) (c - '\t') < 5 || c == ' ';
	}

	template<typename T>
	inline void read_int(T &number)
	{
		bool negative = false;
		number = 0;

		while (!isdigit(next_char(false)))
			if (next_char() == '-')
				negative = true;

		do
		{
			number = 10 * number + (next_char() - '0');
		} while (isdigit(next_char(false)));

		if (negative)
			number = -number;
	}

	template<typename T, typename... Args>
	inline void read_int(T &number, Args &... args)
	{
		read_int(number);
		read_int(args...);
	}

	inline void read_char(char &c)
	{
		while (isspace(next_char(false)))
			next_char();

		c = next_char();
	}

	inline void read_str(string &str)
	{
		while (isspace(next_char(false)))
			next_char();

		str.clear();

		do
		{
			str += next_char();
		} while (!isspace(next_char(false)));
	}

	void _flush_output()
	{
		fwrite(output_buffer, sizeof(char), output_pos, stdout);
		output_pos = 0;
	}

	inline void write_char(char c)
	{
		if (output_pos == BUFFER_SIZE)
			_flush_output();

		output_buffer[output_pos++] = c;
	}

	template<typename T>
	inline void write_int(T number, char after = '\0')
	{
		if (number < 0)
		{
			write_char('-');
			number = -number;
		}

		int length = 0;

		while (number >= 10)
		{
			uint8_t lookup_value = lookup[number % 100];
			number /= 100;
			number_buffer[length++] = (lookup_value & 15) + '0';
			number_buffer[length++] = (lookup_value >> 4) + '0';
		}

		if (number != 0 || length == 0)
			write_char(number + '0');

		for (int i = length - 1; i >= 0; i--)
			write_char(number_buffer[i]);

		if (after)
			write_char(after);
	}

	inline void write_str(const string &str, char after = '\0')
	{
		for (char c : str)
			write_char(c);

		if (after)
			write_char(after);
	}

	void init()
	{
		// Make sure _flush_output() is called at the end of the program.
		bool exit_success = atexit(_flush_output) == 0;
		assert(exit_success);

		for (int i = 0; i < 100; i++)
			lookup[i] = (i / 10 << 4) + i % 10;
	}
}

const int mod = 1e9+7;
int dp[60][16];

void add(int &x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}

int main()
{
	#ifdef TurnRed
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

    IO::init();
	int t;
	IO::read_int(t);
	while (t--)
	{
		ll n;
		IO::read_int(n);

		memset(dp, 0, sizeof dp);
		dp[59][n >> 59 & 1] = 1;
		for (int i = 58; i >= 0; --i)
		{
			int s = 0;
			for (int j = 0; j < 8; ++j)
				add(s, dp[i+1][j]);

			for (int j = (n >> i & 1); j < 16; j += 2)
			{
				int k = j >> 1;
//				for (int l = k; l < min(16, k+8); ++l)
					add(dp[i][j], s);
				add(s, mod-dp[i+1][k]);
				add(s, dp[i+1][k+8]);
			}
		}
		int ans = 0;
		for (int i = 0; i < 8; ++i)
			add(ans, dp[0][i]);
		IO::write_int(ans, '\n');
	}

	return 0;
}