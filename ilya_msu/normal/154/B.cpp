#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>

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

typedef long long ll; 


int main() {
	int m, n;
	cin >> n >> m;
	vector<vector<int> > data(n + 1);
	vector<int> num(100001, -1);
	int numer = 0;
	for (int i = 2; i < n + 1; ++i) {
		if (data[i].size() == 0) {
			num[i] = numer;
			++numer;
			data[i].push_back(i);
			int j = 2 * i;
			while (j < n + 1) {
				data[j].push_back(i);
				j += i;
			}
		}
	}
	vector<bool> col(n, false);
	vector<int> pr(numer, -1);
	//vector<int> prnumer(numer, 0);
	char c;
	int x;
	//cin >> c;
	for (int i = 0; i < m; ++i) {
		scanf("%c", &c);
		scanf("%c %d", &c, &x);
		if (c == '+') {
			if (col[x - 1])
				printf("Already on\n");
			else {
				int j;
				for (j = 0; j < data[x].size(); ++j) {
					if (pr[num[data[x][j]]] != -1) {
						printf("Conflict with %d\n", pr[num[data[x][j]]]);
						break;
					}
				}
				if (j == data[x].size()) {
					for (j = 0; j < data[x].size(); ++j) {
						pr[num[data[x][j]]] = x;
					}
					col[x - 1] = true;
					printf("Success\n");
				}
			}
		}
		else {
			if (!col[x - 1]) {
				printf("Already off\n");
			}
			else {
				for (int j = 0; j < data[x].size(); ++j) {
						pr[num[data[x][j]]] = -1;
				}
				printf("Success\n");
				col[x - 1] = false;
			}
		}
	}
	return 0;	
}