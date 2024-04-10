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
	int h, m;
	scanf("%d:%d", &h, &m);
	while (true) {
		++m;
		if (m == 60) {
			++h;
			m = 0;
		}
		if (h == 24)
			h = 0;
		string time;
		if (h < 10) {
			time += '0';
			time += '0' + h;
		}
		else {
			time += '0' + (h / 10);
			time += '0' + (h % 10);
		}
		if (m < 10) {
			time += '0';
			time += '0' + m;
		}
		else {
			time += '0' + (m / 10);
			time += '0' + (m % 10);
		}
		if ((time[0] == time[3]) && (time[1] == time[2])) {
			cout << time[0] << time[1] << ":" << time[2] << time[3] << endl;
			return 0;
		}
	}	
	return 0;
}