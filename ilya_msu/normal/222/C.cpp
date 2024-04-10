#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
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
#include<map>

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
using std::map;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const double eps = 1e-12;

const int MAXN = 10000001;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> data1(n), data2(m);
	for (int i = 0; i < n; ++i)
		cin >> data1[i];
	for (int j = 0; j < m; ++j)
		cin >> data2[j];
	vector<int> prime(MAXN);
	vector<int> count1(MAXN);
	vector<vector<int> > p;
	vector<int> pr;
	vector<int> ind(MAXN);
	for (int i = 2; i < MAXN; ++i) {
		if (prime[i] == 0) {
			prime[i] = i;
			ind[i] = pr.size();
			pr.push_back(i);
			for (int j = i + i; j < MAXN; j += i)
				prime[j] = i;
		}
	}
	p.resize(pr.size());
	for (int i = 0; i < n; ++i) {
		int x = data1[i];
		if (x == 1)
			continue;
		while(x != 1) {
			++count1[prime[x]];
			p[ind[prime[x]]].push_back(i);
			x /= prime[x];
		}
	}
	for (int i = 0; i < m; ++i) {
		int x = data2[i];
		if (x == 1)
			continue;
		while(x != 1) {
			if (count1[prime[x]] == 0) 
				x /= prime[x];
			else {
				--count1[prime[x]];
				data2[i] /= prime[x];
				p[ind[prime[x]]].pop_back();
				x /= prime[x];
			}
		}
	}
	vector<int> data(n, 1);
	for (int i = 0; i < p.size(); ++i) {
		for (int j = 0; j < p[i].size(); ++j)
			data[p[i][j]] *= pr[i];
	}	
	cout << n << " " << m << endl;
	for (int i = 0; i < n; ++i)
		cout << data[i] << " ";
	cout << endl;
	for (int i = 0; i < m; ++i)
		cout << data2[i] << " ";
	cout << endl;
	return 0;
}