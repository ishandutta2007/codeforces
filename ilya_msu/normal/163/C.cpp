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



int main() {
	int n, l, v1, v2;
	cin >> n >> l >> v1 >> v2;
	long double time = (long double)(l) / (v1 + v2);
	long double s = time * v2;
	vector<int> conf(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &conf[i]);
	vector<long double> prConf(n);
	for (int i = 0; i < n; ++i) {
		prConf[i] = conf[i] - s;
		if (prConf[i] < 0)
			prConf[i] += 2 * l;
	}
	sort(prConf.begin(), prConf.end());
	int i1, i2;
	i1 = i2 = 0;
	vector<long double> data(n + 1);
	long double pos = 0;
	int num = 0;
	int i3 = 0;
	while((i3 < n) && (conf[i3] < s )) {
		++num;
		++i3;
	}
	while((i1 < n) || (i2 < n)) {
		if ((i1 < n) && ((i2 == n) || (conf[i1] <= prConf[i2]))) {
			data[num] += conf[i1] - pos;
			pos = conf[i1];
			++i1;
			--num;
		}
		else {
			data[num] += prConf[i2] - pos;
			pos = prConf[i2];
			++i2;
			++num;
		}
	}
	data[num] += 2 * l - pos;
	for (int i = 0; i < data.size(); ++i)
		printf("%0.10f\n", data[i] / (2 * l));
	return 0;
}