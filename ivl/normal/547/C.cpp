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

int n, q;
int a[200005];
int erat[500005], e2[500005];
vector < pii > Div[500005];

int Cnt[500005];
bool Ex[200005];
ll Res;

int main(){
	
	FOR(2, 500005, i)
		if (!erat[i])
			for (int j = i; j < 500005; j += i)
				erat[j] = i, e2[j] = j / i;
	
	Div[1] = {{1, 1}};
	FOR(2, 500005, i){
		int Prime = erat[i], tmp = e2[i];
		if (erat[tmp] == Prime) Div[i] = Div[tmp];
		else for (auto x : Div[tmp])
			Div[i].pb(x), Div[i].pb({x.x * Prime, x.y * (-1)});
	}
	
	scanf("%d%d", &n, &q);
	FOR(1, n + 1, i) scanf("%d", a + i);
	
	REP(q){
		int x;
		scanf("%d", &x);
		int coef = (Ex[x] ? -1 : 1);
		Ex[x] = !Ex[x];
		for (auto t : Div[a[x]]){
			if (coef < 0) Cnt[t.x] += coef;
			Res += coef * t.y * Cnt[t.x];
			if (coef > 0) Cnt[t.x] += coef;
		}
		printf("%I64d\n", Res);
	}
	
	return 0;
}