#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9;

typedef long long ll;


int main() {
	int n;
	cin >> n;
	string st;
	cin >> st;
	vector<pair<char, int>> line;
	int cur = 1;
	int g = 0;
	for (int i = 1; i < n; i++) {
		if (st[i] == st[i - 1]) cur++;
		else {
			line.push_back({ st[i - 1], cur });
			if (st[i - 1] == 'G')g++;
			cur = 1;
		}
	}
	line.push_back({ st[n - 1], cur });
	if (st[n - 1] == 'G') g++;
	int maxi = 0;
	int rofl = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i].first == 'S')continue;
		maxi = max(maxi, line[i].second);
		if (i < (int)line.size() - 2) {
			if(line[i + 1].second == 1)	
				rofl = max(rofl, line[i].second + line[i + 2].second);
		}
	}
	if (g > 1) maxi++;
	if (g > 2) rofl++;
	if (g == 0) {
		cout << "0\n";
	}
	else {
		cout << max(maxi, rofl) << endl;
	}
	//system("pause");
	return 0;
}