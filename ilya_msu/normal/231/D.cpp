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
const double eps = 1e-12;
const int INF = 1000 * 1000 + 100;
//const int mod = 1000 * 1000 * 1000 + 7;

 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, y, z;
	int x1, y1, z1;
	vector<int> a(6);
	cin >> x >> y >> z;
	cin >> x1 >> y1 >> z1;
	for (int i = 0; i < 6; ++i)
		cin >> a[i];
	int res = 0;
	if (y < 0)
		res += a[0];
	if (y > y1)
		res += a[1];
	if (z < 0)
		res += a[2];
	if (z > z1)
		res += a[3];
	if (x < 0)
		res += a[4];
	if (x > x1)
		res += a[5];
	cout << res << endl;

	return 0;
}