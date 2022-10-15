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

typedef long long ll; 
typedef pair<ll, ll> pll;
const long double PI = 3.14159265358979323846;  

int getMax(const vector<int>& data, int lb) {
	int i = 0;
	if (data.size() == 0)
		return 0;
	while ((i < data.size() - 1) && (data[i] < data[i + 1]))
		++i;
	int j = 0;
	int lastMax = i;
	++i;
	int res = i;
	if (i == data.size())
		return i;
	while (i < data.size() - 1) {
		while ((j <= lastMax) && (data[j] < data[i]))
			++j;
		res = max(res, i - j + 1);
		if (data[i] < data[i + 1])
			++i;
		else {
			j = lastMax + 1;
			lastMax = i;
			++i;
		}
	}
	while ((j <= lastMax) && (data[j] < data[i]))
			++j;
	res = max(res, i - j + 1);
	return res;
}


int main() {
	//freopen("input.txt", "r", stdin);
	int la, lb;
	scanf("%d %d", &la, &lb);
	vector<int> a(la), b(lb);
	for (int i = 0; i < la; ++i)
		scanf("%d", &a[i]);
	vector<int> ind(10000001, -1);
	for (int i = 0; i < lb; ++i) {
		scanf("%d", &b[i]);
		ind[b[i]] = i;
	}
	vector<int> num(la);
	for (int i = 0; i < la; ++i) {
		num[i] = ind[a[i]];
	}
	num.insert(num.end(), num.begin(), num.end());
	int begin = 0;
	int ans = 0;
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] == -1) {
			vector<int> arg(num.begin() + begin, num.begin() + i);
			ans = max(ans, getMax(arg, lb));
			begin = i + 1;
		}
	}
	vector<int> arg(num.begin() + begin, num.end());
	ans = max(ans, getMax(arg, lb));
	cout << min(min(ans, la), lb) << endl;
	return 0;
}