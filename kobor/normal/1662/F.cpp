#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
using vi = vector<int>;

#define f first
#define s second
#define all(s) s.begin(), s.end()
#define pb push_back
#define sz(s) (int)s.size()

#define ii pair<int, int>
const int INF = 1e9 + 7;

struct Tree{
	ii tree[1 << 20];

	int T;

	void set_val(int poz, int val){
		poz += T;
		tree[poz] = {val, poz - T};
		poz /= 2;
	
		while(poz){
			tree[poz] = max(tree[poz + poz], tree[poz + poz + 1]);
			poz /= 2;
		}
	}

	ii ask(int pocz, int kon){
		pocz += T - 1;
		kon += T + 1;
	
		ii ret = {-INF, -1};

		while(pocz >> 1 != kon >> 1){
			if(pocz % 2 == 0)
				ret = max(ret, tree[pocz + 1]);
			if(kon % 2 == 1)
				ret = max(ret, tree[kon - 1]);
			pocz >>= 1;
			kon >>= 1;
		}
	
		return ret;
	}
	
	void clear(){
		for(int i = 0; i < T + T; i++)
			tree[i] = {-INF, -1};
	}
};

Tree lewo;
Tree prawo;
int tab[1<<20];

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	
	int T = 1;
	while(n + 2 > T)
		T *= 2;
	
	lewo.T = T;
	prawo.T = T;
	
	lewo.clear();
	prawo.clear();
	
	for(int i = 1; i <= n; i++){
		cin >> tab[i];
		lewo.set_val(i, i + tab[i]);
		prawo.set_val(i, tab[i] - i);
	}
	
	lewo.set_val(a, -INF);
	prawo.set_val(a, -INF);	
	
	queue<ii> kol;
	kol.push(make_pair(a, 0));
	
	while(sz(kol)){
		auto [kto, dist] = kol.front();
		kol.pop();
		
		//cout << "KTO " << kto << endl;
		
		if (kto == b){
			cout << dist << '\n';
			return;
		}
		
		while(kto < n){
			auto [score, poz] = prawo.ask(kto + 1, min(n, kto + tab[kto]));
			if(score == -INF or poz - tab[poz] > kto)
				break;
				
			//cout << "PRAWO " << poz << endl;
			
			kol.push({poz, dist + 1});
			prawo.set_val(poz, -INF);
			lewo.set_val(poz, -INF);
		}
		
		while(kto > 1){
			//cout << "PRZEDZIAL " << max(1, kto - tab[kto]) << ' ' << kto - 1 << endl;
			auto [score, poz] = lewo.ask(max(1, kto - tab[kto]), kto - 1);
			if(score == -INF or poz + tab[poz] < kto)
				break;
			
			//cout << "LEWO " << poz << endl;
			
			kol.push({poz, dist + 1});
			prawo.set_val(poz, -INF);
			lewo.set_val(poz, -INF);
		}
	}
	assert(false);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt) solve();
	return 0;
}