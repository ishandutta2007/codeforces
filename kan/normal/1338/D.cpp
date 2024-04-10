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

const int maxn = 100005;

vector<int> gr[maxn];
int down[maxn][2];
int n;
int answer;

void go(int cur, int pr)
{
	for (auto t : gr[cur]) if (t != pr) go(t, cur);
	int deg = (int)gr[cur].size() - 2;
	
	for (int i = 0; i < 2; i++) down[cur][i] = 0;
	down[cur][0] = max(0, deg);
	down[cur][1] = max(1, deg);
	for (auto t : gr[cur]) if (t != pr)
	{
		answer = max(answer, down[t][0] + down[cur][0]);
		answer = max(answer, down[t][1] + down[cur][0]);
		answer = max(answer, down[t][0] + down[cur][1]);
		
		down[cur][0] = max(down[cur][0], max(deg, 0) + down[t][1]);
		down[cur][1] = max(down[cur][1], down[cur][0]);
		down[cur][1] = max(down[cur][1], 1 + down[t][0]);
		//cout << cur << ' ';
		//for (int i = 0; i < 4; i++) cout << down[cur][i] << ' ';
		//cout << endl;
	}
	//cout << cur << ' ';
	//for (int i = 0; i < 4; i++) cout << down[cur][i] << ' ';
	//cout << endl;
	//cout << answer << endl;
}

int main()
{
	scanf("%d", &n);
	for (int i =0 ; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	answer = 0;
	go(n - 1, -1);
	printf("%d\n", answer);
	//for (int i = 0; i < n; i++)
	//{
		//answer = 0;
		//go(i, -1);
		//printf("%d\n", answer);
	//}
    return 0;
}