#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define F(i, l, r) for(ll i = l; i < (r); i++)
#define G(x) ll x; cin >> x;
#define N 300010

vector<ll> gr[N], dir[N];
char val1[N], val2[N];
vector<ll> uids, fringe;
map<pl, vector<ll>> idx;
bool seen[N], fseen[N];
ll seen_size = 0;

void finsert(ll x) {
	if (fseen[x]) return;
	fseen[x]=1;
	fringe.push_back(x);
}

void freset() {
	for (auto x:fringe) fseen[x]=0;
	fringe.clear();
}

void ddfs(ll i) {
	seen[i] = true;
	seen_size++;
	finsert(i);
	for(ll v : dir[i]) if(!seen[v]) ddfs(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	G(n) G(m) G(s)
	ll udir = 0;
	F(i, 0, m) {	
		G(t) G(u) G(v)
		if(t == 1) dir[u].push_back(v);
		else {
			uids.push_back(i);
			if(idx[{u, v}].empty() && idx[{v, u}].empty())
				gr[u].push_back(v), gr[v].push_back(u);
			idx[{u, v}].push_back(i);
		}
	}
	finsert(s);
	ll bigans = -1, smallans = -1;
	fill_n(val1, N, '+');
	fill_n(val2, N, '+');
	while(1) {
			vector<ll> ofr = fringe;	
			for(ll x : ofr) if (!seen[x]) ddfs(x);
			if(smallans == -1) smallans = seen_size;
			bigans = seen_size;
			vector<ll> newf;
			for(ll x : fringe) 
				for(ll v : gr[x]) if(!seen[v]) {
					if (idx.count({x, v})) for(ll id : idx[{x, v}]) { val1[id] = '+'; val2[id] = '-'; }
					if (idx.count({v, x})) for(ll id : idx[{v, x}]) { val1[id] = '-'; val2[id] = '+'; }				
					newf.push_back(v);
				}
			freset();
			for (auto x:newf) finsert(x);
			if(!fringe.size()) break;
	}
	cout << bigans << '\n';
	for(ll i : uids) cout << val1[i];
	cout << '\n' << smallans << '\n';
	for(ll i : uids) cout << val2[i];
	cout << '\n';
}