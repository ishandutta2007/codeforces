#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long

using namespace std;

void ReadLL(ll &a){
	char c = '\0';
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9'){
		a = a * 10 + c - '0';
		c = getchar();
	}
}

int n, q;
ll a[3000005];
ll pref[3000005];
ll Get(int lo, int hi){return pref[hi + 1] - pref[lo];}
/*
int nxt[2000005];
int lca[21][2000005];

int GetNxt(int ID, int cnt){
	FOR(0, 21, i) if (cnt & (1 << i)) ID = lca[i][ID];
	return ID;
}
*/
int main(){
	scanf("%d%d", &n, &q);
	FOR(0, n, i) ReadLL(a[i]), a[2 * n + i] = a[n + i] = a[i];
	pref[0] = 0;
	FOR(0, n * 3, i) pref[i + 1] = pref[i] + a[i]; //return 0;
	REP(q){
		ll b;
		scanf("%I64d", &b);
		
		
		ll tmp = 0;
		int cnt = 0;
		FOR(0, n, i){
			if (tmp + a[i] > b){
				++cnt; tmp = 0;
			} tmp += a[i];
		} if (tmp) ++cnt, tmp = 0; // rjesenje je ili cnt ili cnt - 1
		
		
		vector < int > V = {0};
		//ll tmp = 0;
		FOR(0, n * 3, i){
			if (tmp + a[i] > b){
				V.pb(i);
				tmp = 0;
			} tmp += a[i];
		} if (tmp) V.pb(3 * n), tmp = 0;
		
		if (cnt == 1){
			printf("1\n");
			continue;
		}
		
		bool CHECK = false;
		FOR(0, V.size(), i){
			if (i + cnt - 1 >= V.size()) break;
			if (V[i + cnt - 1] - V[i] >= n) CHECK = true;
		}
		
		if (CHECK) printf("%d\n", cnt - 1); else printf("%d\n", cnt);
		
		/*
		int p1 = 0, p2 = 0;
		while (p1 != 2 * n){
			if (p2 != 2 * n - 1 && Get(p1, p2 + 1) <= b) ++p2; // mogu expandat
			else { // nemrem
				nxt[p1] = p2 + 1;
				++p1;
			}
		} // oni koji mogu do kraja pokazuju na 2n, bsomp 2n -> 2n
		nxt[2 * n] = 2 * n;
		
		FOR(0, 2 * n + 1, i) lca[0][i] = nxt[i];// printf("%d -> %d\n", i, nxt[i]);
		FOR(1, 21, i) FOR(0, 2 * n + 1, j) lca[i][j] = lca[i - 1][lca[i - 1][j]];
		
		bool CHECK = false;
		FOR(0, n, i){
			int X = GetNxt(i, cnt - 1);
			if (X - i >= n){
				CHECK = true; //printf(" -> %d [%d]\n", i, X);
				break;
			}
		}
		if (CHECK) printf("%d\n", cnt - 1); else printf("%d\n", cnt);
		*/
	}
	return 0;
}