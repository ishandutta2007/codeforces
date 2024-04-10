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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q, ignored = 0;

	bool overtake = true;
	int no_overtake_unignored = 0;

	int speed = 0;
	cin >> q;

	// koliko znakova je vidjeno do nekog trenutka
	vector<int> znak(q+1, 0);
	vector<int> ignore_z(q+2, 0);
	vector<int> seen(301, 0);

	for (int vreme=1; vreme<=q; vreme++) {
		int t;
		cin >> t;
		if (t == 1) {
			cin >> speed;
			
			int rm = 0;
			for (int s=speed; s<=300; s++) {
				rm = max(rm, seen[s]);
			}

			ignore_z[rm+1]++;
			ignore_z[vreme+1]--;

		} else if (t == 2) {
			if (!overtake) {
				ignored += no_overtake_unignored;
				no_overtake_unignored = 0;
			}
		} else if (t == 3) {
			int sl;
			cin >> sl;
			znak[vreme] = 1;

			seen[sl] = vreme;

			if (speed > sl) {
				ignore_z[vreme]++;
				ignore_z[vreme+1]--;
			}
			
		} else if (t == 4) {
			overtake = true;
			no_overtake_unignored = 0;
		} else if (t == 5) {
			// volimo ovaj znak, videli smo ga, brisemo ostale iz secanja
			seen[300] = vreme;
		} else if (t == 6) {
			overtake = false;
			no_overtake_unignored++;
		}
	}

	cerr << ignored << '\n';

	int igg = 0;
	for (int i=1; i<=q; i++) {
		igg += ignore_z[i];
		if (igg > 0 && znak[i]) {
			ignored++;
		}
	}

	cout << ignored;
}