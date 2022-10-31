#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 57
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 10E18
const ll INF = 10E18;
const ll mask = po(9) - 1;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
struct node {
	ll x, m, num;
};
ll n, A[DIM][DIM],V[DIM][DIM];
vector<pp> vec[3];
void dfs(pp x, ll arg) {
	if (x.fi<1 || x.fi>n || x.sc<1 || x.sc> n || V[x.fi][x.sc] !=0 || A[x.fi][x.sc]==1)return;
	V[x.fi][x.sc] = arg;
	vec[arg].pb(x);
	dfs(pp{ x.fi + 1,x.sc },arg);
	dfs(pp{ x.fi - 1,x.sc }, arg);
	dfs(pp{ x.fi,x.sc - 1 }, arg);
	dfs(pp{ x.fi,x.sc + 1 }, arg);
}

int main() {
	schnell;
	cin >> n;
	pp start, finish;
	cin >> start.fi >> start.sc >> finish.fi >> finish.sc;
	forn(i, n) {
		forn(j, n) {
			char x;
			cin >> x;
			A[i][j] = x - '0';
		}
	}
	dfs(start, 1);
	if (V[finish.fi][finish.sc] == 1) {
		cout << 0 << endl;
		return 0;
	}
	dfs(finish, 2);
	ll res = INF;
	for (pp to : vec[1]) {
		for (pp at : vec[2]) {
			res = min(res, abs(to.fi - at.fi)* abs(to.fi - at.fi) + abs(to.sc - at.sc)* abs(to.sc - at.sc));
		}
	}
	cout << res << endl;
}