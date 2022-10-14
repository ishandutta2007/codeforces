#include <bits/stdc++.h>

using namespace std;

int rangelen(pair<int, int> a) {
	return (a.second - a.first + 1);
}

int main() {
	int length;
	string cubes;
	cin >> length >> cubes;
	cubes += "S";
	int maxstart = 0, maxend = 0, mx = 0;
	int start = 0, end = 0, value = 0;
	vector<pair<int, int>> ranges;

	for(int i = 0; i <= length; i++) {
		if(cubes[i] == 'G') {
			value++;
			end = i;
		} else {
			if(start != end || cubes[end] == 'G')
				ranges.push_back(make_pair(start, end));
			value = 0;
			start = end = i + 1;
		}

		if(value > mx) {
			maxstart = start;
			maxend = end;
			mx = value;
		}
	}


	int dmax = 0;
	for(size_t i = 0; i < (ranges.size() - 1) && (ranges.size() > 1); i++) {
		if(ranges[i + 1].first - ranges[i].second == 2) {
			if(dmax < (rangelen(ranges[i + 1]) + rangelen(ranges[i]) + (ranges.size() > 2))) {
				dmax = rangelen(ranges[i + 1]) + rangelen(ranges[i]) + (ranges.size() > 2);
			}
		}
	}

	cout << max(mx + (ranges.size() > 1), dmax);

}