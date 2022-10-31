// Hydro submission #62c6cdd48672efa577c0160a@1657195988840
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int N = 501;

vector<set<int>> g;
vector<int> used;
set<int> cant;
vector<int> del, comp;
queue<int> q;
int n, t = 0;

void dfs(int v){
	comp[v] = t;
	q.pop();
	set<int> now;
	for(auto i : g[v]){
		if(cant.find(i) != cant.end()){
			now.insert(i);
		}
	}

	for(auto i : now){
		cant.erase(i);
	}

	for(auto i : cant){
		used[i] = 1;
		q.push(i);
	}

	cant.clear();
	for(auto i : now){
		cant.insert(i);
	}


	// for(auto i : cant){
	// 	cout << i + 1 << " ";
	// }
	// cout << " !\n";

	if(!q.empty()){
		dfs(q.front());
	}
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	// freopen("moocast.in", "r", stdin);
    // freopen("moocast.out", "w", stdout);
	
	int m;
	cin >> n >> m;

	used.resize(n);
	g.resize(n);
	del.resize(n);
	comp.resize(n);

	for(int i = 0; i < n; ++i){
		cant.insert(i);
	}

	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].insert(y);
		g[y].insert(x);
	}
	
	int cou = 0;
	for(int i = 0; i < n; ++i){
		if(!used[i]){
			used[i] = 1;
			q.push(i);
			cant.erase(i);
			dfs(i);
			cou++;
			t++;
		}
	}
	map<int, int> ans;
	for(int i = 0; i < n; ++i){
		ans[comp[i]]++;
	}

	multiset<int> an;

	for(auto i : ans){
		an.insert(i.second);
	}
	cout << cou << endl;
	for(auto i : an){
		cout << i << " ";
	}
}