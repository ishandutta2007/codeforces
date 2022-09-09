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

const int maxn = 5005;

const int maxm = 10000000;

bitset<maxm> elems;
vector<int> added;
int have;
int n, m;
int sums[maxm];
map<int, int> sumsm;

void addsum(int s, int t)
{
	if (s < maxm)
	{
		sums[s] += t;
	} else sumsm[s] += t;
}

void add(int x, bool check = true)
{
	for (auto t : added)
	{
		if (check)
		{
			int r = x - t;
			if (r >= 1 && r < t) have += (int)elems[r];
		}
		addsum(x + t, 1);
	}
	if (check) elems[x] = 1;
	added.pb(x);
}

void rem()
{
	int x = added.back();
	added.pop_back();
	for (auto t : added)
	{
		int r = x - t;
		if (r >= 1 && r < t) have -= elems[r];
		addsum(x + t, -1);
	}
	elems[x] = 0;
}

int fst = 0;

inline bool getsum(int fst)
{
	if (fst < maxm) return sums[fst] != 0;
	auto it = sumsm.find(fst);
	return it != sumsm.end() && it->se > 0;
}

inline int findfirst()
{
	fst = max(fst, (int)added.back() + 1);
	while (getsum(fst)) fst++;
	return fst;
}

int main()
{
	scanf("%d%d", &n, &m);
	have = 0;
	for (int i = 0; i < n; i++)
	{
		add(i + 1);
		if (have >= m)
		{
			int cur = i + 1;
			while (have > m)
			{
				rem();
				cur++;
				add(cur + 1);
			}
			assert(have == m);
			break;
		}
	}
	if (have < m)
	{
		printf("-1\n");
		return 0;
	}
	while ((int)added.size() < n)
	{
		int cur = findfirst();
		//cout << "got " << cur << endl;
		add(cur, false);
	}
	//int curans = 0;
	//for (int i = 0; i < (int)added.size(); i++)
	//{
		//for (int j = i + 1; j < (int)added.size(); j++)
		//{
			//for (int k = j + 1; k < (int)added.size(); k++) curans += (added[i] + added[j] == added[k]);
		//}
	//}
	//assert(curans == m);
	for (auto t : added) printf("%d ", t);
    return 0;
}