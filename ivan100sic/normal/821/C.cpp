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

vector<int> sex;
set<int> sor;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, sled = 1, sol=0;
	cin >> n;
	for (int i=1; i<=2*n; i++) {
		string cmd;
		int x;

		cin >> cmd;

		if (cmd == "add") {
			cin >> x;
			sex.push_back(x);
		} else {
			if (sex.size()) {
				if (*sex.rbegin() != sled) {
					// sort
					for (int x : sex) {
						sor.insert(x);
					}
					sex.clear();
					sol++;
					sor.erase(sled++);
				} else {
					sex.pop_back();
					sled++;
				}
			} else {
				// tu je
				sor.erase(sled++);
			}
		}
	}

	cout << sol;
}