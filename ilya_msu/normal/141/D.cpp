#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>


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
	int ID;
	int coord;
	int dist;
	int prev;
	vector<arc> arcs;
	vertex(int n, int m) {
		ID = n;
		coord = m;
		dist = 1000000001;
		prev = -1;
	}
};

bool operator<(const vertex& a, const vertex& b) {
	return a.dist > b.dist;
}


bool comp(const vertex& a, const vertex& b) {
	return (a.coord < b.coord) || ((a.coord == b.coord) && (a.ID < b.ID));
}

bool comp2(const vertex& a, const vertex& b) {
	return (a.ID < b.ID);
}

int main() {
	int n, L;
	vector<vertex> data;
	cin >> n >> L;
	vertex start(0, 0), end(2 * n + 1, L);
	start.dist = 0;
	data.push_back(start);
	for (int i = 0; i < n; ++i) {
		int x, d, t, p;
		scanf("%d%d%d%d", &x, &d, &t, &p);
		vertex st(2 * i + 1, x - p), en(2 * i + 2, x + d);
		arc a(2 * i + 2, t + p);
		if (x - p < 0)
			a.cost = L + 1;
		st.arcs.push_back(a);
		data.push_back(st);
		data.push_back(en);
	}
	data.push_back(end);
	sort(data.begin(), data.end(), comp);
	for (int i = 0; i < data.size(); ++i) {
		if (i != data.size() - 1)
			data[i].arcs.push_back(arc(data[i + 1].ID, data[i + 1].coord - data[i].coord));
		if (i)
			data[i].arcs.push_back(arc(data[i - 1].ID, data[i].coord - data[i - 1].coord));
	}
	sort(data.begin(), data.end(), comp2);
	priority_queue<vertex> deikstra;
	deikstra.push(data[0]);
	vector<bool> used(data.size(), false);
	while (!used[2 * n + 1]) {
		vertex mini = deikstra.top();
		deikstra.pop();
		if (!used[mini.ID]) {
			for (int i = 0; i < mini.arcs.size(); ++i) {
				if (data[mini.arcs[i].end].dist > mini.arcs[i].cost + mini.dist) {
					data[mini.arcs[i].end].dist = mini.arcs[i].cost + mini.dist;
					data[mini.arcs[i].end].prev = mini.ID;
				}
				if (!used[mini.arcs[i].end])
					deikstra.push(data[mini.arcs[i].end]);
			}
			used[mini.ID] = true;
		}
	}
	cout << data[2 * n + 1].dist << endl;
	vector<int> tram;
	vector<int> way;
	int index = 2 * n + 1;
	way.push_back(index);
	while (data[index].prev != -1) {
		index = data[index].prev;
		way.push_back(index);
	}
	for (int i = 1; i < way.size(); ++i) {
		if ((way[i - 1] == way[i] + 1) && (way[i - 1] % 2 == 0) && (data[way[i - 1]].dist - data[way[i - 1]].coord != data[way[i]].dist - data[way[i]].coord)) {
			tram.push_back(way[i - 1] / 2);
		}
	}
	cout << tram.size() << endl;
	reverse(tram.begin(), tram.end());
	for (int i = 0; i < tram.size(); ++i)
		printf("%d ", tram[i]);
	cout << endl;
}