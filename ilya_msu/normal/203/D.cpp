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

int c[30][30];
 void f() {
	 for (int i = 0; i < 30; ++i)
		 for (int j = 0; j < 30; ++j)
			 c[i][j] = 0;
	 c[0][0] = 1;
	 for (int i = 1; i < 30; ++i) {
		 c[i][0] = c[i][i] = 1;
		 for (int j = 1; j < i; ++j)
			 c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	 }
 }



int main() {
	//freopen("input.txt", "r", stdin);
	int a, b, m;
	int vx, vy, vz;
	cin >> a >> b >> m;
	cin >> vx >> vy >> vz;
	double t = (double)(m) / (-vy);
	double x = (double)(a) / 2.0 + t * vx;
	double z = t * vz;
	while (x < 0)
		x += 2 * a;
	while (x > 2 * a)
		x -= 2 * a;
	while (z < 0)
		z += 2 * b;
	while (z > 2 * b)
		z -= 2 * b;
	if (x > a)
		x = 2 * a - x;
	if (z > b)
		z = 2 * b - z;
	printf("%0.12f %0.12f\n", x, z);
	return 0;

}