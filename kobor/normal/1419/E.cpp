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

vector<ii> factors;
int gn;

vector<ii> fact(int n){
	vector<ii> ret;
	for(int i = 2; 1ll*i*i <= n; i++){
		int cnt = 0;
		while(n % i == 0){
			n /= i;
			cnt++;
		}
		if(cnt) ret.PB({i, cnt});
	}
	if(n > 1) ret.PB({n, 1});
	return ret;
}

void gen(int kt, int akt, int st = 0){
	if(kt == SZ(factors)){
		if(akt != gn && akt != 1) cout << akt << ' ';
		return;
	}
	FOR(i, 0, factors[kt].Y+1-st){
		gen(kt+1, akt);
		akt *= factors[kt].X;
	}
}

void solve(){
	int n;
	cin >> n;
	gn = n;
	factors = fact(n);
	if(SZ(factors) == 1){
		int akt = 1;
		FOR(i, 0, factors[0].Y){
			akt *= factors[0].X;
			cout << akt << ' ';
		}
		cout << '\n' << 0 << '\n';
		return;
	}
	cout << n << ' ';
	if(SZ(factors) == 2){
		int akt = 1;
		FOR(i, 0, factors[0].Y){
			akt *= factors[0].X;
			cout << akt << ' ';
		}
		if(max(factors[0].Y, factors[1].Y) > 1) cout << factors[0].X*factors[1].X << ' ';
		akt = 1;
		FOR(i, 0, factors[1].Y){
			akt *= factors[1].X;
			int akt2 = akt;
			FOR(j, 0, factors[0].Y){
				if(akt2 != n && akt2 != factors[0].X*factors[1].X) cout << akt2 << ' ';
				akt2 *= factors[0].X;
			}
		}
		cout << '\n' << (max(factors[0].Y, factors[1].Y) == 1) << '\n';
		return;
	}
	FOR(i, 0, SZ(factors)) gen(i, factors[i].X, 1);
	cout << '\n' << 0 << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin>>tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}