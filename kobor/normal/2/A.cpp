#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

map<string, int> ile;
vector<pair<string, int>> inp;

void solve(){
	int n;
	cin >> n;
	FOR(i, 0, n){
		string name;
		int pts;
		cin >> name >> pts;
		inp.PB({name, pts});
	}
	for(auto &x: inp){
		ile[x.X] += x.Y;
	}
	int maks = 0;
	set<string> fajniak;
	for(auto &x: ile){
		if(x.Y > maks) fajniak.clear(), maks = x.Y;
		if(x.Y == maks) fajniak.insert(x.X);
	}
	ile.clear();
	for(auto &x: inp){
		ile[x.X] += x.Y;
		if(ile[x.X] >= maks && fajniak.count(x.X)){
			cout << x.X << '\n';
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}