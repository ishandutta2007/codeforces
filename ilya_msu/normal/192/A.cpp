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
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  



int main() {
	int n;
	cin >> n;
	int k = 1;
	int x = 1;
	vector<int> data1, data2;
	//vector<bool> a(n + 1, false);
	while (x < n) {
		data1.push_back(x);
		data2.push_back(n - x);
		++k;
		x = k * (k + 1) / 2;
	}
	for (int i = 0; i < data2.size(); ++i)
		data1.push_back(data2[i]);
	sort(data1.begin(), data1.end());
	for (int i = 1; i < data1.size(); ++i)
		if (data1[i - 1] == data1[i]) {
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;	
	return 0;
}