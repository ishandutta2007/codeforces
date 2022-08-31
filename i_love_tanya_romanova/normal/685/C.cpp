/*
You open up and what you gain is another hole
Reaching out for a hand and I know
The fear of losing all the trust that it craves
And feel that parts of you are never coming back

I used to think that life was ugly and a mess
Well I was right but what else to do other than your best
The meaning of it all you find within yourself
I hold the key but where's the door
I kick it in

Whatever that I want I will get
I'll take the beatings too and all the blame
But father you're the one that I miss
I'm thankful that I have our loved ones near
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000009
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 300331;

int tests;
int n;
long long x[N], y[N], z[N];

struct SHIT
{
	pair<long long, long long> P[4];
};

struct SOLUTION
{
	long long C[5];
	bool ok;
};

void show(SHIT S)
{
	for (int i = 0; i < 4; i++)
	{
		cout << S.P[i].first << "%" << S.P[i].second << endl;
	}
}

SHIT make(int id, long long thold)
{
	SHIT S;
	long long val;
	val = x[id] + y[id] + z[id];
	S.P[0] = make_pair(val - thold, val + thold);
	val = x[id] + y[id] - z[id];
	S.P[1] = make_pair(val - thold, val + thold);
	val = x[id] - y[id] + z[id];
	S.P[2] = make_pair(val - thold, val + thold);
	val = x[id] - y[id] - z[id];
	S.P[3] = make_pair(val - thold, val + thold);
	return S;
}

pair<long long, long long> inter(pair<long long, long long> p1, pair<long long, long long> p2)
{
	p1.first = max(p1.first, p2.first);
	p1.second = min(p1.second, p2.second);
	return p1;
}

SHIT combine(SHIT a, SHIT b)
{
	SHIT res;
	for (int i = 0; i < 4; i++)
	{
		res.P[i] = inter(a.P[i], b.P[i]);
	}
	return res;
}

SHIT solve(long long bound)
{
	SHIT P = make(1, bound);
	for (int i = 2; i <= n; i++)
	{
		SHIT HERE = make(i, bound);
		P = combine(P, HERE);
	}
	return P;
}

long long real_x, real_y, real_z, ans_x, ans_y, ans_z;

long long Abs(long long x)
{
	return (x > 0 ? x : -x);
}

unsigned long long eval(long long a, long long b, long long c)
{
	unsigned long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, 0ull + Abs(a - x[i]) + Abs(b - y[i]) + Abs(c - z[i]));
	}
	return res;
}

SHIT normalize(SHIT S)
{
	for (int i = 0; i < 4; i++)
	{
		S.P[i].first = S.P[i].first + S.P[i].second;
		S.P[i].first /= 2;
	}
	return S;
}

pair<long long, long long> bound[10];

long long solve_lim_d(long long val, int par)
{
	if (par == 1)
	{
		if (val % 2 == 0)
			++val;
	}
	if (par==0)
	{
		if (val % 2 != 0)
			++val;
	}
	return val;
}

long long solve_lim_u(long long val, int par)
{
	if (par == 1)
	{
		if (val % 2 == 0)
			--val;
	}
	if (par == 0)
	{
		if (val % 2 != 0)
			--val;
	}
	return val;
}

pair<long long, long long> solve_bounds(pair<long long, long long> p, int par)
{
	pair<long long, long long> res;
	res.first = solve_lim_d(p.first, par);
	res.second = solve_lim_u(p.second, par);
	return res;
}

SOLUTION get_c(SOLUTION s)
{
	SOLUTION res = s;
	res.C[2] = s.C[0] - s.C[1];//z
	res.C[2] /= 2;
	res.C[1] = s.C[0] - s.C[2];
	res.C[1] /= 2;
	res.C[0] = s.C[0] - res.C[1] - res.C[2];
	return res;
}

SOLUTION resolve(SHIT S)
{
	SOLUTION ret;
	ret.ok = 0;
	
	for (int par = 0; par <= 1; par++) // 0+3-1=2
	{
		SOLUTION here;
		here.ok = 0;
		int flag = 0;

		for (int i = 0; i < 4; i++)
		{
			bound[i] = solve_bounds(S.P[i], par);
			if (bound[i].first>bound[i].second)
				flag = 1;
		}
		if (flag)
			continue;
		long long cur_res = 0;
		cur_res += bound[0].first + bound[3].first - bound[1].first;
		for (int i = 0; i < 4; i++)
		{
			here.C[i] = bound[i].first;
		}

		here.C[2] = cur_res;

		if (cur_res < bound[2].first)// need to add, inc 0&3
		{
			long long can_add = bound[0].second - bound[0].first;
			long long toadd = min(can_add, bound[2].first - here.C[2]);
			here.C[0] += toadd;
			here.C[2] += toadd;

			can_add = bound[3].second - bound[3].first;
			toadd = min(can_add, bound[2].first - here.C[2]);
			here.C[3] += toadd;
			here.C[2] += toadd;
		}

		if (here.C[2]>bound[2].second)//need to sub, inc 1
		{
			long long can_add = bound[1].second - bound[1].first;
			can_add = min(can_add, here.C[2] - bound[2].second);
			here.C[2] -= can_add;
			here.C[1]+= can_add;
		}

		if (here.C[2] >= bound[2].first&&here.C[2] <= bound[2].second)
			here.ok = 1;
		if (here.ok)
			ret = here;
	}

	if (ret.ok)
		ret = get_c(ret);

	return ret;
}

bool valid(SHIT S)
{
	SOLUTION Sol = resolve(S);
	return Sol.ok;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i] >> y[i] >> z[i];
		}
		long long l, r;
		l = 0;
		r = 3e18 + 1e17;
		//l = r = 4;
		while (l < r)
		{
			long long mid = l + r;
			mid /= 2;
			SHIT S = solve(mid);
			if (valid(S))
				r = mid;
			else
				l = mid + 1;
		}

		SHIT S = solve(l);
		
		SOLUTION sol = resolve(S);
		cout << sol.C[0] << " " << sol.C[1] << " " << sol.C[2] << endl;
//		cout << ans_x << " " << ans_y << " " << ans_z << endl;
	}
	cin.get(); cin.get();
	return 0;
}