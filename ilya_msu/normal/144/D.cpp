#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>

using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;

struct arc {
	int end, cost;
	arc(int a, int b) {
		end = a;
		cost = b;
	}
};

struct vertex {
	vector<arc> arcs;
	int dist;
	int ID;
	vertex(int a) {
		ID = a;
		dist = 1000000001;
	}
	vertex() {
		ID = 0;
		dist = 1000000001;
	}
};

bool operator<(const vertex& a, const vertex& b) {
	return a.dist > b.dist;
}


int main() {
	int n, m, s;
	cin >> n >> m >> s;
	--s;
	vector<vertex> data(n); 
	for (int i = 0; i < n; ++i) {
		vertex v(i);
		data[i] = v;
	}
	int first, second, cost;
	for (int i = 0; i < m; ++i) {
		cin >> first >> second >> cost;
		--first;
		--second;
		data[first].arcs.push_back(arc (second, cost));
		data[second].arcs.push_back(arc (first, cost));
	}
	int l;
	cin >> l;
	priority_queue<vertex> deikstra;
	data[s].dist = 0;
	deikstra.push(data[s]);
	vector<bool> used(n, false);
	int u = 0;
	while (u < n) {
		vertex v = deikstra.top();
		deikstra.pop();
		if (!used[v.ID]) {
		for (int i = 0; i < v.arcs.size(); ++i) {
			if (data[v.arcs[i].end].dist > v.dist + v.arcs[i].cost) {
				data[v.arcs[i].end].dist = v.dist + v.arcs[i].cost;
				deikstra.push(data[v.arcs[i].end]);
			}
		}
		used[v.ID] = true;
		++u;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (data[i].dist == l)
			++ans;
		for (int j = 0; j < data[i].arcs.size(); ++j) {
			if (data[i].arcs[j].end < i)
				continue;
			if ((l > data[i].dist) && (l < data[i].dist + data[i].arcs[j].cost) && 
				(data[data[i].arcs[j].end].dist + data[i].arcs[j].cost - l + data[i].dist > l))
				++ans;
			if ((l > data[data[i].arcs[j].end].dist) && (l < data[data[i].arcs[j].end].dist + data[i].arcs[j].cost) && 
				(data[i].dist + data[i].arcs[j].cost - l + data[data[i].arcs[j].end].dist > l))
				++ans;
			if ((l > data[i].dist) && (l < data[i].dist + data[i].arcs[j].cost) && 
				(data[data[i].arcs[j].end].dist + data[i].arcs[j].cost - l + data[i].dist == l))
				++ans;
		}
	}
	cout << ans << endl;
	return 0;	
}