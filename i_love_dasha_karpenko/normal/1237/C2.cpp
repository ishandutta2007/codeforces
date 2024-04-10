#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
const ll BLOCK = 400;
const ll DIM = 50007;
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
const ll bufsize = 500;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}
struct node {
	ll x, y, z,pos;
};
ll di(node a, node b) {
	return abs(a.x - b.x) + abs(a.y - b.y) + abs(b.z - a.z);
}
ll n,vis[DIM];
node A[DIM];
bool mc(node a, node b) {
	if (a.x == b.x) {
		if (a.y == b.y)return a.z < b.z;
		return a.y < b.y;
	}
	return a.x < b.x;
}
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i].x >> A[i].y >> A[i].z;
		A[i].pos = i;
	}
	sort(A + 1, A + 1 + n, mc);

	forn(i, n) {
		if (i<n && A[i].x == A[i + 1].x && A[i].y == A[i + 1].y) {
			cout << A[i].pos << ' ' << A[i + 1].pos << endl;
			vis[i] = vis[i + 1] = 1;
			i++;
		}
	}
	
	ll last = -1;
	forn(i, n) {
		if (vis[i] == 1)continue;
		if (last!=-1 && A[last].x == A[i].x) {
			cout << A[last].pos << ' ' << A[i].pos << endl;
			vis[last] = 1;
			vis[i] = 1;
			last = -1;
		}
		else {
			last = i;
		}
	}
	last = -1;
	forn(i, n) {
		if (vis[i] == 1)continue;
		if (last != -1) {
			cout << A[last].pos << ' ' << A[i].pos << endl;
			last = -1;
		}
		else last = i;
	}
	return 0;

}