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
	int s;
	int a, b, c;
	cin >> s >> a >> b >> c;
	int sum = a + b + c;
	if (sum == 0) {
		printf("%0.10f %0.10f %0.10f\n", 0.0, 0.0, 0.0);
		return 0;
	}
	double x = (double)(s * a) / sum;
	double y = (double)(s * b) / sum;
	double z = (double)(s * c) / sum;
	printf("%0.10f %0.10f %0.10f\n", x, y, z);
	return 0;
}