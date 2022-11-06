#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef long long llong;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int n;
string str[100000];
char buf[100005];

set<char> pos;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin.getline(buf, sizeof(buf));
	for (char i = 'a'; i <= 'z'; ++i) pos.insert(i);
	for (int i = 0; i < n; ++i) {
		cin.getline(buf, sizeof(buf));
		str[i] = buf;
	}
	bool success = false;
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (str[i][0] == '!') {
			if (success) ++ans;
			else {
				set<char> tmp;
				for (char j = 'a'; j <= 'z'; ++j) tmp.insert(j);
				for (int j = 2; j < str[i].size(); ++j) tmp.erase(str[i][j]);
				for (char c : tmp) pos.erase(c);
			}
		}
		else if (str[i][0] == '.') {
			if (!success) for (int j = 2; j < str[i].size(); ++j) pos.erase(str[i][j]);
		}
		else {
			if (success) ++ans;
			else pos.erase(str[i][2]);
		}
		if (pos.size() == 1) {
			success = true;
		}
	}
	printf("%d\n", ans);
	return 0;
}