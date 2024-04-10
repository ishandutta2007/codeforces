#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second
#define N 1000010
#define Z 4

vector<ll> graph[N];
bool bad[N];

ll enc(ll r, ll th) {
	return r * 360 * Z + th;
}

bool dfs(ll v) {
	if(v == enc(21 * Z, 0)) return true;
	bad[v] = true;
	for(ll j : graph[v]) if(!bad[j] && dfs(j)) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	F(th, 0, 360 * Z) F(r, 0, 22 * Z) {
		graph[enc(r, th)].push_back(enc(r + 1, th));
		graph[enc(r + 1, th)].push_back(enc(r, th));
		graph[enc(r, th)].push_back(enc(r, (th + 1) % (360 * Z)));
		graph[enc(r, (th + 1) % (360 * Z))].push_back(enc(r, th));
	}
	G(tc) while(tc--) {
		G(n) while(n--) {
			string s; cin >> s;
			G(a) G(b) G(c) a *= Z, b *= Z, c *= Z;
			if(s == "C") while(1) {
				bad[enc(a, b)] = true;
				if(b - c) b = (b + 1) % (360 * Z); else break;
			} else F(r, a, b + 1) bad[enc(r, c)] = true;
		}
		cout << (dfs(0) ? "YES\n" : "NO\n");
		F(th, 0, 360 * Z) F(r, 0, 22 * Z) bad[enc(r, th)] = false;
	}
}