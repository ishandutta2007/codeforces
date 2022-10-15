#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>

using std::sqrt;

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

struct man {
	string name;
	int n;
	int numer;
	int h;
};

bool comp(man a, man b) {
	return a.n < b.n;
}

bool comp2(man a, man b) {
	return a.numer < b.numer;
}

int main() {
	int n;
	cin >> n;
	vector<man> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i].name >> data[i].n;
		data[i].numer = i;
	}

	sort(data.begin(), data.end(), comp);
	vector<int> por;
	for (int i = 0; i < data.size(); ++i) {
		if (data[i].n > i) {
			cout << -1 << endl;
			return 0;
		}
		por.push_back(i);
		int x = por.size() - 1;
		while (x > por.size() - 1 - data[i].n) {
			swap(por[x], por[x - 1]);
			--x;
		}
	}
	for (int i = 0; i < por.size(); ++i) {
		data[por[i]].h = i + 1;
	}
	//sort(data.begin(), data.end(), comp2);
	for (int i = 0; i < data.size(); ++i) {
		cout << data[i].name << " " << data[i].h << endl;
	}
	return 0;
}