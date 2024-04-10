#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

struct Node;

vector<Node> g;

struct Node {
	string type;
	int subTreeValue = 0;
	int	l, r;
	bool canBeChanged = true;
	Node() {}
	Node(string _type) : type(_type), l(-1), r(-1) {}
	Node(string _type, int _l) : type(_type), l(_l), r(-1) {}
	Node(string _type, int _l, int _r) : type(_type), l(_l), r(_r) {}
	void get_val(){
		if (type == "NOT") {
			subTreeValue = !g[l].subTreeValue;
		}
		else if (type == "AND") {
			subTreeValue = g[l].subTreeValue & g[r].subTreeValue;
		}
		else if (type == "OR") {
			subTreeValue = g[l].subTreeValue | g[r].subTreeValue;
		}
		else if (type == "XOR") {
			subTreeValue = g[l].subTreeValue ^ g[r].subTreeValue;
		}
	}
};

vector<int> ans;

void fill(int v) {
	if (v == -1) return;
	fill(g[v].l); fill(g[v].r);
	g[v].get_val();
	//cout << v + 1 << " " << g[v].subTreeValue << endl;
}

void push(int v) {
	if (v == -1) return;
	if (g[v].type == "IN") ans[v] = true;
	else {
		if (g[v].type == "NOT") {
			push(g[v].l);
		}
		else if (g[v].type == "AND") {
			if (g[g[v].l].subTreeValue && !g[g[v].r].subTreeValue) push(g[v].r);
			else if (!g[g[v].l].subTreeValue && g[g[v].r].subTreeValue) push(g[v].l);
			else if (g[g[v].l].subTreeValue && g[g[v].r].subTreeValue) {
				push(g[v].l);
				push(g[v].r);
			}
		}
		else if (g[v].type == "OR") {
			if (!g[g[v].l].subTreeValue && !g[g[v].r].subTreeValue) {
				push(g[v].l);
				push(g[v].r);
			}
			else if (g[g[v].l].subTreeValue && !g[g[v].r].subTreeValue) push(g[v].l);
			else if (!g[g[v].l].subTreeValue && g[g[v].r].subTreeValue) push(g[v].r);
		}
		else if (g[v].type == "XOR") {
			push(g[v].l);
			push(g[v].r);
		}
	}
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	g.resize(n);
	ans.resize(n);
	string tp;
	int t1, t2;
	vector<char> isleaf(n);
	for (int i = 0; i < n; i++) {
		cin >> tp >> t1;
		if (tp != "IN" && tp != "NOT") {
			cin >> t2; t1--; t2--;
			g[i] = Node(tp, t1, t2);
		}
		else if (tp == "IN") {
			isleaf[i] = true;
			g[i] = Node(tp);
			g[i].subTreeValue = t1; 
		}
		else {
			t1--;
			g[i] = Node(tp, t1);
		}
	}
	fill(0);
	//cout << "kek\n";
	push(0);
	for (int i = 0; i < n; i++) {
		if (!isleaf[i]) continue;
		if (ans[i]) cout << !g[0].subTreeValue;
		else cout << g[0].subTreeValue;
	}
	cout << endl;
	//system("pause");
	return 0;
}