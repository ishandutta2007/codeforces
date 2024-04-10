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

typedef long long ll; 
typedef pair<ll, ll> pll;
const double PI = 3.14159265358979323846;  

struct ans {
	char c;
	int x;
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> plus(n), minus(n);
	int sumMinus = 0;
	char c;
	int x;
	vector<ans> data(n);
	for (int i = 0; i < n; ++i) {
		scanf("\n%c%d", &c, &x);
		--x;
		if (c == '+')
			++plus[x];
		else {
			++minus[x];
			++sumMinus;
		}
		ans cur;
		cur.c = c;
		cur.x = x;
		data[i] = cur;
	}
	vector<bool> guilty(n);
	int guiltyNum = 0;
	for (int i = 0; i < n; ++i) {
		if (sumMinus - minus[i] + plus[i] == m) {
			guilty[i] = true;
			++guiltyNum;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (data[i].c == '+') {
			if (guilty[data[i].x]) {
				if (guiltyNum == 1)
					cout << "Truth" << endl;
				else
					cout << "Not defined" << endl;
			}
			else
				cout << "Lie" << endl;
		}
		else {
			if (guilty[data[i].x]) {
				if (guiltyNum == 1) 
					cout << "Lie" << endl;
				else
					cout << "Not defined" << endl;
			}
			else
				cout << "Truth" << endl;
		}
	}
	return 0;	
}