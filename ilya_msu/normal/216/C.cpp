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

vector<int> used;
vector<vector<int> > en;



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	if ((n == 2) && (m == 2) && (k == 1)) {
		cout << 4 << endl << "1 2 3 4" << endl;
		return 0;
	}
	if (m == n) {
		cout << 2 * k + 1 << endl;
		for (int i = 0; i < k; ++i)
			cout << "1 ";
		cout << n;
		for (int i = 0; i < k - 1; ++i)
			cout << " " << n + 1;
		cout << " " << n + 2 << endl;
		return 0;
	}
	if ((m == n - 1) && (k == 1)) {
		cout << 2 * k + 1 << endl;
		for (int i = 0; i < k; ++i)
			cout << "1 ";
		cout << "2";
		for (int i = 0; i < k; ++i)
			cout << " " << n + 1;
		cout << endl;
		return 0;
	}
	if (m == n - 1) {
		cout << 2 * k << endl;
		for (int i = 0; i < k; ++i)
			cout << "1 ";
		cout << n;
		for (int i = 0; i < k - 1; ++i)
			cout << " " << n + 1;
		cout << endl;
		return 0;
	}
	cout << 2 * k << endl;
	for (int i = 0; i < k; ++i)
		cout << "1 ";
	for (int i = 0; i < k; ++i)
		cout << n << " ";
	cout << endl;
	
	
	return 0;
}