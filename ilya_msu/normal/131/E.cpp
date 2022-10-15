#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;

struct ferz {
	int x, y, n;
	ferz() {
		x = y = n = 0;
	}
};


bool sort1(ferz a, ferz b) {
	return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
}

bool sort2(ferz a, ferz b) {
	return (a.y < b.y) || ((a.y == b.y) && (a.x < b.x));
}

bool sort3(ferz a, ferz b) {
	return (a.x + a.y < b.x + b.y) || ((a.x + a.y == b.x + b.y) && (a.y < b.y));
}

bool sort4(ferz a, ferz b) {
	return (-a.x + a.y < -b.x + b.y) || ((-a.x + a.y == -b.x + b.y) && (a.y < b.y));
}


int main() {
        int n, m;
		cin >> n >> m;
		vector<ferz> data(m);
		for (int i = 0; i < m; ++i) {
			ferz f;
			cin >> f.x >> f.y;
			data[i] = f;
		}
		sort(data.begin(), data.end(), sort1);
		for (int i = 1; i < m; ++i) {
			if (data[i].x == data[i - 1].x) {
				++data[i].n;
				++data[i - 1].n;
			}
		}
		sort(data.begin(), data.end(), sort2);
		for (int i = 1; i < m; ++i) {
			if (data[i].y == data[i - 1].y) {
				++data[i].n;
				++data[i - 1].n;
			}
		}
		sort(data.begin(), data.end(), sort3);
		for (int i = 1; i < m; ++i) {
			if (data[i].x + data[i].y == data[i - 1].x + data[i - 1].y) {
				++data[i].n;
				++data[i - 1].n;
			}
		}
		sort(data.begin(), data.end(), sort4);
		for (int i = 1; i < m; ++i) {
			if (data[i].y - data[i].x == data[i - 1].y - data[i - 1].x) {
				++data[i].n;
				++data[i - 1].n;
			}
		}
		vector<int> answer(9, 0);
		for (int i = 0; i < m; ++i)
			++answer[data[i].n];
		for (int i = 0; i < 9; ++i)
			cout << answer[i] << " ";
		cout << endl;
        return 0;
}