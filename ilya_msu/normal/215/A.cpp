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



int n, m;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	vector<int> data;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (b[j] % a[i] == 0)
				data.push_back(b[j] / a[i]);
	sort(data.begin(), data.end());
	reverse(data.begin(), data.end());
	if (data.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	int res = 1;
	while((res < data.size()) && (data[res] == data[res - 1]))
		++res;
	cout << res << endl;	
	return 0;
}