// Coding on my mac
// My mac doesn't have bits/stdc++.h
// http://codeforces.com/blog/entry/47152 looks helpful
// If only I could be bothered setting things up

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

struct data
{
	ll value; int far, node;
	data(ll V, int F, int N) : value(V), far(F), node(N) { }
	bool operator< (const data& oth) const
	{
		if (value != oth.value) return (value < oth.value);
		if (far != oth.far) return (far < oth.far);
		return (node < oth.node);
	}
};

vector<pair<int, int> > ch[100005];
bool prime[32000];
bool dead[100005];
int bel[100005];
ll p10[100005];
ll inv[100005];
int sz[100005];
int n, m;
ll ans;

map<ll, int> mA[100005];
multiset<data> mB;
vector<int> hv;

void dfs(int at, int par, ll A, ll B, int dep, int rt)
{
	mA[rt][A]++; mB.emplace(B, dep, at);
	if (bel[at] != -1)
		mA[bel[at]][A]++;
	for (auto u: ch[at]) if (!dead[u.first] && u.first != par)
	{
		bel[u.first] = bel[at];
		if (bel[at] == -1) bel[u.first] = u.first;
		dfs(u.first, at, (A+u.second*p10[dep])%m, (B*10+u.second)%m, dep+1, rt);
	}
}

int getsz(int at, int par=-1)
{
	sz[at] = 1;
	hv.push_back(at);
	for (auto u: ch[at]) if (!dead[u.first] && u.first != par)
		sz[at] += getsz(u.first, at);
	return sz[at];
}

void slv(int at)
{
	int tot = getsz(at);
	at = -1;
	for (int u: hv)
	{
		int hi = tot - sz[u];
		for (auto v: ch[u]) if (!dead[v.first] && sz[v.first] < sz[u])
			hi = max(hi, sz[v.first]);
		if (hi*2 <= tot)
		{
			at = u;
			break;
		}
	}
	bel[at] = -1;
	dfs(at, -1, 0, 0, 0, at);
	for (auto u: mB)
	{
		ans += mA[at][((m-u.value)%m * inv[u.far])%m];
		if (bel[u.node] != -1)
			ans -= mA[bel[u.node]][((m-u.value)%m * inv[u.far])%m];
	}
	ans--; // path of 0 length is bad

	dead[at] = true;
	mA[at].clear(), mB.clear();
	for (auto u: ch[at]) if (!dead[u.first]) mA[u.first].clear();
	hv.clear();
	for (auto u: ch[at]) if (!dead[u.first])
		slv(u.first);
}

ll euler()
{
	ll val = m, tmp = m;
	for (int i = 2;i < 32000;i++) prime[i] = true;
	for (int i = 2;i < 32000;i++) if (prime[i])
	{
		for (int j = i*i;j < 32000;j+=i) prime[j] = false;
		if (m%i == 0) val = val/i*(i-1);
		while (tmp%i == 0) tmp /= i;
	}
	if (tmp != 1) val = val/tmp*(tmp-1);
	return val;
}

ll exp(ll b, ll e)
{
	if (e == 0) return 1;
	ll ret = exp(b, e>>1);
	ret *= ret; ret %= m;
	if (e&1ll) ret = (ret * b) % m;
	return ret;
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	p10[0] = 1;
	for (int i = 1;i < n;i++) p10[i] = (p10[i-1]*10)%m;
	int phi = euler();
	for (int i = 0;i < n;i++) inv[i] = exp(p10[i], phi-1);

	for (int i = 1;i < n;i++)
	{
		int a, b, d; cin >> a >> b >> d;
		ch[a].emplace_back(b, d);
		ch[b].emplace_back(a, d);
	}
	slv(0);
	cout << ans << endl;
	return 0;
}