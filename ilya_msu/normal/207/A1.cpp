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

const int INF = 1000;


int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int sum = 0;
	vector<vector<int> > data(n);
	int maxi = 0;
	for (int i = 0; i < n; ++i) {
		int k, a, x, y, m, cur = 0;
		cin >> k >> a >> x >> y >> m;
		sum += k;
		data[i].resize(k);
		data[i][0] = a;
		for (int j = 1; j < k; ++j) {
			data[i][j] = ((ll)(data[i][j - 1]) * x + y) % m;
			if (data[i][j] < data[i][j - 1])
				++cur;
		}
		maxi = max(maxi, cur);
	}
	if (sum > 200000) {
		cout << maxi << endl;
		return 0;
	}
	vector<pii> ans(sum);
	int begin = 0, end = 0;
	vector<int> b(n, 0);
	while(end < sum) {
		for (int i = 0; i < n; ++i) {
			if (b[i] == data[i].size())
				continue;
			ans[end] = make_pair(data[i][b[i]], i);
			++end;
			int j = b[i] + 1;
			while ((j < data[i].size()) && (data[i][j] >= data[i][j - 1])) {
				ans[end] = make_pair(data[i][j], i);
				++end;
				++j;
			}
			b[i] = j;
		}
		sort(ans.begin() + begin, ans.begin() + end);
		begin = end;
	}
	cout << maxi << endl;
	for (int i = 0; i < sum; ++i)
		cout << ans[i].first << " " << ans[i].second + 1 << endl;
	return 0;
}