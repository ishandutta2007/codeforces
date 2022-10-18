#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto& i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
using ll = long long;
using PII = std::pair<int, int>;
using VI = std::vector<int>;

int n, m, s;
std::vector<VI> g;
VI par;
VI col;

void fail(){
	std::cout << "Impossible\n";
	std::exit(0);
}

VI wez(int v){
	VI ret;
	do{
		ret.push_back(v);
		v = par[v];
	}while(v != -1);
	std::reverse(ret.begin(), ret.end());
	return ret;
}

void ans(VI a, VI b){
	std::cout << "Possible\n";
	std::cout << SZ(a) << "\n";
	TRAV(i, a) std::cout << i+1 << " ";
	std::cout << "\n";
	std::cout << SZ(b) << "\n";
	TRAV(i, b) std::cout << i+1 << " ";
	std::cout << "\n";
	std::exit(0);
}

void dfs(int v){
	TRAV(ch, g[v]){
		if(col[ch] == -1){
			col[ch] = col[v];
			par[ch] = v;
			dfs(ch);
		}else if(col[ch] != col[v]){
			VI fs = wez(ch);
			VI sc = wez(v);
			sc.push_back(ch);
			ans(fs, sc);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m >> s;
	s--;
	g.resize(n);
	par.resize(n, -1);
	col.resize(n, -1);
	VI starts;
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(a == s){
			starts.push_back(b);
		}else if(b == s){
			
		}else{
			g[a].push_back(b);
		}
	}

	if(SZ(starts) < 2){
		fail();
		return 0;
	}

	TRAV(st, starts){
		col[st] = st;
		par[st] = s;
	}

	TRAV(st, starts){
		dfs(st);
	}

	fail();

	return 0;
}