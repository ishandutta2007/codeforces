#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<queue>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::queue;

struct vertex {
	int station, prev, depth;
	vertex(int s, int p, int d) {
		station = s;
		prev = p;
		depth = d;
	}
};



int main() {
	int n;
	cin >> n;
	vector<vector<bool> > edges(n, vector<bool> (n, false));
	for (int i = 0; i < n; ++i) {
		int first, second;
		cin >> first >> second;
		edges[first - 1][second - 1] = edges[second - 1][first - 1] = true;
	}

	queue<int> traversal;
	vector<vertex> data(n, vertex(0, -1, n + 5));
	for (int i = 0; i < n; ++i)
		data[i].station = i;

	data[0].prev = -1;
	data[0].depth = 0;
	traversal.push(0);
	//vector<bool> used(n, false);
	int first, second;
	
	while (!traversal.empty()) {
		int v = traversal.front();
		traversal.pop();
		for (int i = 0; i < n; ++i) {
			if (edges[data[v].station][i]) {
				if (data[i].depth == n + 5) {
					data[i].depth = data[v].depth + 1;
					data[i].prev = data[v].station;
					traversal.push(i);
				}
				else {
					if (data[i].station != data[v].prev) {
						first = i;
						second = data[v].station;
						while (!traversal.empty())
							traversal.pop();
						break;
					}
				}
			}
		}
	}
	vector<int> cycle;
	//cycle.push_back(first);
	//cycle.push_back(second);

	while (second != first) {
		if (data[second].depth > data[first].depth) {
			cycle.push_back(second);
			second = data[second].prev;
		}
		else {
			cycle.push_back(first);
			first = data[first].prev;
		}
	}
	cycle.push_back(first);
	for (int i = 0; i < n; ++i)
		data[i].depth = n + 5;
	for (int i = 0; i < cycle.size(); ++i) {
		data[cycle[i]].depth = 0;
		traversal.push(cycle[i]);
	}
	while (!traversal.empty()) {
		int v = traversal.front();
		traversal.pop();
		for (int i = 0; i < n; ++i) {
			if (edges[data[v].station][i]) {
				if (data[i].depth == n + 5) {
					data[i].depth = data[v].depth + 1;
					data[i].prev = data[v].station;
					traversal.push(i);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
		cout << data[i].depth << " ";
	cout << endl;
	
	return 0;
}