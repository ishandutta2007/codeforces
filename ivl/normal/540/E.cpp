#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>

#define FOR(a, b, c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)
#define pii pair < int, int >
#define x first
#define y second
#define ll long long

using namespace std;

int loga[1 << 20];
void add(int p, int v){ ++p;
	for (; p < (1 << 20); p += p & -p)
		loga[p] += v;
}
int sum(int p){ ++p;
	int r = 0;
	for (; p; p -= p & -p)
		r += loga[p];
	return r;
}
int sum(int a, int b){return sum(b) - sum(a - 1);}

int n;
map < int, int > M;
set < int > S;
map < int, int > M2;
vector < int > V2;

int main(){
	scanf("%d", &n);
	REP(n){
		int a, b;
		scanf("%d%d", &a, &b);
		if (M.count(a) == 0) M[a] = a;
		if (M.count(b) == 0) M[b] = b;
		swap(M[a], M[b]);
	}
	for (auto x : M){
		M2[x.x] = V2.size();
		V2.push_back(x.x); //printf("%d\n", x.x);
	}
	int Prev = 1;
	ll R = 0;
	FOR(0, V2.size(), i){
		int x = V2[i];
		R += (ll)(x - Prev) * sum(i, 1 << 19);
		add(i, x - Prev);
		Prev = x + 1;
		R += sum(M2[M[x]] + 1, 1 << 19);
		add(M2[M[x]], 1);
	} printf("%I64d\n", R);
	return 0;
}