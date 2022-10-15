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
#include<ctime>
 
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
using std::clock;
 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
//const int INF = 1000 * 1000 + 100;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n;
	vector<int> first(n);
	for (int i = 0; i < n; ++i)
		cin >> first[i];
	cin >> m;
	vector<int> second(m);
	for (int i = 0; i < m; ++i)
		cin >> second[i];
	vector<int> data(m + n);
	vector<int> per;
	int i = n - 1, j = m - 1, ind = 0;
	int x = 0;
	while(ind < m + n) {
		while((j >= 0) && (second[j] == x)) {
			data[ind] = j + n + 1;
			--j;
			++ind;
		}
		while((i >= 0) && (first[i] == x)) {
			data[ind] = i + 1;
			--i;
			++ind;
		}
		if (ind < m + n)
			per.push_back(m + n - ind);
		x = 1 - x;
	}
	reverse(data.begin(), data.end());
	for (int i = 0; i < n + m; ++i) {
		cout << data[i] << " ";
	}
	cout << endl;
	cout << per.size() << endl;
	reverse(per.begin(), per.end());
	for (int i = 0; i < per.size(); ++i)
		cout << per[i] << " ";
	cout << endl;
	
	return 0;
}