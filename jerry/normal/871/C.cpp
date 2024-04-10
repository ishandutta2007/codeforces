#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007ll;

namespace UF
{
	int p[100005];
	void init(int n) { for (int i = 0;i < n;i++) p[i] = i; }
	int gp(int a) { return p[a]==a?a:p[a]=gp(p[a]); }
	void mrg(int a, int b) { p[gp(a)] = gp(b); }
};

map<int, vector<int> > hx, hy;
int x[100005], y[100005];
vector<int> hv[100005];
long long ans;
int n;

int main()
{
	ans = 1;
	scanf("%d", &n); UF::init(n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d%d", x+i, y+i);
		hx[x[i]].push_back(i);
		hy[y[i]].push_back(i);
	}
	for (auto &u: hx) for (unsigned i = 1;i < u.second.size();i++) UF::mrg(u.second[i-1], u.second[i]);
	for (auto &u: hy) for (unsigned i = 1;i < u.second.size();i++) UF::mrg(u.second[i-1], u.second[i]);
	for (int i = 0;i < n;i++) hv[UF::gp(i)].push_back(i);
	for (int i = 0;i < n;i++) if (UF::gp(i) == i)
	{
		set<int> X, Y;
		for (int u: hv[i]) X.insert(x[u]), Y.insert(y[u]);
		long long tmp = 1;
		for (unsigned j = 0;j < X.size()+Y.size();j++) tmp = (tmp*2)%MOD;
		if (X.size()+Y.size() > hv[i].size()) tmp = (tmp+MOD-1)%MOD;
		ans *= tmp;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}