#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >
#define all(x) (x).begin(), (x).end()

using namespace std;

class Inter{
public:
	int Maks;
	set < pii > S;
	Inter() : Maks(0){}
	void Add(int t){
		pii ct = {t, t};
		auto it = S.lower_bound({t, t});
		if (it != S.end())
			if (it->x == t + 1){
				ct.y = it->y;
				S.erase(it);
			}
		it = S.lower_bound({t, t});
		if (it != S.begin()){
			--it;
			if (it->y == t - 1){
				ct.x = it->x;
				S.erase(it);
			}
		}
		S.insert(ct);
		Maks = max(Maks, ct.y - ct.x + 1);
	}
} T;

int n;
int a[200005];
int b[200005];

bool cmp(int a, int b){return ::a[a] > ::a[b];}

int main(){
	scanf("%d", &n);
	FOR(0, n, i) scanf("%d", a + i);
	vector < int > V;
	FOR(0, n, i) V.pb(i);
	sort(V.begin(), V.end(), cmp);
	for (auto x : V){
		T.Add(x);
		b[T.Maks] = max(b[T.Maks], a[x]);
	}
	for (int i = n; i >= 1; --i)
		if (!b[i - 1]) b[i - 1] = b[i];
	FOR(1, n + 1, i) printf("%d ", b[i]); printf("\n");
	return 0;
}