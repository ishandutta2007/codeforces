#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int hmod1 = 1000000007;
const int hmod2 = 1000000009;

inline int sum(int a, int b, int mod)
{
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

inline int sub(int a, int b, int mod)
{
	a -= b;
	if (a < 0) a += mod;
	return a;
}

inline int mul(int a, int b, int mod)
{
	return ((ll)a * b) % mod;
}

struct thash
{
	int h1, h2;
	
	thash (): h1(0), h2(0) {}
	thash (int x)
	{
		h1 = x;
		h2 = x;
	}
	
	thash(int h1_, int h2_): h1(h1_), h2(h2_) {}
};

inline thash operator*(const thash &a, const thash &b)
{
	return thash(mul(a.h1, b.h1, hmod1), mul(a.h2, b.h2, hmod2));
}

inline thash operator+(const thash &a, const thash &b)
{
	return thash(sum(a.h1, b.h1, hmod1), sum(a.h2, b.h2, hmod2));
}

inline thash operator-(const thash &a, const thash &b)
{
	return thash(sub(a.h1, b.h1, hmod1), sub(a.h2, b.h2, hmod2));
}

inline bool operator==(const thash &a, const thash &b)
{
	return a.h1 == b.h1 && a.h2 == b.h2;
}

const int BSZ = 300;

const int maxn = 100005;

int st[maxn];
vector<int> open[maxn], close[maxn];
vector<thash> hopen[maxn], hclose[maxn];
vector<thash> hl, hr;
vector<int> curl, curr;
int s[maxn];
int n, nq;
int stsz;
bool bad;
thash hst[maxn];
bool isbad[maxn];

void dostack(int l, int r)
{
	stsz = 0;
	bad = false;
	for (int i = l; i < r; i++)
	{
		if (s[i] > 0 || stsz == 0) st[stsz++] = s[i];
		else
		{
			if (st[stsz - 1] < 0) st[stsz++] = s[i];
			else
			{
				if (st[stsz - 1] != -s[i]) bad = true;
				stsz--;
			}
		}
	}
}

vector<thash> calch(vector<int> &a)
{
	vector<thash> h;
	h.resize((int)a.size() + 1, 0);
	if (a.size() == 0) return h;
	if (a[0] > 0)
	{
		for (int i = 0; i < (int)a.size(); i++) h[i + 1] = h[i] * hst[1] + a[i];
	} else
	{
		for (int i = (int)a.size() - 1; i >= 0; i--) h[i] = h[i + 1] * hst[1] + abs(a[i]);
	}
	return h;
}

struct tsubs
{
	vector<thash> *h;
	int l;
	int r;
	
	int len()
	{
		return r - l;
	}
};

inline thash gethl(vector<thash> *h, int l, int r)
{
	return (*h)[r] - (*h)[l] * hst[r - l];
}

inline thash gethr(vector<thash> *h, int l, int r)
{
	return (*h)[l] - (*h)[r] * hst[r - l];
}

inline bool operator==(const tsubs &a, const tsubs &b)
{
	thash ha = gethl(a.h, a.l, a.r);
	thash hb = gethr(b.h, b.l, b.r);
	//for (auto t : *b.h) cout << t.h1 << ' ';
	//cout << endl;
	//cout << ha.h1 << ' ' << hb.h1 << endl;
	return ha == hb;
}

void build(int bid)
{
	int l = bid * BSZ;
	int r = min((bid + 1) * BSZ, n);
	dostack(l, r);
	
	isbad[bid] = false;
	if (bad) isbad[bid] = true;
	
	close[bid].clear();
	open[bid].clear();
	for (int i = 0; i < stsz; i++)
	{
		if (st[i] < 0) close[bid].pb(st[i]);
		else open[bid].pb(st[i]);
	}
	//cout << "build " << bid << ' ' << stsz << ' ' << close[bid].size() << endl;
	hclose[bid] = calch(close[bid]);
	hopen[bid] = calch(open[bid]);
}

tsubs getsub(const tsubs &a, int l, int r)
{
	return {a.h, l, r};
}

void query(int l, int r)
{
	int lid = l / BSZ;
	int rid = r / BSZ;
	if (lid == rid)
	{
		dostack(l, r + 1);
		if (!bad && stsz == 0)
		{
			printf("Yes\n");
		} else
		{
			printf("No\n");
		}
		return;
	}
	dostack(l, (lid + 1) * BSZ);
	if (bad || (stsz > 0 && st[0] < 0))
	{
		printf("No\n");
		return;
	}
	curl.clear();
	for (int i = 0; i < stsz; i++)
	{
		curl.pb(st[i]);
	}
	hl = calch(curl);
	
	vector<tsubs> opens;
	if (stsz > 0) opens.pb({&hl, 0, stsz});
	for (int i = lid + 1; i < rid; i++)
	{
		if (isbad[i])
		{
			printf("No\n");
			return;
		}
		tsubs curclose = {&hclose[i], 0, (int)close[i].size()};
		while (!opens.empty() && curclose.len() > 0)
		{
			tsubs curopen = opens.back();
			opens.pop_back();
			int lencmp = min(curopen.len(), curclose.len());
			tsubs cl = getsub(curopen, curopen.r - lencmp, curopen.r);
			tsubs cr = getsub(curclose, curclose.l, curclose.l + lencmp);
			if (!(cl == cr))
			{
				printf("No\n");
				return;
			}
			curclose = getsub(curclose, curclose.l + lencmp, curclose.r);
			curopen = getsub(curopen, curopen.l, curopen.r - lencmp);
			if (curopen.len() > 0) opens.pb(curopen);
		}
		//cout << i << ' ' << opens.size() << endl;
		//for (auto t : opens) cout << t.len() << ' ';
		//cout << endl;
		if (curclose.len() > 0)
		{
			printf("No\n");
			return;
		}
		if (!open[i].empty()) opens.pb({&hopen[i], 0, (int)open[i].size()});
	}
	dostack(rid * BSZ, r + 1);
	
	if (bad || (stsz > 0 && st[stsz - 1] > 0))
	{
		printf("No\n");
		return;
	}
	
	//for (auto t : curl) cout << t << ' ';
	//cout << endl;
	
	curr.clear();
	for (int i = 0; i < stsz; i++)
	{
		curr.pb(st[i]);
	}
	hr = calch(curr);

	//for (auto t : curr) cout << t << ' ';
	//cout << endl;

	tsubs curclose = {&hr, 0, (int)curr.size()};
	while (!opens.empty() && curclose.len() > 0)
	{
		tsubs curopen = opens.back();
		opens.pop_back();
		int lencmp = min(curopen.len(), curclose.len());
		//cout << lencmp << endl;
		tsubs cl = getsub(curopen, curopen.r - lencmp, curopen.r);
		tsubs cr = getsub(curclose, curclose.l, curclose.l + lencmp);
		//cout << cl.l << ' ' << cl.r << ' ' << cr.l << ' ' << cl.r << endl;
		if (!(cl == cr))
		{
			//cout << "not eq " << endl;
			printf("No\n");
			return;
		}
		curclose = getsub(curclose, curclose.l + lencmp, curclose.r);
		curopen = getsub(curopen, curopen.l, curopen.r - lencmp);
		if (curopen.len() > 0) opens.pb(curopen);
	}
	//cout << curclose.len() << ' ' << opens.size() << endl;
	if (curclose.len() > 0 || !opens.empty())
	{
		printf("No\n");
		return;
	}
	printf("Yes\n");
}

int main()
{
	hst[0] = 1;
	hst[1] = 239017;
	for (int i = 2; i < maxn; i++) hst[i] = hst[i - 1] * hst[1];
	scanf("%d%*d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &s[i]);
	for (int i = 0; i < n; i += BSZ) build(i / BSZ);
	int nq;
	scanf("%d", &nq);
	for (int q = 0; q < nq; q++)
	{
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if (t == 1)
		{
			a--;
			s[a] = b;
			build(a / BSZ);
		} else
		{
			a--, b--;
			query(a, b);
		}
	}
    return 0;
}