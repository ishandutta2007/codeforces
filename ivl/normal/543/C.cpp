#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >
#define all(x) (x).begin(), (x).end()

using namespace std;

int POW[1 << 20];

const int oo = 1000000000;

int n, m;
string in[25];
int a[25][25];
int mini[25];

vector < pii > Bits;
vector < pii > Trans[25];

int ALL;
int memo[1 << 20];
bool bio[1 << 20];
int dp(int bit){
	int &r = memo[bit];
	if (bio[bit]++) return r;
	r = oo;
	int t = POW[bit ^ ALL];
	for (auto x : Trans[t])
		r = min(r, x.y + dp(bit | x.x));
	return r;
}

int main(){
	FOR(0, 1 << 20, i) if (i & 1) POW[i] = 0; else POW[i] = 1 + POW[i / 2];
	FOR(0, 25, i) mini[i] = oo;
	
	scanf("%d%d", &n, &m);
	FOR(0, n, i) cin >> in[i];
	FOR(0, n, i) FOR(0, m, j) scanf("%d", a[i] + j);
	FOR(0, n, i) FOR(0, m, j) mini[i] = min(mini[i], a[i][j]);
	FOR(0, m, i){
		vector < int > V[26];
		FOR(0, n, j) V[in[j][i] - 'a'].pb(j);
		for (auto x : V){
			if (x.size() == 0) continue;
			pii T = {0, 0};
			int maksi = -1;
			for (auto y : x){
				T.x |= (1 << y);
				T.y += a[y][i];
				if (maksi < a[y][i]) maksi = a[y][i];
			}
			T.y -= maksi;
			Bits.pb(T);
		}
	}
	for (auto x : Bits)
		FOR(0, n, i)
			if ((x.x >> i) & 1)
				Trans[i].pb(x);
	ALL = (1 << n) - 1;
	memo[ALL] = 0;
	bio[ALL] = true;
	FOR(0, 1 << n, i) dp(ALL ^ i);
	int RES = oo;
	FOR(0, 1 << n, i){
		int R = dp(i);
		FOR(0, n, j)
			if ((i >> j) & 1)
				R += mini[j];
		RES = min(RES, R);
	}
	printf("%d\n", RES);
	return 0;
}