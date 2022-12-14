#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef unsigned u32;

namespace input
{
	const int BufferSize = 1 << 16 | 1;

	char buffer[BufferSize];
	char *head = buffer + BufferSize;
	const char *tail = head;

	inline char nextChar()
	{
		if (head == tail)
		{
			fread(buffer, 1, BufferSize, stdin);
			head = buffer;
		}
		return *head++;
	}

	inline int getint()
	{
		static char c;
		while ((c = nextChar()) < '0' || c > '9');

		int res = c - '0';
		while ((c = nextChar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
}
using input::getint;

namespace output
{
	const int BufferSize = 23333333;

	char buffer[BufferSize];
	char *out_tail = buffer;

	char s[11], *t;
	inline void putint(int x)
	{
		if (x == 0)
			*out_tail++ = '0';
		else
		{
			t = s;
			while (x > 0)
				*t++ = x % 10 + '0', x /= 10;
			while (t-- != s)
				*out_tail++ = *t;
		}
		*out_tail++ = '\n';
	}

	inline void flush()
	{
		fwrite(buffer, 1, out_tail - buffer, stdout);
	}
}
using output::putint;

const int MaxN = 200005;
const int L = 16;
const int N = 32;
const int TN = 6250;

int nT;
char a[MaxN], b[MaxN];

int cnt[1 << L | 1];

inline int get(u32 x)
{
/*	int res = cnt[x & 2047];
	res += cnt[(x >>= 11) & 2047];
	return res + cnt[x >> 11];*/
	return cnt[x & 65535u] + cnt[x >> 16];
}
inline int get(u32 x, int l)
{
	l > 0 ? x &= (1u << l) - 1 : x = 0;
/*	int res = cnt[x & 2047];
	res += cnt[(x >>= 11) & 2047];
	return res + cnt[x >> 11];*/
	return cnt[x & 65535u] + cnt[x >> 16];
}

u32 maskA[N][TN + 1];
u32 maskB[N][TN + 1];

inline void build_mask(const char *a, u32 mask[][TN + 1])
{
	int u = 0, v = 0;
	for (int i = 0; a[i]; ++i)
	{
		mask[0][u] |= (a[i] & 1) << v;
		u += ++v == 32;
		v &= 31;
	}

	for (int l = 1; l < N; ++l)
	{
		u32 *ori_b = mask[l - 1];
		u32 *new_b = mask[l];
		for (int i = 0; i < TN; ++i)
		{
			int high = ori_b[i + 1] & 1;
			new_b[i] = ori_b[i] >> 1;
			new_b[i] |= high << 31;
		}
	}
}

int main()
{
	cnt[0] = 0;
	for (int i = 1; i < 1 << L; ++i)
		cnt[i] = cnt[i >> 1] + (i & 1);

	scanf("%s%s", a, b);
	build_mask(a, maskA);
	build_mask(b, maskB);

	nT = getint();
	while (nT--)
	{
		int u = getint(), v = getint();
		int l = getint(), res = 0;

		u32 *f = maskA[u & 31] + (u >> 5);
		u32 *g = maskB[v & 31] + (v >> 5);
		for (int i = 0; l > 0; )
		{
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
			res += l < 32 ? get(f[i] ^ g[i], l) : get(f[i] ^ g[i]), l -= 32, ++i;
		}
		putint(res);
	}

	output::flush();
	return 0;
}