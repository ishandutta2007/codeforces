#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MAX_N 100005
#define INF 1000000000

using namespace std;

typedef long long ll;

/* This function return the gcd of a and b followed by
   the pair x and y of equation ax + by = gcd(a,b)*/
pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b) {
	ll x = 1, y = 0;
	ll xLast = 0, yLast = 1;
	ll q, r, m, n;
	while(a != 0) {
		q = b / a;
		r = b % a;
		m = xLast - q * x;
		n = yLast - q * y;
		xLast = x, yLast = y;
		x = m, y = n;
		b = a, a = r;
	}
	return make_pair(b, make_pair(xLast, yLast));
}

ll modInverse(ll a, ll m) {
	return (extendedEuclid(a,m).second.first + m) % m;
}

set<pair<int,int> > u[MAX_N]; // spanning tree
bool seen[MAX_N];
int p[MAX_N];
int n;
ll m;
ll ti;
ll pwt[100005];
ll pwti[100005];


int ts[MAX_N], mxs[MAX_N];
vector<int> v;

void cs(int i, int par) {
    v.push_back(i);
    ts[i] = 1; mxs[i] = 0;
    for (auto e : u[i]) if (e.first != par) {
        cs(e.first,i);
        ts[i] += ts[e.first];
        mxs[i] = max(mxs[i], ts[e.first]);
    }
}
vector<ll> a, b;

void cl(int i, int par, ll v1, ll v2, int l) {
    //printf("%d->%d : %lld %lld %d\n", par, i, v1, v2, l);
    a.emplace_back(v1);
    b.emplace_back((m-v2) * pwti[l] % m);
    for (auto e : u[i]) if (e.first != par) {
        cl(e.first,i,
                (v1+e.second*pwt[l])%m,
                (v2*10+e.second)%m,
                l+1);
    }
}

map<int,int> ac, bc;
ll res = 0;

void decomp(int r) {
    v.clear(); cs(r,0);
    for (int x : v) mxs[x] = max(mxs[x], ts[r]-ts[x]);
    for (int x : v) if (mxs[x] < mxs[r]) r = x;
    //printf("r=%d\n", r);
    ac.clear(); bc.clear();
    ac[0] = 1;
    bc[0] = 1;
    for (auto e : u[r]) {
        int i = e.first;
        a.clear(); b.clear();
        cl(i, r, e.second % m, e.second % m, 1);
        for (ll x : a) {
            auto it = bc.find(x);
            if (it != bc.end()) res += it->second;
        }
        for (ll x : b) {
            auto it = ac.find(x);
            if (it != ac.end()) res += it->second;
        }

        for (ll x : a) ac[x] += 1;
        for (ll x : b) bc[x] += 1;
    }
    for (auto e : u[r]) {
        auto re = e; re.first = r;
        u[e.first].erase(re);
        decomp(e.first);
    }
}

int main() {
	scanf("%d %lld", &n, &m);
    ti = modInverse(10, m);
    pwt[0] = 1;
    pwti[0] = 1;
    FO(i,1,100005) {
        pwt[i] = 10 * pwt[i-1] % m;
        pwti[i] = ti * pwti[i-1] % m;
    }
    FO(i,0,n-1) {
        int  x, y, w; scanf("%d %d %d", &x, &y, &w);
        x++; y++;
        u[x].emplace(y,w);
        u[y].emplace(x,w);
    }

    decomp(1);

    printf("%lld\n", res);
}