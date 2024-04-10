#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>


//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"


vector<pair<int, int>> now;
vector<vector<int>> kek;
vector<int> pr;

void init() {
	now.clear();
	kek.clear();
	pr.clear();
}

vector<pair<int, int>> now1;
void gen(int ind) {
	if (ind == pr.size()) {
		int calc = 1;
		int sum = 0;
		for (int i = 0; i < now1.size(); i++) {
			for (int j = 0; j < now1[i].second; j++) {
				calc *= pr[now1[i].first];
				sum++;
			}
		}
		if (now1.size() == 0) {
			return;
		}
		if (now1.size() == 1) {
			if (now1[0].second > 1) {
				kek[now1[0].first].push_back(calc);
			}
			return;
		}
		if (now1.size() == 2 && sum == 2) {
			if ((now1[1].first - now1[0].first) != 1 && (now1[1].first - now1[0].first) != pr.size() - 1) {
				kek[now1[0].first].push_back(calc);
			}
			return;
		}
        kek[now1[0].first].push_back(calc);
 	} else {
 		for (int i = 0; i <= now[ind].second; i++) {
 			if (i == 0) {
 				gen(ind + 1);
 			}
 			if (i == 1) {
 				now1.push_back(make_pair(ind, i));
 				gen(ind + 1);
 			}
 			if (i > 1) {
 				now1.pop_back();
 				now1.push_back(make_pair(ind, i));
 				gen(ind + 1);
 			}

 		}
 		now1.pop_back();
	}
}
void solve() {
    init();
	int n;
	cin >> n;
	int k = n;
	int lol = 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			pr.push_back(i);
			int cnt = 0;
			lol++;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			now.push_back(make_pair(i, cnt));
		}
	}
	if (n != 1) {
		lol++;
		pr.push_back(n);
		now.push_back(make_pair(n, 1));
	}
	if (lol == 1) {
        int calc = 1;
        for (int i = 0; i < now[0].second; i++) {
            calc *= now[0].first;
            cout << calc << " ";
        }
		cout << endl << 0 << endl;
		return;
	}
	if (lol == 2) {

	}
	kek.resize(pr.size());
	gen(0);
	for (int i = 0; i < pr.size(); i++) {
		int j = (i + 1) % pr.size();
		int val = pr[i] * pr[j];
		if (i == 0 && now.size() == 2) {
            continue;
		}
		kek[i].push_back(val);
	}
	for (int i = 0; i < pr.size(); i++) {
		cout << pr[i] << " ";
		for (auto u: kek[i]) {
			cout << u << " ";
		}
		//cout << endl;
	}
	cout << endl;
    if (kek[0].size() == 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}