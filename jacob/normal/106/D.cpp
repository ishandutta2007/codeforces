#include <vector>
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<string> ma(n, string(m, '-'));
	for (int i = 0; i < n; i++) {
		scanf("%s", &ma[i][0]);
	}
	int k;
	cin >> k;
	vector< pair<string, int> > dir(k, pair<string, int>(" ", 0));
	for (int i = 0; i < k; i++)
		scanf("%s%d", &dir[i].first[0], &dir[i].second);
	vector< vector<int> > maxN, maxS, maxE, maxW;
	maxN = maxS = maxW = maxE = vector< vector<int> > (n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ma[i][j] == '#') {
				maxN[i][j] = maxW[i][j] = -1;
			} else {
				maxN[i][j] = 1 + maxN[i-1][j];
				maxW[i][j] = 1 + maxW[i][j-1];
			}
		}
	}
	for (int i = n-1; i >= 0; i--) {
		for (int j = m-1; j >= 0; j--) {
			if (ma[i][j] == '#') {
				maxS[i][j] = maxE[i][j] = -1;
			} else {
				maxS[i][j] = 1 + maxS[i+1][j];
				maxE[i][j] = 1 + maxE[i][j+1];
			}
		}
	}
	vector<char> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ma[i][j] == '#' || ma[i][j] == '.')
				continue;
			int cx = i, cy = j;
			bool good = true;
			for (int l = 0; l < k; l++) {
				switch (dir[l].first[0]) {
				case 'N':
					if (dir[l].second > maxN[cx][cy]) {
						good = false;
					} else
						cx -= dir[l].second;
					break;
				case 'S':
					if (dir[l].second > maxS[cx][cy]) {
						good = false;
					} else
						cx += dir[l].second;
					break;
				case 'E':
					if (dir[l].second > maxE[cx][cy]) {
						good = false;
					} else
						cy += dir[l].second;
					break;
				case 'W':
					if (dir[l].second > maxW[cx][cy]) {
						good = false;
					} else
						cy -= dir[l].second;
					break;
				default:
					return 57;
				}
				if (!good) break;
			}
			if (good)
				result.push_back(ma[i][j]);
		}
	}
	sort(result.begin(), result.end());
	if (result.empty())
		cout << "no solution" << endl;
	else
		cout << string(result.begin(), result.end()) << endl;
	return 0;
}