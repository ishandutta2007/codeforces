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

double R = 5.0 / sin(PI / 5);

void printCoord(int t) {
	double add = 2.0 * R * cos(PI / 10) * t;
	for (int i = int(t != 0); i < 5; ++i) {
		printf("%0.20f %0.20f\n", add + R * cos((162.0 - i * 72) / 180 * PI), R * sin((162.0 - i * 72) / 180 * PI));
	}
}

void printPath(int i, int n) {
	if (i == n)
		return;
	cout << 4 * i - 1 << " ";
	//if (i < n - 1)
	//	cout << 4 * i + 3 << " ";
	printPath(i + 1, n);
	cout << 4 * i + 3 << " " << 4 * i + 5 << " " << 4 * i + 2 << " " << 4 * i + 4 << " ";
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	cout << 4 * n  + 1 << endl;
	for (int i = 0; i < n; ++i)
		printCoord(i);
	cout << "1 2 3 4 5" << endl;
	for (int i = 1; i < n; ++i) {
		cout << 4 * i - 1;
		for (int j = 1; j < 5; ++j) {
			cout << " " << 4 * i + j + 1;
		}
		cout << endl;
	}
	cout << "1 ";
	printPath(1, n);
	cout << "3 5 2 4 1" << endl;
	return 0;
}