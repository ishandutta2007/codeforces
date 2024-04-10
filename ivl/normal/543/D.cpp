#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MOD = 1000000007;
class mint{
public:
	int x;
	mint(long long y = 0){y %= MOD; if (y < 0) y += MOD; x = y;}
};
mint operator+(mint a, mint b){a.x += b.x; if (a.x >= MOD) a.x -= MOD; return a;}
mint operator*(mint a, mint b){return mint((ll)a.x * b.x);}
void operator+=(mint &a, mint b){a = a + b;}
void operator*=(mint &a, mint b){a = a * b;}

int n;
vector < int > E[200005];
vector < int > E2[200005];

mint down[200005];
mint up[200005];
mint left[200005], right[200005];
int par[200005];
void CalcDown(int id, int par){
	::par[id] = par;
	down[id] = 1;
	for (auto x : E[id]) if (x != par){
		E2[id].pb(x);
		CalcDown(x, id);
		down[id] *= (down[x] + 1);
	}
}
void CalcUp(int id){ //printf("%d\n", id);
	left[0] = 1;
	FOR(0, E2[id].size(), i) left[i + 1] = left[i] * (down[E2[id][i]] + 1);
	right[E2[id].size() - 1] = 1;
	for (int i = E2[id].size() - 2; i >= 0; --i)
		right[i] = right[i + 1] * (down[E2[id][i + 1]] + 1);
	FOR(0, E2[id].size(), i) up[E2[id][i]] = (up[id] + 1) * left[i] * right[i];
	for (auto x : E2[id]) CalcUp(x);
}

int main(){
	scanf("%d", &n);
	FOR(2, n + 1, i){
		int a;
		scanf("%d", &a);
		E[a].pb(i);
		E[i].pb(a);
	}
	CalcDown(1, 0);
	up[1] = 0;
	CalcUp(1);
	FOR(1, n + 1, i){
		mint R = down[i] * (up[i] + 1);
		printf("%d ", R.x);
	} printf("\n");
	return 0;
}