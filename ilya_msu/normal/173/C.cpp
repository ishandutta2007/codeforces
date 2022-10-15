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
	//freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int> > data(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &data[i][j]);
	vector<vector<int> > strSum = data;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (j)
				strSum[i][j] += strSum[i][j - 1];
	vector<vector<int> > stolbSum = data;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (j)
				stolbSum[j][i] += stolbSum[j - 1][i];
	int maximum = -500 * 500 * 1000;
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			int cur = data[i - 1][j - 1] + data[i - 1][j] + data[i - 1][j + 1] + data[i][j + 1] + 
						data[i + 1][j + 1] + data[i + 1][j] + data[i + 1][j - 1];
			maximum = max(maximum, cur);
			int sum = strSum[i - 1][j + 1] + strSum[i][j + 1] + strSum[i + 1][j + 1];
			if (j - 1)
				sum -= (strSum[i - 1][j - 2] + strSum[i][j - 2] + strSum[i + 1][j - 2]);
			int k = 2;
			while ((i >= k) && (j >= k) && (i + k <= n - 1) && (j + k <= m - 1)) {
				sum += strSum[i - k][j + k] - strSum[i - k][j - k];
				sum += strSum[i + k][j + k] - strSum[i + k][j - k];  
				sum += stolbSum[i + k - 1][j + k] - stolbSum[i - k][j + k];
				sum += stolbSum[i + k][j - k];
				if (i - k)
					sum -= stolbSum[i - k - 1][j - k];
				cur = sum - data[i - k + 1][j - k] - cur;
				maximum = max(maximum, cur);
				++k;
			}
		}
	}
	cout << maximum << endl;
	return 0;
}