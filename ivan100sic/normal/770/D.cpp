#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;


string p[105];

int nesting(string s) {
	int mx = 0, curr = 0;
	for (char x : s) {
		if (x == '[') {
			curr++;
		} else {
			curr--;
		}
		mx = max(mx, curr);
	}
	return mx;
}

int ymax;

void canvas_draw(char x, int row, int col, int ht) {
	if (x == '[') {
		p[row][col] = '+';
		p[row][col+1] = '-';
		p[row+ht-1][col] = '+';
		p[row+ht-1][col+1] = '-';
		for (int i=row+1; i<row+ht-1; i++) {
			p[i][col] = '|';
		}
	} else {
		p[row][col+1] = '+';
		p[row][col] = '-';
		p[row+ht-1][col+1] = '+';
		p[row+ht-1][col] = '-';
		for (int i=row+1; i<row+ht-1; i++) {
			p[i][col+1] = '|';
		}
	}
	ymax = max(ymax, col+1);
}

void draw(int ht, string s) {
	for (int i=0; i<105; i++) {
		p[i] = string(1005, ' ');
	}
	int m = 0, row = -1, col = -1;
	char prev = '[';
	for (char x : s) {

		if (x == '[') {
			if (prev == '[') {
				row++;
				col++;
				ht -= 2;
			} else {
				col += 2;
			}
		} else {
			if (prev == '[') {
				col += 3;
			} else {
				col++;
				row--;
				ht += 2;
			}
		}

		canvas_draw(x, row, col, ht);

		prev = x;
	}
}

void print(int ht) {
	for (int i=0; i<ht; i++) {
		cout << p[i].substr(0, ymax+1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	int nest = nesting(s);
	draw(2*nest+3, s);
	print(2*nest+1);


}