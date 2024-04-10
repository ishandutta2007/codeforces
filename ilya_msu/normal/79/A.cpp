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
	//freopen("input.txt", "r", stdin);
	int x, y;
	cin >> x >> y;
	while(true) {
		if (y < 2) {
			cout << "Hanako" << endl;
			return 0;
		}
		if (x >= 2) {
			x -= 2;
			y -= 2;
		}
		else
			if (x == 1) {
				if (y < 12) {
					cout << "Hanako" << endl;
					return 0;
				}
				else {
					x -= 1;
					y -= 12;
				}
			}
			else {
				if (y < 22) {
					cout << "Hanako" << endl;
					return 0;
				}
				else {
					y -= 22;
				}
			}
	if (y >= 22) {
		y -= 22;
	}
	else 
		if (y >= 12) {
			if (x < 1) {
				cout << "Ciel" << endl;
				return 0;
			}
			else {
				x -= 1;
				y -= 12;
			}
		}
		else
			if (y >= 2) {
				if (x < 2) {
					cout << "Ciel" << endl;
					return 0;
				}
				else {
					x -= 2;
					y -= 2;
				}
			}
			else {
				cout << "Ciel" << endl;
				return 0;
			}
	}
 	return 0;
}