#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>

using std::pair;
using std::stringstream;
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
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;

typedef long long ll; 
typedef pair<ll, ll> pll;
const long double PI = 3.14159265358979323846;  

vector<int> color;
vector<vector<pair<int, int> > > gr;
vector<int> p;
vector<int> cond;

bool dfs (int v) {
	color[v] = 1;
	for (size_t i=0; i<gr[v].size(); ++i) {
		if (cond[i] != i)
			continue;
		int to = gr[v][i].first;
		if (to == p[v])
			continue;
		if (color[to] == 0) {
			p[to] = v;
			if (dfs (to))  return true;
		}
		else if (color[to] == 1) {
			int cycle_end = v;
			
			vector<int> p1;
			p1.push_back(v);
			while(cycle_end != 0) {
				cycle_end = p[cycle_end];
				p1.push_back(cycle_end);
			}

			int cycle_st = to;
			
			int mini = to;
			/*while (cycle_end != cycle_st) {
				mini = min(mini, cycle_end);
				cycle.push_back(cycle_end);
				cycle_end = p[cycle_end];
			}
			cycle.push_back(cycle_st);*/
			vector<int> p2;
			p2.push_back(to);
			while(cycle_st != 0) {
				cycle_st = p[cycle_st];
				p2.push_back(cycle_st);
			}
			int j = 0;
			while ((j < p1.size()) && (j < p2.size()) && (p1[p1.size() - j - 1] == p2[p2.size() - 1 - j])) {
				++j;
			}
			vector<int> cycle;
			
			/*if ((j < p1.size()) && (j < p2.size())) {
				cycle.push_back(p1[p1.size() - j - 1]);
				cycle.push_back(p2[p2.size() - j - 1]);
			}*/
			cycle.push_back(p1[p1.size() - j]);


			for (int i = j; i < p1.size(); ++i) {
				cycle.push_back(p1[p1.size() - i - 1]);
				mini = min(mini, p1[p1.size() - i - 1]);
			}
			for (int i = j; i < p2.size(); ++i) {
				cycle.push_back(p2[p2.size() - i - 1]);
				mini = min(mini, p2[p2.size() - i - 1]);
			}
			for(int i = 0; i < cycle.size(); ++i)
				cond[cycle[i]] = mini;

			return true;
		}
	}
	color[v] = 2;
	return false;
}
vector<int> d;
bool ddfs (int v) {
	color[v] = 1;
	for (size_t i=0; i<gr[v].size(); ++i) {
		if (cond[i] != i)
			continue;
		int to = gr[v][i].first;
		if (to == i)
			continue;
		if (to == p[v])
			continue;
		if (color[to] == 0) {
			
			p[to] = v;
			if (gr[v][i].second == 1)
				d[to] = d[v] + 1;
			else
				d[to] = d[v];
		ddfs(to);
		}
	}
	color[v] = 2;
	return false;
}
int n, s;

bool magic(const vector<int>& data) {
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j)
			sum += data[i * n + j];
		if (sum != s)
			return false;
	}
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j)
			sum += data[j * n + i];
		if (sum != s)
			return false;
	}
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += data[i * n + i];
	if (sum != s)
		return false;
	sum = 0;
	for (int i = 0; i < n; ++i)
		sum += data[i * n - i + n - 1];
	if (sum != s)
		return false;
	sum = 0;
	return true;
}
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n;
	vector<int> data(n * n);
	s = 0;
	for (int i = 0; i < n * n; ++i) {
		cin >> data[i];
		s += data[i];
	}
	s /= n;
	sort(data.begin(), data.end());
	do {
		
		if (magic(data)) {
			
			cout << s << endl;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j)
					cout << data[i * n + j] << " ";
				cout << endl;
			}
			return 0;
		}
		for (int j = 0; j < n - 1; ++j) {
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += data[i + j * n];
		if (sum != s) {
			sort(data.begin() + n * (j + 1), data.end());
			reverse(data.begin() + n * (j + 1), data.end());
			break;
		}
		}
	} while (next_permutation (data.begin(), data.end()));
	return 0;
}