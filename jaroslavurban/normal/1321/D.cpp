#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


struct inter{
	vector<inter*> children;
	vector<inter*> parents;
	ll dist, id;
	bool visited;
};


queue<inter*> q;


void bfs(){
	while (!q.empty()){
		inter *intersec = q.front();
		q.pop();
		for (inter *par: intersec->parents){
			if (!par->visited){
				par->visited = true;
				par->dist = intersec->dist + 1;
				q.push(par);				
			}
		}
	}
}


int main(){
	ll n, m, k;
	cin >> n >> m;
	inter * inters = new inter[n+1];
	for (ll i = 1; i < n + 1; ++i) {
		inters[i].visited = false;
		inters[i].id = i;
	}
	for (ll i = 0; i < m; ++i){
		ll u, v;
		cin >>u>>v;
		inters[u].children.push_back(&inters[v]);
		inters[v].parents.push_back(&inters[u]);
	}
	cin >> k;
	vector<inter*> path;
	for (ll i = 0; i < k; ++i){
		ll v;
		cin >> v;
		path.push_back(&inters[v]);
	}

	inters[path[k-1]->id].dist = 0;
	inters[path[k-1]->id].visited = true;
	q.push(&inters[path[k-1]->id]);
	bfs();

	ll max_rec = 0;
	ll min_rec = 0;
	for (ll i = 0; i < k - 1; ++i){
		if (path[i]->dist != path[i+1]->dist + 1)
			min_rec++, max_rec++;
		else{
			ll cnt = 0;
			for (inter *c: path[i]->children)
				if (c->dist + 1 == path[i]->dist)
					cnt++;
			max_rec += (cnt > 1);
		}
	}

	delete [] inters;
	cout << min_rec << " " << max_rec << endl;
}