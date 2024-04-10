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

const int MOD = 1000000007;
class mint{
public:
	int x;
	mint(long long y = 0){y %= MOD; if (y < 0) y += MOD; x = y;}
};
mint operator+(mint a, mint b){a.x += b.x; if (a.x >= MOD) a.x -= MOD; return a;}
mint operator-(mint a, mint b){a.x -= b.x; if (a.x < 0) a.x += MOD; return a;}
mint operator*(mint a, mint b){return mint((ll)a.x * (ll)b.x);}
bool operator!=(mint a, mint b){return a.x != b.x;}
bool operator==(mint a, mint b){return a.x == b.x;}

int n, k;
char in[1000005];

const mint P = 101;
mint H[1000005];
mint Hpot[1000005];
void InitHash(){
	Hpot[0] = 1;
	FOR(1, 1000005, i) Hpot[i] = P * Hpot[i - 1];
	H[0] = 0;
	FOR(0, n, i) H[i + 1] = H[i] * P + in[i];
}
mint GetHash(int lo, int hi){
	return H[hi + 1] - H[lo] * Hpot[hi - lo + 1];
}

bool check(int len){
	FOR(0, k, i)
		if (GetHash(0, len - 1) != GetHash(i * len, i * len + len - 1))
			return false;
	return true;
}

int lcp(int a, int b, int len){
	int lo = 0, hi = min(n - b, len), mid = (lo + hi + 1) / 2;
	while (lo != hi){
		if (GetHash(a, a + mid - 1) == GetHash(b, b + mid - 1)) lo = mid;
		else hi = mid - 1;
		mid = (lo + hi + 1) / 2;
	}
	return mid;
}

int out[1000005];

int main(){
	scanf("%d%d%s", &n, &k, in);
	InitHash();
	FOR(1, n / k + 1, x){
		if (!check(x)) continue;
		int ID = x * k; //printf("%d ", x);
		int T = lcp(0, ID, x);
		++out[ID - 1];
		--out[ID + T];
	} //printf("\n");
	int tmp = 0;
	FOR(0, n, i){
		tmp += out[i];
		if (tmp) printf("1"); else printf("0");
	} printf("\n");
	return 0;
}